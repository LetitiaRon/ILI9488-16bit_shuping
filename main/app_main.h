#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
/*freeRTOS*/
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "esp_freertos_hooks.h"
/*LVGL*/
#include "lvgl_helpers.h"
#include "lv_examples/src/lv_demo_widgets/lv_demo_widgets.h"
#include "lv_examples/src/lv_demo_music/lv_demo_music.h"
#include "lv_examples/src/lv_demo_benchmark/lv_demo_benchmark.h"
#include "lv_examples/src/lv_demo_stress/lv_demo_stress.h"
#include "lv_examples/src/lv_demo_keypad_encoder/lv_demo_keypad_encoder.h"
#include "my_lv_port_indev.h"
/*SD card and FAT filesystem example*/

/*WIFI*/
#include "esp_wifi.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "mqtt_client.h"
#include "protocol_examples_common.h"
#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"
#include "esp_log.h"
/*json解析*/
#include "cJSON.h"
/*uart*/
#include "driver/uart.h"
/*Task*/
#include "led/include/led.h"
#include "NTP/include/NTP.h"
#include "lv_mydemo/include/lv_mydemo.h"
/*Display_Port*/
#include "lv_port_disp.h"
#include "lv_port_tick.h"
/*UI*/
#include "ui.h"
#include "ui_helpers.h"

SemaphoreHandle_t xGuiSemaphore;

/*MQTT接收的数据*/
int32_t Fan;       //风扇状态
int32_t Watering;  //浇水状态
int32_t co2;       //CO2含量
double LightLux;    //光照强度
double Humidity;    //湿度
double temperature; //温度
double Atmosphere;  //大气压强

struct TimeSntp
{
    int year;
    int month;
    int mday;
    int day;
    int hour;
    int min;
    int sec;
}NTP;

/*json Data*/
cJSON *root;//存储到mqtt云流转的数据
int json_Flag = 0;

/*串口*/
static const int RX_BUF_SIZE = 1024;
static char buffer[1024]; /* 暂时存储从串口接收到的字符串 */