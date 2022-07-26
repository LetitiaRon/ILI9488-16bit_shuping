#include "NTP.h"


static const char *TAG = "SNTP";

/*NTP（Init）*/
void initialize_sntp(void)
{
    ESP_LOGI(TAG, "Initializing SNTP");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    sntp_stop();    //不加这段ntp会报错
    sntp_enabled(); //不加这段ntp会报错
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, "pool.ntp.org");
    sntp_setservername(3, "cn.pool.ntp.org"); // 中国区NTP服务的虚拟集群
    sntp_setservername(1, "210.72.145.44");   // 国家授时中心服务器 IP 地址
    sntp_setservername(2, "ntp1.aliyun.com");
    sntp_init();
}

void obtain_time(void)
{
    // ESP_ERROR_CHECK(nvs_flash_init());
    // ESP_ERROR_CHECK(esp_netif_init());
    // ESP_ERROR_CHECK(esp_event_loop_create_default());

    /* This helper function configures Wi-Fi or Ethernet, as selected in menuconfig.
     * Read "Establishing Wi-Fi or Ethernet Connection" section in
     * examples/protocols/README.md for more information about this function.
     */
    // ESP_ERROR_CHECK(example_connect());

    initialize_sntp();

    // wait for time to be set
    time_t now = 0;
    struct tm timeinfo = {0};
    int retry = 0;
    const int retry_count = 10;
    while (sntp_get_sync_status() == SNTP_SYNC_STATUS_RESET && ++retry < retry_count)
    {
        ESP_LOGI(TAG, "Waiting for system time to be set... (%d/%d)", retry, retry_count);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
    time(&now);
    localtime_r(&now, &timeinfo);

    //  ESP_ERROR_CHECK(example_disconnect());
}
