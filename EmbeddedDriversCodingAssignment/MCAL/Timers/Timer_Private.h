/**
 * @file    Timer_Private.h
 * @brief   This shows the private macros and enums used by the timer driver
 * @author  mohammed diaa <mohammeddiaato@gmail.com>
 */
#ifndef _Timer_Private_H
#define _Timer_Private_H

typedef enum
{
    CS00,
    CS01,
    CS02,
    WGM01,
    COM00,
    COM01,
    WGM00,
    FOC0,
} TCCR0_Bits_t;
typedef enum
{
    TOIE0,
    OCIE0,
    
} TIMSK_Bits_t;
typedef enum
{
    TOV0,
    OCF0,
    
} TIFR_Bits_t;
typedef enum
{
    
    Reset_Prescaller_timer0_and_timer1=0,
    Global_Interrupt_Pin=7,
    
} SomeOther_Bits_t;

typedef enum
{
    Normal_Mode,
    PWM_PhaseCorrect_Mode,
    CTC_Mode,
    PWM_FastPWM,
    
} WaveForm_Modes_t;
typedef enum
{
    Normal_PORT,
    Toggle_OC0,
    Clear_OC0,
    Set_OC0,
    
} COM_NoNPWM_Modes_t;
typedef enum
{
    Normal_PORT,
    RESERVED_DO_NOT_USE,
    Non_Inverting,
    Inverting,
    
} COM_FAST_PWM_Modes_t;
typedef enum
{
No_Clock_Source,
Prescaller_1,
Prescaller_64,
Prescaller_256,
Prescaller_1024,
ExternalSource_FallingEdge,
ExternalSource_RisingEdge,
    
} COM_FAST_PWM_Modes_t;


#define SREG_Reg *((volatile u8 *)0x5F)
#define TCCR0_Reg *((volatile u8 *)0x53)
#define TCNT0_Reg *((volatile u8 *)0x52)
#define OCR0_Reg *((volatile u8 *)0x5C)
#define TIMSK_Reg *((volatile u8 *)0x59)
#define TIFR_Reg *((volatile u8 *)0x58)
#define SFIOR_Reg *((volatile u8 *)0x50)
#endif