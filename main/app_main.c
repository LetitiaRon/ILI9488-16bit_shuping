#include "app_main.h"

static const char *TAG = "Main";

/*MQTT初始化*/
static void log_error_if_nonzero(const char *message, int error_code)
{
    if (error_code != 0)
    {
        ESP_LOGE(TAG, "Last error %s: 0x%x", message, error_code);
    }
}
static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    ESP_LOGD(TAG, "Event dispatched from event loop base=%s, event_id=%d", base, event_id);
    esp_mqtt_event_handle_t event = event_data;
    esp_mqtt_client_handle_t client = event->client;
    int msg_id;
    switch ((esp_mqtt_event_id_t)event_id)
    {
    case MQTT_EVENT_CONNECTED: //mqtt连接事件
        ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
        msg_id = esp_mqtt_client_publish(client, "/topic/qos1", "data_3", 0, 1, 0);
        ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);
        msg_id = esp_mqtt_client_subscribe(client, "/topic/qos0", 0);
        ESP_LOGI(TAG, "sent subscribe successful, msg_id=%d", msg_id);
        msg_id = esp_mqtt_client_subscribe(client, "/topic/qos1", 1);
        ESP_LOGI(TAG, "sent subscribe successful, msg_id=%d", msg_id);
        msg_id = esp_mqtt_client_unsubscribe(client, "/topic/qos1");
        ESP_LOGI(TAG, "sent unsubscribe successful, msg_id=%d", msg_id);
        break;
    case MQTT_EVENT_DISCONNECTED: //mqtt断开事件
        ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
        break;
    case MQTT_EVENT_SUBSCRIBED: //mqtt订阅事件
        ESP_LOGI(TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id);
        msg_id = esp_mqtt_client_publish(client, "/topic/qos0", "data", 0, 0, 0);
        ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);
        break;
    case MQTT_EVENT_UNSUBSCRIBED: //mqtt取消订阅事件
        ESP_LOGI(TAG, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_PUBLISHED: //mqtt发布事件
        ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_DATA: //mqtt接收数据事件
        ESP_LOGI(TAG, "MQTT_EVENT_DATA");
        printf("TOPIC=%.*s\r\n", event->topic_len, event->topic);
        printf("DATA=%.*s\r\n", event->data_len, event->data);
        /*解析数据*/
        // json parse
        root = cJSON_Parse(event->data);
        if (root == NULL)
        {
            // free(data);
            printf("cJSON_Parse fail![%s]\n", cJSON_GetErrorPtr());
            return -1;
        }
        cJSON *items = cJSON_GetObjectItem(root, "items"); //全部数据
        if (items != NULL)
        {
            char *name = cJSON_Print(items); //将JSON结构体打印到字符串中 需要自己释放
            //printf("items:%s\n", name);
            free(name);
        }
        /*解析各个部分数据*/
        /*解析风扇状态*/
        cJSON *Fan_item = cJSON_GetObjectItem(items, "Fan");
        if (Fan_item != NULL)
        {
            char *type = cJSON_Print(Fan_item); //将JSON结构体打印到字符串中 需要自己释放
            //printf("Fan:%s\n", type);
            free(type);
        }
        cJSON *Fan_value = cJSON_GetObjectItem(Fan_item, "value");
        if (Fan_value != NULL)
        {
            char *fanvalue = cJSON_Print(Fan_value); //将JSON结构体打印到字符串中 需要自己释放
            //printf("value:%s\n", fanvalue);
            Fan = atoi(fanvalue); //字符串转换整形
            free(fanvalue);
        }
        /*解析浇水状态*/
        cJSON *watering_item = cJSON_GetObjectItem(items, "Watering");
        if (watering_item != NULL)
        {
            char *type = cJSON_Print(watering_item); //将JSON结构体打印到字符串中 需要自己释放
            //printf("watering:%s\n", type);
            free(type);
        }
        cJSON *watering_value = cJSON_GetObjectItem(watering_item, "value");
        if (watering_value != NULL)
        {
            char *wateringvalue = cJSON_Print(watering_value); //将JSON结构体打印到字符串中 需要自己释放
            //printf("value:%s\n", wateringvalue);
            Watering = atoi(wateringvalue); //字符串转换整形
            free(wateringvalue);
        }
        /*解析温度*/
        cJSON *temperature_item = cJSON_GetObjectItem(items, "temperature");
        if (temperature_item != NULL)
        {
            char *type = cJSON_Print(temperature_item); //将JSON结构体打印到字符串中 需要自己释放
            //printf("watering:%s\n", type);
            free(type);
        }
        cJSON *temperature_value = cJSON_GetObjectItem(temperature_item, "value");
        if (temperature_value != NULL)
        {
            char *temperaturevalue = cJSON_Print(temperature_value); //将JSON结构体打印到字符串中 需要自己释放
            //printf("value:%s\n", wateringvalue);
            temperature = atof(temperaturevalue); //字符串转换成double
            free(temperaturevalue);
        }
        /*解析湿度*/
        cJSON *Humidity_item = cJSON_GetObjectItem(items, "Humidity");
        if (Humidity_item != NULL)
        {
            char *type = cJSON_Print(Humidity_item); //将JSON结构体打印到字符串中 需要自己释放
            //printf("watering:%s\n", type);
            free(type);
        }
        cJSON *Humidity_value = cJSON_GetObjectItem(Humidity_item, "value");
        if (Humidity_value != NULL)
        {
            char *Humidityvalue = cJSON_Print(Humidity_value); //将JSON结构体打印到字符串中 需要自己释放
            //printf("value:%s\n", wateringvalue);
            Humidity = atof(Humidityvalue); //字符串转换成double
            free(Humidityvalue);
        }
        /*解析光照强度*/
        cJSON *LightLux_item = cJSON_GetObjectItem(items, "LightLux");
        if (LightLux_item != NULL)
        {
            char *type = cJSON_Print(LightLux_item); //将JSON结构体打印到字符串中 需要自己释放
            //printf("watering:%s\n", type);
            free(type);
        }
        cJSON *LightLux_value = cJSON_GetObjectItem(LightLux_item, "value");
        if (LightLux_value != NULL)
        {
            char *LightLuxvalue = cJSON_Print(LightLux_value); //将JSON结构体打印到字符串中 需要自己释放
            //printf("value:%s\n", wateringvalue);
            LightLux = atof(LightLuxvalue); //字符串转换成double
            free(LightLuxvalue);
        }
        /*解析CO2含量*/
        cJSON *co2_item = cJSON_GetObjectItem(items, "co2");
        if (co2_item != NULL)
        {
            char *type = cJSON_Print(co2_item); //将JSON结构体打印到字符串中 需要自己释放
            //printf("watering:%s\n", type);
            free(type);
        }
        cJSON *co2_value = cJSON_GetObjectItem(co2_item, "value");
        if (co2_value != NULL)
        {
            char *co2value = cJSON_Print(co2_value); //将JSON结构体打印到字符串中 需要自己释放
            //printf("value:%s\n", wateringvalue);
            co2 = atoi(co2value); //字符串转换整形
            free(co2value);
        }
        /*解析大气压强*/
        cJSON *Atmosphere_item = cJSON_GetObjectItem(items, "Atmosphere");
        if (Atmosphere_item != NULL)
        {
            char *type = cJSON_Print(Atmosphere_item); //将JSON结构体打印到字符串中 需要自己释放
            //printf("watering:%s\n", type);
            free(type);
        }
        cJSON *Atmosphere_value = cJSON_GetObjectItem(Atmosphere_item, "value");
        if (Atmosphere_value != NULL)
        {
            char *Atmospherevalue = cJSON_Print(Atmosphere_value); //将JSON结构体打印到字符串中 需要自己释放
            //printf("value:%s\n", wateringvalue);
            Atmosphere = atof(Atmospherevalue); //字符串转换成double
            free(Atmospherevalue);
        }
        /*删除root*/
        cJSON_Delete(root);
        break;
    case MQTT_EVENT_ERROR: //mqtt错误事件
        ESP_LOGI(TAG, "MQTT_EVENT_ERROR");
        if (event->error_handle->error_type == MQTT_ERROR_TYPE_TCP_TRANSPORT)
        {
            log_error_if_nonzero("reported from esp-tls", event->error_handle->esp_tls_last_esp_err);
            log_error_if_nonzero("reported from tls stack", event->error_handle->esp_tls_stack_err);
            log_error_if_nonzero("captured as transport's socket errno", event->error_handle->esp_transport_sock_errno);
            ESP_LOGI(TAG, "Last errno string (%s)", strerror(event->error_handle->esp_transport_sock_errno));
        }
        break;
    default:
        ESP_LOGI(TAG, "Other event id:%d", event->event_id);
        break;
    }
}
static void mqtt_app_start(void)
{
    esp_mqtt_client_config_t mqtt_cfg = {
        .host = "a1D0VCyeFNT.iot-as-mqtt.cn-shanghai.aliyuncs.com", //CONFIG_BROKER_URL,//根据实际填写
        .port = 1883,
        .username = "Client&a1D0VCyeFNT",                                                              //根据实际填写
        .password = "57e7162d120f2be707c27cd57f8d206a0d83e88a49f649425e3f44b5bc97725c",                //根据实际填写
        .client_id = "a1D0VCyeFNT.Client|securemode=2,signmethod=hmacsha256,timestamp=1655034468007|", //根据实际填写
    };

#if CONFIG_BROKER_URL_FROM_STDIN
    char line[128];
    if (strcmp(mqtt_cfg.uri, "FROM_STDIN") == 0)
    {
        int count = 0;
        printf("Please enter url of mqtt broker\n");
        while (count < 128)
        {
            int c = fgetc(stdin);
            if (c == '\n')
            {
                line[count] = '\0';
                break;
            }
            else if (c > 0 && c < 127)
            {
                line[count] = c;
                ++count;
            }
            vTaskDelay(10 / portTICK_PERIOD_MS);
        }
        mqtt_cfg.uri = line;
        printf("Broker url: %s\n", line);
    }
    else
    {
        ESP_LOGE(TAG, "Configuration mismatch: wrong broker url");
        abort();
    }
#endif /* CONFIG_BROKER_URL_FROM_STDIN */
    //创建客户端
    esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);
    /* The last argument may be used to pass data to the event handler, in this example mqtt_event_handler */
    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, client);
    //启动客户端，连接服务器
    esp_mqtt_client_start(client);
}


