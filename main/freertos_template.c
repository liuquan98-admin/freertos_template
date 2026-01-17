#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "app_tasks.h" // 引入任务创建函数
#include "esp_log.h"
#include "ledc.h"

static const char *MAIN_TAG = "APP_MAIN";
void app_main(void)
{
    // static const char *MAIN_TAG = "APP_MAIN";
    example_ledc_init();
    ESP_LOGI(MAIN_TAG, "ESP32 + FreeRTOS LED项目成功启动");
    app_tasks_create();
}
