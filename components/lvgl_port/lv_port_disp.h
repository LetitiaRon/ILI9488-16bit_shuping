#ifndef __LV_PORT_DISP_H
#define __LV_PORT_DISP_H

/* lvgl缓冲区大小，单位为像素数 */
#define LVGL_BUFF_SIZE (LCD_X_PIXELS*LCD_Y_PIXELS/4) // 1/8屏幕分辨率

void lv_port_disp_init(void);

#endif