/*uart初始化*/
void init(void)
{
    const uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };
    // We won't use a buffer for sending data.
    uart_driver_install(UART_NUM_0, RX_BUF_SIZE * 2, 0, 0, NULL, 0);
    uart_param_config(UART_NUM_0, &uart_config);
    //uart_set_pin(UART_NUM_0, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}
int sendData(const char *logName, const char *data)
{
    const int len = strlen(data);
    const int txBytes = uart_write_bytes(UART_NUM_0, data, len);
    //ESP_LOGI(logName, "Wrote %d bytes", txBytes);
    return txBytes;
}
int sendData_NULL(const char *data)
{
    const int len = strlen(data);
    const int txBytes = uart_write_bytes(UART_NUM_0, data, len);
    return txBytes;
}

/*RTOS任务*/
static void lv_tick_task(void *arg)
{
    (void)arg;
    lv_tick_inc(portTICK_PERIOD_MS);
}
/*GUI任务*/
static void gui_task(void *arg)
{
    xGuiSemaphore = xSemaphoreCreateMutex();
    /*lvgl内核初始化*/
    lv_init();
    /*屏幕初始化*/
    lv_port_disp_init();
    /*设备初始化接入*/
    lv_port_indev_init();
    /*freertos注册*/
    esp_register_freertos_tick_hook(lv_tick_task);

    ui_init();
    // setup_ui();
    // lv_mydemo();
    // lv_demo_widgets();
    // lv_demo_music();
    // lv_demo_benchmark();
    // lv_demo_stress();
    // lv_demo_keypad_encoder();
    while (1)
    {
        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(10));
        /* Try to take the semaphore, call lvgl related function on success */
        if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY))
        {
            lv_timer_handler();
            xSemaphoreGive(xGuiSemaphore);
        }
    }
}
/*NTP和MQTT同时用的时候需把task里面的其中一个网络初始化注释掉*/
static void mqtt_task(void *arg)
{
    ESP_LOGI(TAG, "[APP] Startup..");
    ESP_LOGI(TAG, "[APP] Free memory: %d bytes", esp_get_free_heap_size());
    ESP_LOGI(TAG, "[APP] IDF version: %s", esp_get_idf_version());

    esp_log_level_set("*", ESP_LOG_INFO);
    esp_log_level_set("MQTT_CLIENT", ESP_LOG_VERBOSE);
    esp_log_level_set("MQTT_EXAMPLE", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT_BASE", ESP_LOG_VERBOSE);
    esp_log_level_set("esp-tls", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT", ESP_LOG_VERBOSE);
    esp_log_level_set("OUTBOX", ESP_LOG_VERBOSE);

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    /* This helper function configures Wi-Fi or Ethernet, as selected in menuconfig.
     * Read "Establishing Wi-Fi or Ethernet Connection" section in
     * examples/protocols/README.md for more information about this function.
     */
    ESP_ERROR_CHECK(example_connect());

    mqtt_app_start();
    while (1)
    {

        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
/*获取NTP任务*/
static void Get_NTP_task(void *arg)
{
    time_t now;         //定义一个now 存放unix 时间戳
    struct tm timeinfo; //定义tm时间结构体
                        ////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////
    /*
            int tm_sec;         秒，范围从 0 到 59
            int tm_min;         分，范围从 0 到 59
            int tm_hour;        小时，范围从 0 到 23
            int tm_mday;       一月中的第几天，范围从 1 到 31
            int tm_mon;         月份，范围从 0 到 11
            int tm_year;        注意是自 1900 起的年数
            int tm_wday;      一周中的第几天，范围从 0 到 6
            int tm_yday;        一年中的第几天，范围从 0 到 365
            int tm_isdst;       夏令时
    */
    // ESP_LOGI(TAG, "[APP] Startup..");
    // ESP_LOGI(TAG, "[APP] Free memory: %d bytes", esp_get_free_heap_size());
    // ESP_LOGI(TAG, "[APP] IDF version: %s", esp_get_idf_version());

    // ESP_ERROR_CHECK(nvs_flash_init());
    // ESP_ERROR_CHECK(esp_netif_init());
    // ESP_ERROR_CHECK(esp_event_loop_create_default());

    // /* This helper function configures Wi-Fi or Ethernet, as selected in menuconfig.
    //  * Read "Establishing Wi-Fi or Ethernet Connection" section in
    //  * examples/protocols/README.md for more information about this function.
    //  */
    // ESP_ERROR_CHECK(example_connect()); //使用通过连接函数连接互联网

    obtain_time();                //获取时间
    time(&now);                   //获取总秒数时间
    localtime_r(&now, &timeinfo); //将now unix时间戳格式转为timeinfo时间结构体

    while (1)
    {
        // Is time set? If not, tm_year will be (1970 - 1900).
        if (timeinfo.tm_year < (2016 - 1900)) //判断timeinfo是否正确否者重新获取
        {
            ESP_LOGI(TAG, "Time is not set yet. Connecting to WiFi and getting time over NTP.");
            obtain_time(); //获取时间
            // update 'now' variable with current time
            time(&now); //获取总秒数时间
        }
        time(&now);               //获取unix时间戳
        setenv("TZ", "CST-8", 1); //设置为东八区，中国是东八区
        tzset();
        localtime_r(&now, &timeinfo); //转为tm结构体
        /*打印时间*/
        ESP_LOGI(TAG, "实时时间：周%d,%d年:%d月:%d日,%d:%d:%d",
                 timeinfo.tm_wday, timeinfo.tm_year + 1900,
                 timeinfo.tm_mon + 1, timeinfo.tm_mday,
                 timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
        NTP.year = timeinfo.tm_year + 1900;
        NTP.month = timeinfo.tm_mon + 1;
        NTP.mday = timeinfo.tm_mday;
        NTP.hour = timeinfo.tm_hour;
        NTP.min = timeinfo.tm_min;
        NTP.sec = timeinfo.tm_sec;
        NTP.day = timeinfo.tm_wday;

        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
/*数据刷新任务*/
static void date_refresh_task(void *arg)
{
    char disbuf[30]; /*显示数据缓存*/
    while (1)
    {
        /*mqtt数据显示*/
        if (Fan == 1)
        {
            sprintf(disbuf, "On"); //风扇
            lv_label_set_text(ui_Device1, disbuf);
        }
        else
        {
            sprintf(disbuf, "Off"); //风扇
            lv_label_set_text(ui_Device1, disbuf);
        }
        if (Watering == 1)
        {
            sprintf(disbuf, "On"); //浇水
            lv_label_set_text(ui_Device2, disbuf);
        }
        else
        {
            sprintf(disbuf, "Off"); //浇水
            lv_label_set_text(ui_Device2, disbuf);
        }
        sprintf(disbuf, "%.2f C", temperature); //温度
        lv_label_set_text(ui_Temp, disbuf);
        sprintf(disbuf, "%.2f %%", Humidity); //湿度
        lv_label_set_text(ui_Humi, disbuf);
        sprintf(disbuf, "%.1f lux", LightLux); //光照
        lv_label_set_text(ui_Lux, disbuf);
        sprintf(disbuf, "%d ppm", co2); //CO2
        lv_label_set_text(ui_CO2, disbuf);
        sprintf(disbuf, "%.2f Kpa", Atmosphere); //大气压
        lv_label_set_text(ui_Atmo, disbuf);

        /*显示时间更新*/
        sprintf(disbuf, "%d", NTP.year);
        lv_label_set_text(ui_year, disbuf);
        /*月*/
        sprintf(disbuf, "%d", NTP.month);
        lv_label_set_text(ui_month, disbuf);
        /*日*/
        sprintf(disbuf, "%d", NTP.mday);
        lv_label_set_text(ui_mday, disbuf);
        /*时*/
        sprintf(disbuf, "%d", NTP.hour);
        lv_label_set_text(ui_hour, disbuf);
        /*分*/
        if (NTP.min < 10)
        {
            sprintf(disbuf, "0%d", NTP.min);
            lv_label_set_text(ui_min, disbuf);
        }
        else
        {
            sprintf(disbuf, "%d", NTP.min);
            lv_label_set_text(ui_min, disbuf);
        }
        /*秒*/
        if (NTP.sec < 10)
        {
            sprintf(disbuf, "0%d", NTP.sec);
            lv_label_set_text(ui_sec, disbuf);
        }
        else
        {
            sprintf(disbuf, "%d", NTP.sec);
            lv_label_set_text(ui_sec, disbuf);
        }
        /*星期*/
        switch (NTP.day)
        {
        case 1:
            sprintf(disbuf, "Monday");
            lv_label_set_text(ui_day, disbuf);
            break;
        case 2:
            sprintf(disbuf, "Tuesday");
            lv_label_set_text(ui_day, disbuf);
            break;
        case 3:
            sprintf(disbuf, "Wednesday");
            lv_label_set_text(ui_day, disbuf);
            break;
        case 4:
            sprintf(disbuf, "Thursday");
            lv_label_set_text(ui_day, disbuf);
            break;
        case 5:
            sprintf(disbuf, "Friday");
            lv_label_set_text(ui_day, disbuf);
            break;
        case 6:
            sprintf(disbuf, "Saturday");
            lv_label_set_text(ui_day, disbuf);
            break;
        case 7:
            sprintf(disbuf, "Sunday");
            lv_label_set_text(ui_day, disbuf);
            break;
        default:
            break;
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
/*uart发送任务*/
static void tx_task(void *arg)
{
    static const char *TX_TASK_TAG = "TX_TASK";
    esp_log_level_set(TX_TASK_TAG, ESP_LOG_INFO);
    while (1)
    {
        sendData(TX_TASK_TAG, "POWER VOTAGE CURRENT RESISTANCE\n");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
/*uart接收任务*/
static void rx_task(void *arg)
{
    char disbuf[30]; /*显示数据缓存*/
    while (1)
    {
        //获取串口0接收的数据
        int len = uart_read_bytes(UART_NUM_0, buffer, (RX_BUF_SIZE - 1), 20 / portTICK_PERIOD_MS); /* 从串口1的RX_FIFO获取字符串 */

        /* 如果读到包的话 */
        if (len)
        {
            buffer[len] = '\0'; /* 在结尾加入字符'\0'， */

            if (buffer[0] == 'A')//首帧
            {
                // sprintf(disbuf, "entry");
                // lv_label_set_text(ui_Label2, disbuf);
            }
            else
            {
                // sprintf(disbuf, buffer);
                // lv_label_set_text(ui_Label2, disbuf);
            }
            ESP_LOGI(TAG, "Recv str -> %s , and the length is:%d", buffer, strlen(buffer));            /* 打印logo */
            ESP_LOGI(TAG, "The size of buffer is %d,and ready to clear this buffer.", sizeof(buffer)); /* 打印logo */
            memset(buffer, 0, sizeof(buffer)); /* 清空内存，等待下一次的串口保文。 */
        }
    }
}

/*
*core 0 -> WIFI BLE
*core 1 -> GUI
**/

/*app_main*/
void app_main(void)
{
    init();
    /*task uxPriority  num : high -> low*/
    /*运行MQTT*/
    xTaskCreatePinnedToCore(mqtt_task,   //任务入口函数名作为函数指针调用
                            "mqtt_task", //任务名
                            1024 * 8,    //任务栈
                            "mqtt_task", //传给任务函数的参数
                            4,           //任务优先级
                            NULL,        //任务回传句柄
                            0);          //这个任务固定在0核心上执行

    /*获取NTP*/
    xTaskCreatePinnedToCore(Get_NTP_task,
                            "Get_NTP_task",
                            1024 * 4,
                            "Get_NTP_task",
                            3,
                            NULL,
                            0);
    /*刷Little GL*/
    xTaskCreatePinnedToCore(gui_task,
                            "gui_task",
                            1024 * 8,
                            "gui_task",
                            2,
                            NULL,
                            1);
    /*NTP&&MQTT数据刷新*/
    xTaskCreatePinnedToCore(date_refresh_task,
                            "daterefresh task",
                            1024 * 2,
                            "daterefresh task",
                            0,
                            NULL,
                            0);
    /*检测uart*/
    xTaskCreatePinnedToCore(rx_task,
                            "uart_rx_task",
                            1024 * 2,
                            "uart_rx_task",
                            0,
                            NULL,
                            0);
    // xTaskCreatePinnedToCore(rx_task, "uart_rx_task", 1024 * 2, NULL, 3, NULL, 0);
    // xTaskCreatePinnedToCore(tx_task, "uart_tx_task", 1024 * 2, NULL, 2, NULL, 0);
    while (1)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS); //app_main()也被看作一个任务，所以需要设置任务切换
    }
    //vTaskDelete();//不会执行到此，但如果不加上面的死循环则必须用这个指令删除任务防止内存溢出或程序跑飞
}









