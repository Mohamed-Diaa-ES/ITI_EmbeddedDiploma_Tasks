/**
 * @file    Timer_Private.h
 * @brief   This shows the private macros and enums used by the timer driver
 * @author  mohammed diaa <mohammeddiaato@gmail.com>
 */
#ifndef _Timer_Private_H
#define _Timer_Private_H
/**
 * @enum TCCR0_Bits_t
 * @brief
 */
typedef enum
{
    CS00_Bit,
    CS01_Bit,
    CS02_Bit,
    WGM01_Bit,
    COM00_Bit,
    COM01_Bit,
    WGM00_Bit,
    FOC0_Bit,
} TCCR0_Bits_t;
/**
 * @enum TIMSK_Bits_t
 * @brief
 */
typedef enum
{
    TOIE0_Bit,
    OCIE0_Bit,

} TIMSK_Bits_t;
/**
 * @enum TIFR_Bits_t
 * @brief
 */
typedef enum
{
    TOV0_Bit,
    OCF0_Bit,

} TIFR_Bits_t;

#define Reset_Prescaller_timer0_and_timer1_SFIOR_Reg 0

#define Timer0_Overflow_Value 256UL
#define Prescaller_ClearingMask 0xF8
#define Prescaller_SetMask 0x07
#define Action_ClearingMask ~0x30
#define Action_SetMask      0x30


#define TCCR0_Reg *((volatile u8 *)0x53)
#define TCNT0_Reg *((volatile u8 *)0x52)
#define OCR0_Reg *((volatile u8 *)0x5C)
#define TIMSK_Reg *((volatile u8 *)0x59)
#define TIFR_Reg *((volatile u8 *)0x58)
#define SFIOR_Reg *((volatile u8 *)0x50)
#endif