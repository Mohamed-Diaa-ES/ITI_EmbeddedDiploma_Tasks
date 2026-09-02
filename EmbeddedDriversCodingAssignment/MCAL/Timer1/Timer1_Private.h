/**
 * @file    Timer_Private.h
 * @brief   This shows the private macros and enums used by the timer driver
 * @author  mohammed diaa <mohammeddiaato@gmail.com>
 */
#ifndef _Timer_Private_H
#define _Timer_Private_H

typedef enum
{
    WGM10,
    WGM11,
    FOC1B,
    FOC1A,
    COM1B0,
    COM1B1,
    COM1A0,
    COM1A1,
} TCCR1A_Bits_t;
typedef enum
{
    TCCR1B,
    CS10,
    CS11,
    CS12,
    WGM12 ,
    WGM13 ,
    ICES1=6,
    ICNC1=7,

} TCCR1B_Bits_t;

typedef enum
{
    TOIE1,
    OCIE1B,
    OCIE1A,
    TICIE1,
} TIMSK_Timer1_Bits_t;

typedef enum
{
    TOV1,
    OCF1B,
    OCF1A,
    ICF1,
} TIFR_Timer1_Bits_t;

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
    Toggle_OCA_B,
    Clear_OCA_B,
    Set_OCA_B,

} COM_NoNPWM_Modes_t;

typedef enum
{
    Normal_PORT_Fast_pwm,
    ONLY_FOR_MODE15_OCA_TOGGLE,
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

} PrescallerValues_t;

#define TCNT1_Reg *((volatile u16 *)0x4C)
#define OCR1A_Reg *((volatile u16 *)0x4A)
#define OCR1B_Reg *((volatile u16 *)0x48)
#define TIMSK_Reg *((volatile u8 *)0x59)
#define TIFR_Reg *((volatile u8 *)0x58)
#define SFIOR_Reg *((volatile u8 *)0x50)
#define SFIOR_Reg *((volatile u8 *)0x50)
#define TCCR1A_Reg *((volatile u8 *)0x4F)
#define TCCR1B_Reg *((volatile u8 *)0x4E)

#endif