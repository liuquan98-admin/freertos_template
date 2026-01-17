#include <stdio.h>
#include "driver/ledc.h"
#include "esp_err.h"
#define LEDC_TIMER LEDC_TIMER_0
#define LEDC_MODE LEDC_LOW_SPEED_MODE
#define LEDC_OUTPUT_IO (5) // Define the output GPIO
#define LEDC_CHANNEL LEDC_CHANNEL_0
// 所占的位数越多精度越高
#define LEDC_DUTY_RES LEDC_TIMER_13_BIT // Set duty resolution to 13 bits 占空比分辨率
#define LEDC_DUTY (4096)                // Set duty to 50%. (2 ** 13) * 50% = 4096
// 频率与周期互为倒数关系
#define LEDC_FREQUENCY (2000) // Frequency in Hertz. Set frequency at 4 kHz
void example_ledc_init(void)
{
    // Prepare and then apply the LEDC PWM timer configuration
    // 设定PWM频率和占空比分辨率
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_MODE,
        .duty_resolution = LEDC_DUTY_RES,
        .timer_num = LEDC_TIMER,
        .freq_hz = LEDC_FREQUENCY, // Set output frequency at 4 kHz
        .clk_cfg = LEDC_AUTO_CLK};
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    // Prepare and then apply the LEDC PWM channel configuration
    // 配置通道 把定时器和IO引脚关联起来，让IO脚输出PWM信号
    ledc_channel_config_t ledc_channel = {
        .speed_mode = LEDC_MODE,
        .channel = LEDC_CHANNEL,
        .timer_sel = LEDC_TIMER,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = LEDC_OUTPUT_IO,
        .duty = 0, // Set duty to 0%
        .hpoint = 0};
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
}