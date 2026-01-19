#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "motor.h"
#include "esp_rom_sys.h"
uint8_t step_seq[8][4] = {
    {1, 0, 0, 0},
    {1, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 1, 1, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 1},
    {0, 0, 0, 1},
    {1, 0, 0, 1},
};
// 初始化电机GPIO口
void stepper_2phase_init()
{
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ull << IN1_PIN) | (1ull << IN2_PIN) |
                        (1ull << IN3_PIN) | (1ull << IN4_PIN) |
                        (1ull << IN3_PIN) | (1ull << IN4_PIN) |
                        (1ull << ENA_PIN) | (1ull << ENB_PIN),
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .intr_type = GPIO_INTR_DISABLE

    };

    gpio_config(&io_conf);
    gpio_set_level(ENA_PIN, 1);
    gpio_set_level(ENB_PIN, 1);
}
void stepper_2phase_step(uint8_t dir, uint32_t delay_us)
{
    static uint8_t current_step = 0;
    current_step = dir ? (current_step + 1) % 8 : (current_step - 1 + 8) % 8;
    // 输出时序电平
    gpio_set_level(IN1_PIN, step_seq[current_step][0]);
    gpio_set_level(IN2_PIN, step_seq[current_step][1]);
    gpio_set_level(IN3_PIN, step_seq[current_step][2]);
    gpio_set_level(IN4_PIN, step_seq[current_step][3]);
    esp_rom_delay_us(delay_us);
}