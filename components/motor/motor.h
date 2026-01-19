#ifndef __MOTOR_H__
#define __MOTOR_H__

#define IN1_PIN 18 // A+
#define IN2_PIN 19 // A+
#define IN3_PIN 21 // A+
#define IN4_PIN 22 // A+

#define ENA_PIN 23
#define ENB_PIN 25

void stepper_2phase_init(void);
void stepper_2phase_step(uint8_t dir, uint32_t delay_us);

#endif
