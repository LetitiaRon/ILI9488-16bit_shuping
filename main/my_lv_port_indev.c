/**
 * @file lv_port_indev_templ.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "my_lv_port_indev.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void button_init(void);
static void button_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
static int8_t button_get_pressed_id(void);
static bool button_is_pressed(uint8_t id);

static void encoder_init(void);
static void encoder_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
static void encoder_handler(void);
/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t *indev_button;
lv_indev_t *indev_encoder;
static int32_t encoder_diff;

static lv_indev_state_t encoder_state;
/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void)
{
    /**
     * Here you will find example implementation of input devices supported by LittelvGL:
     *  - Touchpad
     *  - Mouse (with cursor support)
     *  - Keypad (supports GUI usage only with key)
     *  - Encoder (supports GUI usage only with: left, right, push)
     *  - Button (external buttons to press points on the screen)
     *
     *  The `..._read()` function are only examples.
     *  You should shape them according to your hardware
     */

    static lv_indev_drv_t indev_drv;
    /*------------------
     * Button
     * -----------------*/

    /*Initialize your button if you have*/
    button_init();

    /*Register a button input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_BUTTON;
    indev_drv.read_cb = button_read;
    indev_button = lv_indev_drv_register(&indev_drv);

    /*Assign buttons to points on the screen*/
    /*这里对应lv_obj_set_pos(btn, 210, 100);的位置，位置不对不能触发*/
    static const lv_point_t btn_points[3] = {
        /*按键个数增加这里也要加*/
        {300, 25}, /*Buttonup 0 -> x:10; y:10*/
        {160, 20}, /*Buttonentery 1 -> x:40; y:100*/
        {20, 25},  /*Buttondown 0 -> x:10; y:10*/
    };
    lv_indev_set_button_points(indev_button, btn_points);

    // /*------------------
    //  * Encoder
    //  * -----------------*/

    // /*Initialize your encoder if you have*/
    // encoder_init();

    // /*Register a encoder input device*/
    // lv_indev_drv_init(&indev_drv);
    // indev_drv.type = LV_INDEV_TYPE_ENCODER;
    // indev_drv.read_cb = encoder_read;
    // indev_encoder = lv_indev_drv_register(&indev_drv);

    // /*Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
    //  *add objects to the group with `lv_group_add_obj(group, obj)`
    //  *and assign this input device to group to navigate in it:
    //  *`lv_indev_set_group(indev_encoder, group);`*/
}

/*------------------
 * Button
 * -----------------*/

/*Initialize your buttons*/
static void button_init(void)
{
    /*Your code comes here*/
    /*写自己的物理按键初始化*/
    gpio_set_direction(Button_UP, GPIO_MODE_INPUT);      // up
    gpio_set_direction(Button_ENTERY, GPIO_MODE_INPUT);  // entery
    gpio_set_direction(Button_DOWN, GPIO_MODE_INPUT);    // down
    gpio_set_pull_mode(Button_UP, GPIO_PULLUP_ONLY);     //上拉
    gpio_set_pull_mode(Button_ENTERY, GPIO_PULLUP_ONLY); //上拉
    gpio_set_pull_mode(Button_DOWN, GPIO_PULLUP_ONLY);   //上拉
}

/*Will be called by the library to read the button*/
static void button_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{

    static uint8_t last_btn = 0;

    /*Get the pressed button's ID*/
    int8_t btn_act = button_get_pressed_id();

    if (btn_act >= 0)
    {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
    }

    /*Save the last pressed button's ID*/
    data->btn_id = last_btn;
}

/*Get ID  (0, 1, 2 ..) of the pressed button*/
static int8_t button_get_pressed_id(void) //读取所有按键
{
    uint8_t i;

    /*Check to buttons see which is being pressed (assume there are 2 buttons)*/
    for (i = 0; i < 3; i++) /*自己按键多少个就加duo'shao'g*/
    {
        /*Return the pressed button's ID*/
        if (button_is_pressed(i))
        {
            return i;
        }
    }

    /*No button pressed*/
    return -1;
}

/*Test if `id` button is pressed or not*/
static bool button_is_pressed(uint8_t id) //获取按键是否按下
{

    /*Your code comes here*/
    uint8_t i;
    if (id == 0) //上按键
    {
        i = gpio_get_level(35);
        if (i == 0)
        {
            printf("GPIO35 Up Press\n");
            return true;
        }
    }
    else if (id == 1) //中按键
    {
        i = gpio_get_level(45);
        if (i == 0)
        {
            printf("GPIO45 Entery Press\n");
            return true;
        }
    }
    else if (id == 2) //下按键
    {
        i = gpio_get_level(48);
        if (i == 0)
        {
            printf("GPIO48 Down Press\n");
            return true;
        }
    }
    return false;
}

/*------------------
 * Encoder
 * -----------------*/

/*Initialize your keypad*/
static void encoder_init(void)
{
    /*Your code comes here*/
    gpio_set_direction(EC_A, GPIO_MODE_INPUT);  // up
    gpio_set_direction(EC_K, GPIO_MODE_INPUT);  // entery
    gpio_set_direction(EC_B, GPIO_MODE_INPUT);  // down
    gpio_set_pull_mode(EC_A, GPIO_PULLUP_ONLY); // UP INPUT
    gpio_set_pull_mode(EC_K, GPIO_PULLUP_ONLY); // UP INPUT
    gpio_set_pull_mode(EC_B, GPIO_PULLUP_ONLY); // UP INPUT
}

/*Will be called by the library to read the encoder*/
static void encoder_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    data->enc_diff = encoder_diff;
    data->state = encoder_state;

    encoder_diff = 0;
    /*Return `false` because we are not buffering and no more data to read*/
    return false;
}

/*Call this function in an interrupt to process encoder events (turn, press)*/
static void encoder_handler(void)
{
    /*Your code comes here*/
    static bool but_flag = true;

    if (gpio_get_level(EC_K) == 0)
        encoder_state = LV_INDEV_STATE_PR; //按下
    else
        encoder_state = LV_INDEV_STATE_REL; //松开

    if (gpio_get_level(EC_A) == 0 && gpio_get_level(EC_B) == 1 && but_flag) //编码器左转
    {
        encoder_diff--;
        but_flag = false;
    }
    else if (gpio_get_level(EC_A) == 1 && gpio_get_level(EC_B) == 0 && but_flag) //编码器右转
    {
        encoder_diff++;
        but_flag = false;
    }
    else if (gpio_get_level(EC_A) == 1 && gpio_get_level(EC_B) == 1)
        but_flag = true;

    // printf("but_flag:%d \n", encoder_state);
    // printf("encoder_diff:%d \n", encoder_diff);

    /*数据释放*/
    encoder_diff += 0;
    encoder_state = LV_INDEV_STATE_REL;
}