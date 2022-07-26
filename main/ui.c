// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_hour;
lv_obj_t * ui_Label3;
lv_obj_t * ui_min;
lv_obj_t * ui_Label4;
lv_obj_t * ui_sec;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_year;
lv_obj_t * ui_Label1;
lv_obj_t * ui_month;
lv_obj_t * ui_Label2;
lv_obj_t * ui_mday;
lv_obj_t * ui_Panel3;
lv_obj_t * ui_day;
lv_obj_t * ui_Data1;
lv_obj_t * ui_Label10;
lv_obj_t * ui_Label11;
lv_obj_t * ui_Temp;
lv_obj_t * ui_Label12;
lv_obj_t * ui_Humi;
lv_obj_t * ui_Label13;
lv_obj_t * ui_Lux;
lv_obj_t * ui_Label14;
lv_obj_t * ui_Atmo;
lv_obj_t * ui_Label15;
lv_obj_t * ui_CO2;
lv_obj_t * ui_Label16;
lv_obj_t * ui_Device1;
lv_obj_t * ui_Label17;
lv_obj_t * ui_Device2;
lv_obj_t * ui_Data;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Label6;
lv_obj_t * ui_CPUTemp;
lv_obj_t * ui_Label7;
lv_obj_t * ui_BOARTemp;
lv_obj_t * ui_Label8;
lv_obj_t * ui_FanTemp;
lv_obj_t * ui_Label9;
lv_obj_t * ui_SSDTemp;
lv_obj_t * ui_Button1;
lv_obj_t * ui_Button2;
lv_obj_t * ui_Button3;
lv_obj_t * ui_Screen2;
lv_obj_t * ui_Button4;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

// ui_EloAnimation0
// FUNCTION HEADER
void FadeOn_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void FadeOn_Animation(lv_obj_t * TargetObject, int delay)
{

    //
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 300);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);

    //
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 300);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_1, -20, 0);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_1);

}

// ui_EloAnimation0
// FUNCTION HEADER
void FadeOff_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void FadeOff_Animation(lv_obj_t * TargetObject, int delay)
{

    //
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 200);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 255, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_opacity);
    lv_anim_start(&PropertyAnimation_0);

}

// ui_EloAnimation0
// FUNCTION HEADER
void FadexRight_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void FadexRight_Animation(lv_obj_t * TargetObject, int delay)
{

    //
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_opacity);
    lv_anim_start(&PropertyAnimation_0);

    //
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 500);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_1, -40, 0);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_1);

}

// ui_EloAnimation0
// FUNCTION HEADER
void Fade_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void Fade_Animation(lv_obj_t * TargetObject, int delay)
{

    //
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 100);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);

}

// ui_EloAnimation0
// FUNCTION HEADER
void FadexRight1_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void FadexRight1_Animation(lv_obj_t * TargetObject, int delay)
{

    //
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 600);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_opacity);
    lv_anim_start(&PropertyAnimation_0);

    //
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 700);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_1, -65, 0);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_1);

}

