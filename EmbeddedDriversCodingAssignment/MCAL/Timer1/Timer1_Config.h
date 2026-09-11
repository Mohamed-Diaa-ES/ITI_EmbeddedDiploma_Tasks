#ifndef _Timer1_Config_H
#define _Timer1_Config_H

#define CPU_F 8000000UL

#define True_Setting 1
#define False_Setting 0
#define A_OCR 1
#define B_OCR 0
/* Servo PWM Configuration (50Hz / 20ms period) */
#define TIMER1_ICR1_20MS_TOP 19999U

/* Standard Servo Pulse Widths (1.0 ms to 2.0 ms) */
#define TIMER1_SERVO_0_DEG_TICKS 1000U   // 1.0 ms pulse = 0 degrees
#define TIMER1_SERVO_180_DEG_TICKS 2000U // 2.0 ms pulse = 180 degrees
#define TIMER1_SERVO_10_DEG_STEP 55U     // 1000 ticks / 18 steps ≈ 55.55 ticks

#endif