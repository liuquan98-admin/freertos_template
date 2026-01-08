#include "led.h"

#include "driver/gpio.h" // ESP32 GPIO驱动头文件（其他芯片替换为对应GPIO库）

// LED引脚初始化

void led_init(void)

{

    // 配置GPIO为输出模式

    gpio_config_t io_conf = {0};
    io_conf
        .mode = GPIO_MODE_OUTPUT; // 输出模式
    io_conf
        .pin_bit_mask = (1ULL << LED_GPIO_PIN); // 配置目标引脚
    io_conf
        .pull_down_en = GPIO_PULLDOWN_DISABLE; // 禁用下拉
    io_conf
        .pull_up_en = GPIO_PULLUP_DISABLE; // 禁用上拉

    gpio_config(&io_conf);

    // 初始状态：熄灭LED

    led_off();
}

// 点亮LED（低电平点亮，若你的硬件是高电平，改为GPIO_SET_LEVEL即可）

void led_on(void)

{

    gpio_set_level(LED_GPIO_PIN, 0);
}

// 熄灭LED

void led_off(void)

{

    gpio_set_level(LED_GPIO_PIN, 1);
}

// 翻转LED状态（可选）

void led_toggle(void)

{

    gpio_set_level(LED_GPIO_PIN, !gpio_get_level(LED_GPIO_PIN));
}