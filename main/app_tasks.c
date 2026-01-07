#ifndef __APP_TASKS_H__
#define __APP_TASKS_H__

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

/* 任务优先级定义 */
#define TASK1_PRIORITY (tskIDLE_PRIORITY + 1)
#define TASK2_PRIORITY (tskIDLE_PRIORITY + 2)

/* 任务栈大小定义 */
#define TASK1_STACK_SIZE (2048)
#define TASK2_STACK_SIZE (2048)

/* 队列句柄声明 */
extern QueueHandle_t g_data_queue;

/* 任务创建函数 */
void app_tasks_create(void);
/**
 * #void
 */

#endif