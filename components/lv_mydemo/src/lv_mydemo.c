
#include "lv_mydemo.h"

#include "../../lvgl/lvgl.h"

static void btn_event_callback(lv_event_t* event)
{
    static uint32_t counter = 1;
 
    lv_obj_t* btn = lv_event_get_target(event); //获取事件对象
    if (btn != NULL)
    {
        lv_obj_t* label = lv_obj_get_child(btn, 0); // 获取第一个子对象
        if (label != NULL)
        {
            lv_label_set_text_fmt(label, "%d", counter); //设置显示内容
            counter++;
        }
    }
}

void lv_button_click_event_test()
{
    lv_obj_t* btn = lv_btn_create(lv_scr_act()); // 创建Button对象
    if (btn != NULL)
    {
        lv_obj_set_size(btn, 80, 30); // 设置对象大小,宽度和高度
        lv_obj_center(btn);
        lv_obj_add_event_cb(btn, btn_event_callback, LV_EVENT_CLICKED, NULL); // 给对象添加CLICK事件和事件处理回调函数
 
        lv_obj_t* label = lv_label_create(btn); // 基于Button对象创建Label对象
        if (label != NULL)
        {
            lv_label_set_text(label, "Click me!"); // 设置显示内容
            lv_obj_center(label); // 对象居中显示
        }
    }
}


static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        char buf[32];
        lv_dropdown_get_selected_str(obj, buf, sizeof(buf));
        LV_LOG_USER("Option: %s", buf);
    }
}

void lv_example_dropdown_1()
{

    /*Create a normal drop down list*/
    lv_obj_t * dd = lv_dropdown_create(lv_scr_act());
    lv_dropdown_set_options(dd, "Apple\n"
                                "Banana\n"
                                "Orange\n"
                                "Cherry\n"
                                "Grape\n"
                                "Raspberry\n"
                                "Melon\n"
                                "Orange\n"
                                "Lemon\n"
                                "Nuts");

    lv_obj_align(dd, LV_ALIGN_TOP_MID, 0, 60);
    lv_obj_add_event_cb(dd, event_handler, LV_EVENT_ALL, NULL);
}


void lv_mydemo(void)
{
    lv_button_click_event_test();
    lv_example_dropdown_1();
}