///////////////////// FUNCTIONS ////////////////////
static void ui_event_Screen1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_SCREEN_LOAD_START) {
        Fade_Animation(ui_Data1, 250);
        FadexRight1_Animation(ui_Panel3, 250);
        FadexRight1_Animation(ui_Panel2, 200);
        FadexRight1_Animation(ui_Panel1, 150);
        FadexRight1_Animation(ui_Data, 250);
    }
}
static void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        FadexRight_Animation(ui_Data1, 0);
        Fade_Animation(ui_Data, 200);
    }
}
static void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        FadexRight_Animation(ui_Data, 0);
        Fade_Animation(ui_Data1, 200);
    }
}
static void ui_event_Button3(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen2, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
}
static void ui_event_Button4(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{

    // ui_Screen1

    ui_Screen1 = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Screen1, ui_event_Screen1, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_img_src(ui_Screen1, &ui_img_bg1_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Panel1

    ui_Panel1 = lv_obj_create(ui_Screen1);

    lv_obj_set_width(ui_Panel1, 239);
    lv_obj_set_height(ui_Panel1, 53);

    lv_obj_set_x(ui_Panel1, -30);
    lv_obj_set_y(ui_Panel1, -180);

    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_blend_mode(ui_Panel1, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_hour

    ui_hour = lv_label_create(ui_Panel1);

    lv_obj_set_width(ui_hour, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_hour, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_hour, -80);
    lv_obj_set_y(ui_hour, 0);

    lv_obj_set_align(ui_hour, LV_ALIGN_CENTER);

    lv_label_set_text(ui_hour, "23");

    lv_obj_set_style_text_font(ui_hour, &lv_font_montserrat_46, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label3

    ui_Label3 = lv_label_create(ui_Panel1);

    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label3, -40);
    lv_obj_set_y(ui_Label3, 0);

    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label3, ":");

    lv_obj_set_style_text_font(ui_Label3, &lv_font_montserrat_46, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_min

    ui_min = lv_label_create(ui_Panel1);

    lv_obj_set_width(ui_min, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_min, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_min, 0);
    lv_obj_set_y(ui_min, 0);

    lv_obj_set_align(ui_min, LV_ALIGN_CENTER);

    lv_label_set_text(ui_min, "25");

    lv_obj_set_style_text_font(ui_min, &lv_font_montserrat_46, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label4

    ui_Label4 = lv_label_create(ui_Panel1);

    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label4, 40);
    lv_obj_set_y(ui_Label4, 0);

    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label4, ":");

    lv_obj_set_style_text_font(ui_Label4, &lv_font_montserrat_46, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_sec

    ui_sec = lv_label_create(ui_Panel1);

    lv_obj_set_width(ui_sec, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_sec, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_sec, 80);
    lv_obj_set_y(ui_sec, 0);

    lv_obj_set_align(ui_sec, LV_ALIGN_CENTER);

    lv_label_set_text(ui_sec, "24");

    lv_obj_set_style_text_font(ui_sec, &lv_font_montserrat_46, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Panel2

    ui_Panel2 = lv_obj_create(ui_Screen1);

    lv_obj_set_width(ui_Panel2, 126);
    lv_obj_set_height(ui_Panel2, 33);

    lv_obj_set_x(ui_Panel2, -85);
    lv_obj_set_y(ui_Panel2, -130);

    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_blend_mode(ui_Panel2, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_year

    ui_year = lv_label_create(ui_Panel2);

    lv_obj_set_width(ui_year, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_year, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_year, -30);
    lv_obj_set_y(ui_year, 0);

    lv_obj_set_align(ui_year, LV_ALIGN_CENTER);

    lv_label_set_text(ui_year, "2022");

    lv_obj_set_style_text_font(ui_year, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label1

    ui_Label1 = lv_label_create(ui_Panel2);

    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label1, 0);
    lv_obj_set_y(ui_Label1, 0);

    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label1, "/");

    lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_month

    ui_month = lv_label_create(ui_Panel2);

    lv_obj_set_width(ui_month, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_month, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_month, 15);
    lv_obj_set_y(ui_month, 0);

    lv_obj_set_align(ui_month, LV_ALIGN_CENTER);

    lv_label_set_text(ui_month, "10");

    lv_obj_set_style_text_font(ui_month, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label2

    ui_Label2 = lv_label_create(ui_Panel2);

    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label2, 30);
    lv_obj_set_y(ui_Label2, 0);

    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label2, "/");

    lv_obj_set_style_text_font(ui_Label2, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_mday

    ui_mday = lv_label_create(ui_Panel2);

    lv_obj_set_width(ui_mday, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_mday, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_mday, 45);
    lv_obj_set_y(ui_mday, 0);

    lv_obj_set_align(ui_mday, LV_ALIGN_CENTER);

    lv_label_set_text(ui_mday, "25");

    lv_obj_set_style_text_font(ui_mday, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Panel3

    ui_Panel3 = lv_obj_create(ui_Screen1);

    lv_obj_set_width(ui_Panel3, 126);
    lv_obj_set_height(ui_Panel3, 33);

    lv_obj_set_x(ui_Panel3, -85);
    lv_obj_set_y(ui_Panel3, -90);

    lv_obj_set_align(ui_Panel3, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_blend_mode(ui_Panel3, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_day

    ui_day = lv_label_create(ui_Panel3);

    lv_obj_set_width(ui_day, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_day, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_day, 0);
    lv_obj_set_y(ui_day, 0);

    lv_obj_set_align(ui_day, LV_ALIGN_CENTER);

    lv_label_set_text(ui_day, "Monday");

    lv_obj_set_style_text_font(ui_day, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Data1

    ui_Data1 = lv_obj_create(ui_Screen1);

    lv_obj_set_width(ui_Data1, 153);
    lv_obj_set_height(ui_Data1, 251);

    lv_obj_set_x(ui_Data1, -68);
    lv_obj_set_y(ui_Data1, 80);

    lv_obj_set_align(ui_Data1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Data1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Data1, lv_color_hex(0x64DDE1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Data1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Data1, lv_color_hex(0x6AE1E5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Data1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Data1, lv_color_hex(0x6AE1E5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Data1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Data1, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Data1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label10

    ui_Label10 = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label10, 0);
    lv_obj_set_y(ui_Label10, -110);

    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label10, "My MCU DATA");

    // ui_Label11

    ui_Label11 = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_Label11, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label11, -30);
    lv_obj_set_y(ui_Label11, -80);

    lv_obj_set_align(ui_Label11, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label11, "Temp:");

    // ui_Temp

    ui_Temp = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_Temp, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Temp, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Temp, 30);
    lv_obj_set_y(ui_Temp, -80);

    lv_obj_set_align(ui_Temp, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Temp, "30.62 C");

    // ui_Label12

    ui_Label12 = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_Label12, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label12, -30);
    lv_obj_set_y(ui_Label12, -50);

    lv_obj_set_align(ui_Label12, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label12, "Humi:");

    // ui_Humi

    ui_Humi = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_Humi, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Humi, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Humi, 30);
    lv_obj_set_y(ui_Humi, -50);

    lv_obj_set_align(ui_Humi, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Humi, "25.53 %");

    // ui_Label13

    ui_Label13 = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label13, -30);
    lv_obj_set_y(ui_Label13, -20);

    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label13, "Lux  :");

    // ui_Lux

    ui_Lux = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_Lux, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Lux, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Lux, 35);
    lv_obj_set_y(ui_Lux, -20);

    lv_obj_set_align(ui_Lux, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Lux, "20.32 lux");

    // ui_Label14

    ui_Label14 = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label14, -30);
    lv_obj_set_y(ui_Label14, 10);

    lv_obj_set_align(ui_Label14, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label14, "Atmo:");

    // ui_Atmo

    ui_Atmo = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_Atmo, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Atmo, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Atmo, 35);
    lv_obj_set_y(ui_Atmo, 10);

    lv_obj_set_align(ui_Atmo, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Atmo, "20.3 Kpa");

    // ui_Label15

    ui_Label15 = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label15, -30);
    lv_obj_set_y(ui_Label15, 70);

    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label15, "Device1:");

    // ui_CO2

    ui_CO2 = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_CO2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CO2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_CO2, 35);
    lv_obj_set_y(ui_CO2, 40);

    lv_obj_set_align(ui_CO2, LV_ALIGN_CENTER);

    lv_label_set_text(ui_CO2, "400 ppm");

    // ui_Label16

    ui_Label16 = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_Label16, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label16, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label16, -30);
    lv_obj_set_y(ui_Label16, 40);

    lv_obj_set_align(ui_Label16, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label16, "CO2:");

    // ui_Device1

    ui_Device1 = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_Device1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Device1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Device1, 35);
    lv_obj_set_y(ui_Device1, 70);

    lv_obj_set_align(ui_Device1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Device1, "Off");

    // ui_Label17

    ui_Label17 = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_Label17, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label17, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label17, -30);
    lv_obj_set_y(ui_Label17, 100);

    lv_obj_set_align(ui_Label17, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label17, "Device2:");

    // ui_Device2

    ui_Device2 = lv_label_create(ui_Data1);

    lv_obj_set_width(ui_Device2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Device2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Device2, 35);
    lv_obj_set_y(ui_Device2, 100);

    lv_obj_set_align(ui_Device2, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Device2, "Off");

    // ui_Data

    ui_Data = lv_obj_create(ui_Screen1);

    lv_obj_set_width(ui_Data, 153);
    lv_obj_set_height(ui_Data, 251);

    lv_obj_set_x(ui_Data, -68);
    lv_obj_set_y(ui_Data, 80);

    lv_obj_set_align(ui_Data, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Data, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Data, lv_color_hex(0x64DDE1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Data, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Data, lv_color_hex(0x6AE1E5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Data, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Data, lv_color_hex(0x6AE1E5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Data, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Data, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Data, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label5

    ui_Label5 = lv_label_create(ui_Data);

    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label5, -1);
    lv_obj_set_y(ui_Label5, -91);

    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label5, "My PC Sources");

    // ui_Label6

    ui_Label6 = lv_label_create(ui_Data);

    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label6, -20);
    lv_obj_set_y(ui_Label6, -40);

    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label6, "CPU_T      :");

    // ui_CPUTemp

    ui_CPUTemp = lv_label_create(ui_Data);

    lv_obj_set_width(ui_CPUTemp, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CPUTemp, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_CPUTemp, 40);
    lv_obj_set_y(ui_CPUTemp, -40);

    lv_obj_set_align(ui_CPUTemp, LV_ALIGN_CENTER);

    lv_label_set_text(ui_CPUTemp, "30.6C");

    // ui_Label7

    ui_Label7 = lv_label_create(ui_Data);

    lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label7, -20);
    lv_obj_set_y(ui_Label7, -10);

    lv_obj_set_align(ui_Label7, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label7, "BOARD_T:");

    // ui_BOARTemp

    ui_BOARTemp = lv_label_create(ui_Data);

    lv_obj_set_width(ui_BOARTemp, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BOARTemp, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BOARTemp, 40);
    lv_obj_set_y(ui_BOARTemp, -10);

    lv_obj_set_align(ui_BOARTemp, LV_ALIGN_CENTER);

    lv_label_set_text(ui_BOARTemp, "25.5C");

    // ui_Label8

    ui_Label8 = lv_label_create(ui_Data);

    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label8, -20);
    lv_obj_set_y(ui_Label8, 20);

    lv_obj_set_align(ui_Label8, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label8, "Fan_S      :");

    // ui_FanTemp

    ui_FanTemp = lv_label_create(ui_Data);

    lv_obj_set_width(ui_FanTemp, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_FanTemp, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_FanTemp, 40);
    lv_obj_set_y(ui_FanTemp, 20);

    lv_obj_set_align(ui_FanTemp, LV_ALIGN_CENTER);

    lv_label_set_text(ui_FanTemp, "20.3C");

    // ui_Label9

    ui_Label9 = lv_label_create(ui_Data);

    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label9, -20);
    lv_obj_set_y(ui_Label9, 50);

    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label9, "SSD_T     :");

    // ui_SSDTemp

    ui_SSDTemp = lv_label_create(ui_Data);

    lv_obj_set_width(ui_SSDTemp, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SSDTemp, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SSDTemp, 40);
    lv_obj_set_y(ui_SSDTemp, 50);

    lv_obj_set_align(ui_SSDTemp, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SSDTemp, "20.3C");

    // ui_Button1

    ui_Button1 = lv_btn_create(ui_Screen1);

    lv_obj_set_width(ui_Button1, 47);
    lv_obj_set_height(ui_Button1, 39);

    lv_obj_set_x(ui_Button1, 125);
    lv_obj_set_y(ui_Button1, -215);

    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);
    lv_obj_set_style_opa(ui_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Button2

    ui_Button2 = lv_btn_create(ui_Screen1);

    lv_obj_set_width(ui_Button2, 47);
    lv_obj_set_height(ui_Button2, 39);

    lv_obj_set_x(ui_Button2, -125);
    lv_obj_set_y(ui_Button2, -215);

    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);
    lv_obj_set_style_opa(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Button3

    ui_Button3 = lv_btn_create(ui_Screen1);

    lv_obj_set_width(ui_Button3, 40);
    lv_obj_set_height(ui_Button3, 30);

    lv_obj_set_x(ui_Button3, 0);
    lv_obj_set_y(ui_Button3, -225);

    lv_obj_set_align(ui_Button3, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Button3, ui_event_Button3, LV_EVENT_ALL, NULL);
    lv_obj_set_style_opa(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_Screen2_screen_init(void)
{

    // ui_Screen2

    ui_Screen2 = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_img_src(ui_Screen2, &ui_img_bg2_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Button4

    ui_Button4 = lv_btn_create(ui_Screen2);

    lv_obj_set_width(ui_Button4, 40);
    lv_obj_set_height(ui_Button4, 30);

    lv_obj_set_x(ui_Button4, 0);
    lv_obj_set_y(ui_Button4, -225);

    lv_obj_set_align(ui_Button4, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_Button4, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Button4, ui_event_Button4, LV_EVENT_ALL, NULL);
    lv_obj_set_style_opa(ui_Button4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_Screen2_screen_init();
    lv_disp_load_scr(ui_Screen1);
}

