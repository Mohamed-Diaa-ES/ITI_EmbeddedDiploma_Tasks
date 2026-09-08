/**
 * @file    Timer_Interface.h
 * @brief   This shows The APIs needed by the Timer driver
 * @author  mohammed diaa <mohammeddiaato@gmail.com>
 */
#ifndef _Timer_Interface_H
#define _Timer_Interface_H
typedef enum
{
    Normal_Mode = 0,
    PWM_PhaseCorrect_ICR1 = 10,
    CTC_ICR1 = 12,
    PWM_FastPWM = 14,

} WaveForm_Modes_t;

typedef enum
{
    No_Clock_Source_T1 = 0,
    Prescaller_1_T1    = 1,
    Prescaller_8_T1    = 2,
    Prescaller_64_T1   = 3,
    Prescaller_256_T1  = 4,
    Prescaller_1024_T1 = 5,
    ExternalSource_FallingEdge_T1 = 6,
    ExternalSource_RisingEdge_T1  = 7
} Prescaller_t;
u8 Timer1_u8Init(u8 mode,u8 prescaller);
u8 Timer1_u8SetAction(u8 Action);
u8 Timer1_SetICR(u16 Value);
u8 Timer1_u8_my_delay_ms(u16 ms);
u8 Timer1_u8SetCompareValue(u16 CompareValue,u8 A_or_B);
void Timer1_voidSet_OVE_CallBack(void(*Timer1_CallBack)(void));


#endif