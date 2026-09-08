#ifndef _Timer1_Config_H
#define _Timer1_Config_H

#define CPU_F 8000000UL

#define True_Setting  1
#define False_Setting 0

/* Servo PWM Configuration (50Hz / 20ms) */
#define TIMER1_ICR1_20MS_TOP        19999U 
#define TIMER1_SERVO_0_DEG_TICKS    500U   // 0.5 ms pulse
#define TIMER1_SERVO_180_DEG_TICKS  2500U  // 2.5 ms pulse
#define TIMER1_SERVO_10_DEG_STEP    111U   // (2500-500)/18

#endif