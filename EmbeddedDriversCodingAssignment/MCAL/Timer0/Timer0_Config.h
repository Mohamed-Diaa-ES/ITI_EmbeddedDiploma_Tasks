/**
 * @file    Timer_Config.h
 * @brief   This shows the configurable macros that we can configure for the Timer Driver
 * @author  mohammed diaa <mohammeddiaato@gmail.com>
 */
#ifndef _Timer_Config_H
#define _Timer_Config_H

/**
 * @enum Timer0_Ms_or_Us_t
 * @brief
 */
typedef enum
{
    US_Second = 1,
    Milli_Second = 1000UL * US_Second,
    Second = 1000UL * Milli_Second

} Timer0_Ms_or_Us_t;

#define TIMER0_TICKS_DENOMINATOR(prescaler) ((u32)(prescaler) * 1000000UL)

#define TIMER0_OVERFLOW_TIME_US(prescaler) (((u32)Timer0_Overflow_Value * TIMER0_TICKS_DENOMINATOR(prescaler)) / CPU_F)

#define TIMER0_REQUIRED_TICKS_US(time_us, prescaler) ((((u32)(time_us) * CPU_F) + (TIMER0_TICKS_DENOMINATOR(prescaler) / 2UL)) / TIMER0_TICKS_DENOMINATOR(prescaler))

#define TIMER0_REQUIRED_TICKS_MS(time_ms, prescaler) ((((u32)(time_ms) * 1000UL * CPU_F) + (TIMER0_TICKS_DENOMINATOR(prescaler) / 2UL)) / TIMER0_TICKS_DENOMINATOR(prescaler))


#define Fail 0
#define Success 1

#define EXTERNAL_CLOCK_RISING 5
#define EXTERNAL_CLOCK_FALLIN 6
#endif