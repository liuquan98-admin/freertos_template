#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "app_tasks.h" // 引入任务创建函数
void app_main(void)
{

    app_tasks_create();
}