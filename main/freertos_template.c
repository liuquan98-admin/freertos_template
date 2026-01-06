#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "app_tasks.h"
#include "esp_task_wdt.h" // 新增：引入任务看门狗API的头文件
static const char *TAG = "main";

void app_main(void)
{
    ESP_LOGI(TAG, "ESP-IDF FreeRTOS Template Start");

    /* 关闭看门狗（可选，调试用） */
    // esp_task_wdt_delete(NULL);

    /* 创建所有应用任务 */
    // app_tasks_create(/* 参数 */);

    /* 释放app_main任务栈 */
    // vTaskDelete(NULL);
}