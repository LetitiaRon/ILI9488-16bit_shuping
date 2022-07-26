
/**
 * @file lv_port_indev_templ.h
 *
 */

 /*Copy this file as "lv_port_indev.h" and set this value to "1" to enable content*/

#ifndef MY_LV_PORT_INDEV_H
#define MY_LV_PORT_INDEV_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"
#include "sdkconfig.h"
#include "driver/gpio.h"
/*********************
 *      DEFINES
 *********************/
//your Button GPIO
#define Button_UP       35
#define Button_ENTERY   45
#define Button_DOWN     48

//your encoder GPIO
#define EC_A -1
#define EC_K -1
#define EC_B -1

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void lv_port_indev_init(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_PORT_INDEV_TEMPL_H*/

