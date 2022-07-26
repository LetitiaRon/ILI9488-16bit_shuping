
# LVGL TEMPLATE  <br>
ILI9488

## About ESP32

* board: ESP32-S3
* flash size: 8MB
* esp-idf: v4.4

## About LCD TFT

* LCD driver: ILI9488
* LCD module: 3.95 TFT  320x480


## About LVGL

* LVGL : v8.0.0

# NOTE:

* wifi连接是用外部的example
* 在外部的cmake里面加 set(EXTRA_COMPONENT_DIRS $ENV{IDF_PATH}/examples/common_components/protocol_examples_common)

