#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "app_tasks.h" // 引入任务创建函数
#include "esp_log.h"
#include "ledc.h"
#include "motor.h"
// static const char *MAIN_TAG = "APP_MAIN"
void app_main(void)
{

    // example_ledc_init();
    // ESP_LOGI(MAIN_TAG, "3.example_ledc_init()================");
    // example_create_ledc();
    // ESP_LOGI(MAIN_TAG, "4.example_create_led();==============");
    // // app_tasks_create();

    // ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, LEDC_DUTY));
    // // Update duty to apply the new value
    // // 让占空比生效
    // ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_CHANNEL));

    stepper_2phase_init();
    while (1)
    {
        // 正转200步，每步延时800us
        for (int i = 0; i < 200; i++)
        {
            stepper_2phase_step(1, 800);
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
        // 反转200步
        for (int i = 0; i < 200; i++)
        {
            stepper_2phase_step(0, 800);
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
