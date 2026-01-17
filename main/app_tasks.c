#include "app_tasks.h"
#include "freertos/FreeRTOS.h" // FreeRTOS核心头文件
#include "freertos/task.h"     // FreeRTOS任务相关头文件
#include "led.h"               // 引入LED驱动

/**
 * @brief  LED闪烁任务函数（FreeRTOS任务核心逻辑）
 * @param  pvParameters: 任务参数（此处未使用，传NULL）
 */
static void led_blink_task(void *pvParameters)
{
    // 1. 初始化LED硬件（任务内初始化，解耦更友好）
    led_init();

    // 2. FreeRTOS任务必须是无限循环（否则任务会被删除）
    for (;;)
    {
        // 方式1：手动控制亮灭（直观）
        led_on();
        vTaskDelay(pdMS_TO_TICKS(300)); // 延时1秒（释放CPU给其他任务）
        led_off();
        vTaskDelay(pdMS_TO_TICKS(300)); // 延时1秒

        // 方式2：翻转状态（代码更简洁，效果和方式1一致）
        // led_toggle();
        // vTaskDelay(pdMS_TO_TICKS(1000)); // 1秒翻转一次，即1秒亮1秒灭
    }

    // 3. 任务删除（无限循环不会执行到这里，仅规范写法）
    vTaskDelete(NULL);
}

/**
 * @brief  创建所有应用任务（统一管理任务创建）
 */
void app_tasks_create(void)
{
    // 创建LED闪烁任务
    BaseType_t task_create_ret = xTaskCreate(
        led_blink_task, // 任务函数
        "led_blink",    // 任务名称（仅调试用，长度≤configMAX_TASK_NAME_LEN）
        2048,           // 任务栈大小（ESP32建议≥2048字节，避免栈溢出）
        NULL,           // 任务参数（无则传NULL）
        1,              // 任务优先级（0最低，建议1~5，避免高于系统任务）
        NULL            // 任务句柄（无需控制任务则传NULL）
    );

    // 检查任务创建是否成功（可选，调试用）
    if (task_create_ret != pdPASS)
    {
        // 任务创建失败（通常是堆内存不足），可添加日志或错误处理
        printf("LED任务创建失败！\n");
    }
}
