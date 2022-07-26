#ifndef __I80_LCD_PANELS_H
#define __I80_LCD_PANELS_H

#include <stdint.h>

typedef struct {
    uint8_t reg;
    uint8_t *val;
    uint8_t len;
} lcd_panel_reg_t;

extern const lcd_panel_reg_t panel_st7796s_w350ce024a_40z_reg_table[];
extern const lcd_panel_reg_t panel_st7796s_cl35bc1017_40a_reg_table[];
extern const lcd_panel_reg_t panel_ili9488_cl35bc106_40a_reg_table[];
extern const lcd_panel_reg_t panel_ili9488_P0395H01_reg_table[];


#endif