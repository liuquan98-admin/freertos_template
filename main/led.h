#ifndef __LED_H__
#define __LED_H__

// 定义LED控制引脚（以ESP32的GPIO2为例，根据你的硬件修改）
#define LED_GPIO_PIN 2

// 函数声明
void led_init(void);   // LED引脚初始化
void led_on(void);     // 点亮LED
void led_off(void);    // 熄灭LED
void led_toggle(void); // 翻转LED状态（可选，用于闪烁）

#endif // __LED_H__