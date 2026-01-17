#ifndef __LED_H__
#define __LED_H__

// 定义LED控制引脚（可根据实际接线修改，推荐GPIO2/4/5）
#define LED_GPIO_PIN 4

/**
 * @brief  LED硬件初始化（配置GPIO为输出模式）
 */
void led_init(void);

/**
 * @brief  点亮LED
 */
void led_on(void);

/**
 * @brief  熄灭LED
 */
void led_off(void);

/**
 * @brief  翻转LED状态（亮→灭/灭→亮）
 */
void led_toggle(void);

#endif // __LED_H__