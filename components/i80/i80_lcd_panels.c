#include "i80_lcd_panels.h"

#include <stddef.h>

const lcd_panel_reg_t panel_st7796s_w350ce024a_40z_reg_table[] = {
    {0x11, NULL, 0},                                                                                             //退出休眠模式
    {0x21, NULL, 0},                                                                                             //开启反色显示
    {0xF0, (uint8_t[]){0xC3}, 1},                                                                                //使能指令集2第1部分
    {0xF0, (uint8_t[]){0x96}, 1},                                                                                //使能指令集2第2部分
    {0x36, (uint8_t[]){0x48}, 1},                                                                                //显存访问方式: MY=0, MX=1, MV=0, ML=0, RGB=1, MH=0
    {0x3A, (uint8_t[]){0x55}, 1},                                                                                //像素颜色格式: RGB模式16位, MCU模式16位
    {0xB4, (uint8_t[]){0x01}, 1},                                                                                //显示反转控制
    {0xB7, (uint8_t[]){0xC6}, 1},                                                                                //Entry Mode设置
    {0xC1, (uint8_t[]){0x06}, 1},                                                                                //GVDD&GVCL设置
    {0xC2, (uint8_t[]){0xA7}, 1},                                                                                //源极&gamma驱动电流设置
    {0xC5, (uint8_t[]){0x18}, 1},                                                                                //VCOM设置
    {0xE0, (uint8_t[]){0xF0, 0x09, 0x0B, 0x06, 0x04, 0x15, 0x2F, 0x54, 0x42, 0x3C, 0x17, 0x14, 0x18, 0x1B}, 14}, //正gamma控制
    {0xE1, (uint8_t[]){0xF0, 0x09, 0x0B, 0x06, 0x04, 0x03, 0x2D, 0x43, 0x42, 0x3B, 0x16, 0x14, 0x17, 0x1B}, 14}, //负gamma控制
    {0xE8, (uint8_t[]){0x40, 0x8A, 0x00, 0x00, 0x29, 0x19, 0xA5, 0x33}, 8},                                      //显示参数配置
    {0xF0, (uint8_t[]){0x3C}, 1},                                                                                //失能指令集2第1部分
    {0xF0, (uint8_t[]){0x69}, 1},                                                                                //失能指令集2第2部分

    {0, NULL, 0xFF} //寄存器列表结束
};

const lcd_panel_reg_t panel_st7796s_cl35bc1017_40a_reg_table[] = {
    {0x11, NULL, 0},                                                                                             //退出休眠模式
    {0x20, NULL, 0},                                                                                             //关闭反色显示
    {0xF0, (uint8_t[]){0xC3}, 1},                                                                                //使能指令集2第1部分
    {0xF0, (uint8_t[]){0x96}, 1},                                                                                //使能指令集2第2部分
    {0x36, (uint8_t[]){0xE8}, 1},                                                                                //显存访问方式: MY=1, MX=0, MV=1, ML=0, RGB=1, MH=0 D1=0 D0=0/*可以改这里扫描方向，横屏竖屏*/
    {0x3A, (uint8_t[]){0x55}, 1},                                                                                //像素颜色格式: RGB模式16位, MCU模式16位
    {0xC2, (uint8_t[]){0xA7}, 1},                                                                                //源极&gamma驱动电流
    {0xC5, (uint8_t[]){0x27}, 1},                                                                                //VCOM
    {0xE0, (uint8_t[]){0xF0, 0x01, 0x06, 0x0F, 0x12, 0x1D, 0x36, 0x54, 0x44, 0x0C, 0x18, 0x16, 0x13, 0x15}, 14}, //正gamma控制
    {0xE1, (uint8_t[]){0xF0, 0x01, 0x05, 0x0A, 0x0B, 0x07, 0x32, 0x44, 0x44, 0x0C, 0x18, 0x17, 0x13, 0x16}, 14}, //负gamma控制
    {0xE8, (uint8_t[]){0x40, 0x82, 0x07, 0x18, 0x27, 0x0A, 0xB6, 0x33}, 8},                                      //显示参数配置
    {0xF0, (uint8_t[]){0x3C}, 1},                                                                                //失能指令集2第1部分
    {0xF0, (uint8_t[]){0x69}, 1},                                                                                //失能指令集2第2部分
    {0, NULL, 0xFF}                                                                                              //寄存器列表结束
};

