#include "led.h"
#include "driver/gpio.h" // ESP-IDF官方GPIO驱动头文件
#include "esp_log.h"

// 定义LED模块日志标签（大写，便于识别）
static const char *LED_TAG = "LED_DRIVER";

// LED初始化：配置GPIO为推挽输出，禁用上下拉
void led_init(void)
{
    // 1. 定义GPIO配置结构体
    gpio_config_t led_gpio_conf = {0};

    // 2. 配置参数
    led_gpio_conf
        .mode = GPIO_MODE_OUTPUT; // 输出模式
    led_gpio_conf
        .pin_bit_mask = (1ULL << LED_GPIO_PIN); // 配置目标引脚
    led_gpio_conf
        .pull_down_en = GPIO_PULLDOWN_DISABLE; // 禁用下拉电阻
    led_gpio_conf
        .pull_up_en = GPIO_PULLUP_DISABLE; // 禁用上拉电阻

    // 3. 应用配置到GPIO
    gpio_config(&led_gpio_conf);

    // 4. 初始状态：熄灭LED
    led_off();

    ESP_LOGI(LED_TAG, "LED初始化完成，控制引脚：GPIO%d", LED_GPIO_PIN);
}

// 点亮LED（低电平点亮，若硬件是高电平则改为1）
void led_on(void)
{
    gpio_set_level(LED_GPIO_PIN, 0);

    ESP_LOGD(LED_TAG, "LED已点亮（GPIO%d电平：1）", LED_GPIO_PIN);
}

// 熄灭LED（高电平熄灭，若硬件是低电平则改为0）
void led_off(void)
{
    gpio_set_level(LED_GPIO_PIN, 1);
    ESP_LOGD(LED_TAG, "熄灭LED（GPIO%d电平：1）", LED_GPIO_PIN);
}

// 翻转LED状态（用于闪烁更简洁）
void led_toggle(void)
{
    // 读取当前引脚电平，取反后设置
    gpio_set_level(LED_GPIO_PIN, !gpio_get_level(LED_GPIO_PIN));
    // ESP_LOGD(LED_TAG, "反转电平"，LED_GPIO_PIN);
}