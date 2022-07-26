#include "i80_lcd.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <esp_log.h>
#include <esp_err.h>

#include <driver/gpio.h>
#include <driver/ledc.h>

const char *TAG = "bsp_lcd";

static esp_err_t lcd_bl_init();

/**
 * @brief 初始化8080LCD总线
 *
 * @param pclk_mhz 像素时钟，单位为mhz
 * @param transfer_size 单次传输最大数据量，最高为64k
 * @param trans_done_cb 传输完毕后的回调函数，NULL为不使用
 * @return esp_lcd_panel_io_handle_t 显示接口句柄
 */
esp_lcd_panel_io_handle_t lcd_i80_bus_io_init(uint16_t pclk_mhz, size_t transfer_size)
{
    /* 初始化背光 */
    lcd_bl_init();

    /* 初始化8080总线：16位数据，DC与WR脚 */
    esp_lcd_i80_bus_handle_t i80_bus = NULL;
    esp_lcd_i80_bus_config_t bus_config = {
        .dc_gpio_num = BSP_LCD_DC_PIN,
        .wr_gpio_num = BSP_LCD_WR_PIN, //DC与WR引脚
        .data_gpio_nums = BSP_LCD_DATA_PINS,
        .bus_width = 16,                     //总线宽度16位
        .max_transfer_bytes = transfer_size, //缓冲区大小
    };
    esp_lcd_new_i80_bus(&bus_config, &i80_bus);

    /* 初始化LCD面板，使用上述8080总线，并设置CS引脚以及总线频率 */
    esp_lcd_panel_io_handle_t io_handle;
    esp_lcd_panel_io_i80_config_t io_config = {
        .cs_gpio_num = BSP_LCD_CS_PIN, //CS引脚
        .pclk_hz = pclk_mhz * 1000000, //总线时钟频率
        .trans_queue_depth = 1,
        .dc_levels = {
            .dc_idle_level = 1,
            .dc_cmd_level = 0,
            .dc_dummy_level = 1,
            .dc_data_level = 1,
        },
        .lcd_cmd_bits = 8,
        .lcd_param_bits = 8, //指令与指令参数的长度
    };
    esp_lcd_new_panel_io_i80(i80_bus, &io_config, &io_handle);

    return io_handle;
}

void Lcd_reset(const esp_lcd_panel_io_handle_t io)
{
    // perform hardware reset
    if (BSP_LCD_REST_PIN >= 0)
    {
        gpio_set_level(BSP_LCD_REST_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(BSP_LCD_REST_PIN, 0);
        vTaskDelay(pdMS_TO_TICKS(10));
        gpio_set_level(BSP_LCD_REST_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(120));
    }
    else
    {                                  // perform software reset
        vTaskDelay(pdMS_TO_TICKS(20)); // spec, wait at least 5m before sending new command
    }
    ESP_LOGI(TAG, "Lcd_reset ok");
}

void lcd_init_reg(const esp_lcd_panel_io_handle_t io, const lcd_panel_reg_t reg_table[])
{
    uint8_t i = 0;
    while (reg_table[i].len != 0xFF)
    {
        esp_lcd_panel_io_tx_param(io, reg_table[i].reg, reg_table[i].val, reg_table[i].len);
        i++;
    }
}

void lcd_draw_rect(const esp_lcd_panel_io_handle_t io, uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, const void *color_data)
{
    // esp_lcd_panel_io_tx_param(io, 0x11, NULL, 0);
    esp_lcd_panel_io_tx_param(io, 0x2A, (uint8_t[]){(x_start >> 8) & 0xFF, x_start & 0xFF, (x_end >> 8) & 0xFF, x_end & 0xFF}, 4);
    esp_lcd_panel_io_tx_param(io, 0x2B, (uint8_t[]){(y_start >> 8) & 0xFF, y_start & 0xFF, (y_end >> 8) & 0xFF, y_end & 0xFF}, 4);

    size_t len = (x_end - x_start + 1) * (y_end - y_start + 1) * sizeof(uint16_t);
    esp_lcd_panel_io_tx_color(io, 0x2C, color_data, len);
}

void lcd_disp_switch(const esp_lcd_panel_io_handle_t io, bool sw)
{
    if (sw)
    {
        esp_lcd_panel_io_tx_param(io, 0x29, NULL, 0); //开显示
        lcd_bl_set(40);                               //打开背光
        ESP_LOGW(TAG, "display on");
    }
    else
    {
        esp_lcd_panel_io_tx_param(io, 0x28, NULL, 0); //关显示
        lcd_bl_set(0);                                //关闭背光
        ESP_LOGW(TAG, "display off");
    }
}

/* 定时器配置 */
static const ledc_timer_config_t lcd_bl_ledc_timer = {
    .duty_resolution = LEDC_TIMER_10_BIT, //LEDC驱动器占空比精度
    .freq_hz = 2000,                      //PWM频率
    .speed_mode = LEDC_LOW_SPEED_MODE,
    .timer_num = LEDC_TIMER_0, //ledc使用的定时器编号。若需要生成多个频率不同的PWM信号，则需要指定不同的定时器
    .clk_cfg = LEDC_AUTO_CLK,  //自动选择定时器的时钟源
};

/* ledc通道配置 */
static const ledc_channel_config_t lcd_bl_ledc_channel = {
    .channel = LEDC_CHANNEL_0,  //LCD背光使用通道0
    .duty = 0,                  //占空比0
    .gpio_num = BSP_LCD_BL_PIN, //连接背光的IO
    .speed_mode = LEDC_LOW_SPEED_MODE,
    .hpoint = 0,
    .timer_sel = LEDC_TIMER_0, //使用上面初始化过的定时器
};

/**
 * @brief 初始化LCD背光PWM
 *
 * @return esp_err_t 错误代码
 */
static esp_err_t lcd_bl_init()
{
    /* 初始化定时器1，将初始化好的定时器编号传给ledc通道初始化函数即可 */
    esp_err_t error = ledc_timer_config(&lcd_bl_ledc_timer);
    if (error)
    {
        return error;
    }

    /* 初始化ledc通道 */
    return ledc_channel_config(&lcd_bl_ledc_channel);
}

/**
 * @brief 设置背光亮度
 *
 * @param brightness 背光百分比，0-100
 * @return esp_err_t 错误代码
 */
esp_err_t lcd_bl_set(uint8_t brightness)
{
    /* 设定PWM占空比 */
    esp_err_t error = ledc_set_duty(lcd_bl_ledc_channel.speed_mode, lcd_bl_ledc_channel.channel, brightness * 10);
    if (error)
    {
        return error;
    }

    /* 更新PWM占空比输出 */
    return ledc_update_duty(lcd_bl_ledc_channel.speed_mode, lcd_bl_ledc_channel.channel);
}