const lcd_panel_reg_t panel_ili9488_cl35bc106_40a_reg_table[] = {
    {0x11, NULL, 0},
    {0xF7, (uint8_t[]){0xA9, 0x51, 0x2C, 0x82}, 4},
    {0xEC, (uint8_t[]){0x00, 0x02, 0x03, 0x7A}, 4},
    {0xC0, (uint8_t[]){0x13, 0x13}, 2},
    {0xC1, (uint8_t[]){0x41}, 1},
    {0xC5, (uint8_t[]){0x00, 0x28, 0x80}, 3},
    {0xB1, (uint8_t[]){0xB0, 0x11}, 2},
    {0xB4, (uint8_t[]){0x02}, 1},
    {0xB6, (uint8_t[]){0x02, 0x22}, 2},
    {0xB7, (uint8_t[]){0xC6}, 1},
    {0xBE, (uint8_t[]){0x00, 0x04}, 2},
    {0xE9, (uint8_t[]){0x00}, 1},
    {0xF4, (uint8_t[]){0x00, 0x00, 0x0F}, 3},
    {0xE0, (uint8_t[]){0x00, 0x04, 0x0E, 0x08, 0x17, 0x0A, 0x40, 0x79, 0x4D, 0x07, 0x0E, 0x0A, 0x1A, 0x1D, 0x0F}, 16},
    {0xE1, (uint8_t[]){0x00, 0x1B, 0x1F, 0x02, 0x10, 0x05, 0x32, 0x34, 0x43, 0x02, 0x0A, 0x09, 0x33, 0x37, 0x0F}, 16},
    {0xF4, (uint8_t[]){0x00, 0x00, 0x0F}, 3},
    {0x36, (uint8_t[]){0x3F}, 1},
    {0x3A, (uint8_t[]){0x55}, 1},
    {0, NULL, 0xFF}};

const lcd_panel_reg_t panel_ili9488_P0395H01_reg_table[] = {
    {0x11, NULL, 0}, //out sleep
    //{0x29, NULL, 0},
    //{0x21, NULL, 0},              //开启反色显示
    //{0x20, NULL, 0},              //关闭反色显示

    // {0x36, (uint8_t[]){0x68}, 1}, //显存访问方式: MY=0, MX=1, MV=1, ML=0, RGB=1, MH=0  D1=0  D0=0 横屏1
    // {0x36, (uint8_t[]){0xB8}, 1}, //显存访问方式: MY=1, MX=0, MV=1, ML=1, RGB=1, MH=0  D1=0  D0=0 横屏2
    // {0x36, (uint8_t[]){0x18}, 1}, //显存访问方式: MY=0, MX=0, MV=0, ML=1, RGB=1, MH=0  D1=0  D0=0 竖屏1
    {0x36, (uint8_t[]){0x08}, 1}, //显存访问方式: MY=0, MX=0, MV=0, ML=1, RGB=1, MH=0  D1=0  D0=0 竖屏2
    
                                  //MX MY 对应屏幕竖着看
    {0x3A, (uint8_t[]){0x55}, 1}, //像素颜色格式: 0x55RGB模式16位  0x66RGB模式18位
    {0xF7, (uint8_t[]){0xA9, 0x51, 0x2C, 0x02}, 4},
    {0XEC, (uint8_t[]){0x00, 0x02, 0x03, 0x7A}, 4},
    {0xC0, (uint8_t[]){0x13, 0x13}, 2},
    {0xC1, (uint8_t[]){0x41}, 1},
    {0xC5, (uint8_t[]){0x00, 0x28, 0x80, 0x28}, 4},
    {0xB1, (uint8_t[]){0xB0, 0x11}, 2},
    {0xB4, (uint8_t[]){0x02}, 1},
    {0xB6, (uint8_t[]){0x02, 0x22}, 2},
    {0xB7, (uint8_t[]){0xc6}, 1},
    {0xBE, (uint8_t[]){0x00, 0x04}, 2},
    {0xE9, (uint8_t[]){0x00}, 1},
    {0xF4, (uint8_t[]){0x00, 0x00, 0x0f}, 3},
    {0xE0, (uint8_t[]){0x00, 0x04, 0x0E, 0x08, 0x17, 0x0A, 0x40, 0x79, 0x4D, 0x07, 0x0E, 0x0A, 0x1A, 0x1D, 0x0F}, 16},
    {0xE1, (uint8_t[]){0x00, 0x1B, 0x1F, 0x02, 0x10, 0x05, 0x32, 0x34, 0x43, 0x02, 0x0A, 0x09, 0x33, 0x37, 0x0F}, 16},
    {0xF4, (uint8_t[]){0x00, 0x00, 0x0f}, 3}, //解决电荷残留问题
    {0, NULL, 0xFF}};