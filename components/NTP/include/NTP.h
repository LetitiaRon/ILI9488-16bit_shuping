#ifndef __NTP_H
#define __NTP_H

#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"
#include "sntp.h"
#include "esp_log.h"
#include "esp_sntp.h"


void initialize_sntp(void); /*NTP初始化*/
void obtain_time(void);     /*获取NTP*/

#endif
