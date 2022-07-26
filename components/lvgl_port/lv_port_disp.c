#include "lv_port_disp.h"
#include "i80_lcd.h"

#include <esp_log.h>
#include <esp_heap_caps.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>
#include <sdkconfig.h>

#include "lvgl.h"
#include <driver/gpio.h>
#include "lvgl_helpers.h"

#include "ili9488.h"

static const char *TAG = "lv_port_disp";

static void disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    /* 启动新的传输 */
    lcd_draw_rect(disp_drv->user_data, area->x1, area->y1, area->x2, area->y2, color_p);
    /* 通知lvgl传输已完成 */
    lv_disp_flush_ready(disp_drv);
}

void lv_port_disp_init()
{
    /* 申请lvgl渲染缓冲区 */
    lv_color_t *lvgl_draw_buff1 = heap_caps_malloc(LVGL_BUFF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    lv_color_t *lvgl_draw_buff2 = heap_caps_malloc(LVGL_BUFF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    /* 向lvgl注册缓冲区 */
    static lv_disp_draw_buf_t draw_buf_dsc; //需要全程生命周期，设置为静态变量
    lv_disp_draw_buf_init(&draw_buf_dsc, lvgl_draw_buff1, lvgl_draw_buff2, LVGL_BUFF_SIZE);

    /* 创建并初始化用于在lvgl中注册显示设备的结构 */
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv); //使用默认值初始化该结构
    /* 设置屏幕分辨率 */
    disp_drv.hor_res = LCD_X_PIXELS;
    disp_drv.ver_res = LCD_Y_PIXELS;
    /* 初始化LCD总线 */
    static esp_lcd_panel_io_handle_t panel_io;                                                      //需要全程生命周期，设置为静态变量
    panel_io = lcd_i80_bus_io_init(CONFIG_LVGL_LCD_PCLK_FREQ, LVGL_BUFF_SIZE * sizeof(lv_color_t)); //初始化8080并行总线
    /* 将总线句柄放入lv_disp_drv_t中用户自定义段 */
    disp_drv.user_data = panel_io;

   
    gpio_set_direction(BSP_LCD_REST_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(BSP_LCD_REST_PIN, 1); //并口屏的REST脚（1使能）
    gpio_set_direction(BSP_LCD_RD_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(BSP_LCD_RD_PIN, 1); //神奇的引脚，一定要拉高
    Lcd_reset(panel_io); //LCD复位
    /* 初始化寄存器 */
    #if defined(CONFIG_LVGL_LCD_PANEL_W350CE024A_40Z)
        lcd_init_reg(panel_io, panel_st7796s_w350ce024a_40z_reg_table);
    #elif defined(CONFIG_LVGL_LCD_PANEL_CL35BC1017_40A)
        lcd_init_reg(panel_io, panel_st7796s_cl35bc1017_40a_reg_table);
    #elif defined(CONFIG_LVGL_LCD_PANEL_CL35BC106_40A)
        lcd_init_reg(panel_io, panel_ili9488_cl35bc106_40a_reg_table);
    #elif defined(CONFIG_LVGL_LCD_PANEL_P0395H01_SPEC_40A)
        lcd_init_reg(panel_io, panel_ili9488_P0395H01_reg_table);
    #endif

    ESP_LOGI(TAG, "lcd clock: %dMHz, mininal fps: %d", CONFIG_LVGL_LCD_PCLK_FREQ,
             CONFIG_LVGL_LCD_PCLK_FREQ * 1000000 / (LCD_X_PIXELS * LCD_Y_PIXELS));

    /* 设置显示矩形函数，用于将矩形缓冲区刷新到屏幕上 */
    disp_drv.flush_cb = disp_flush;
    /* 设置缓冲区 */
    disp_drv.draw_buf = &draw_buf_dsc;

    // /*软件旋转*/
    // disp_drv.sw_rotate = 1;
    // disp_drv.rotated = LV_DISP_ROT_90;
    /* 注册显示设备 */
    lv_disp_drv_register(&disp_drv);

    /* 开启显示 */
    lcd_disp_switch(panel_io, true);

    // /*触屏初始化*/
    // gpio_set_direction(39, GPIO_MODE_OUTPUT);
    // gpio_set_level(39, 1); //触屏的REC脚(1开启 0关闭)
    // gpio_set_direction(38, GPIO_MODE_INPUT);
    // // gpio_set_level(37, 0); //触屏的INT脚
    // lvgl_driver_init(); //lvgl显示接口初始化
    // /*触屏注册*/
    // static lv_indev_drv_t indev_drv;
    // lv_indev_drv_init(&indev_drv);
    // indev_drv.read_cb = touch_driver_read;
    // indev_drv.type = LV_INDEV_TYPE_POINTER;
    // lv_indev_drv_register(&indev_drv);
    // /*触屏初始化接入lvgl触发中断复位问题是没有spi初始化*/
    // /*屏幕注册和触屏注册一定要放一起*/
}
