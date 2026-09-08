#ifndef _Timer_Interface_H
#define _Timer_Interface_H

#include "../../LIB/STD_TYPES.h"
#include "Timer0_Config.h"

/* Direct mapping to CS02:0 bits in TCCR0 */
typedef enum
{
    No_Clock_Source_T0 = 0,
    Prescaller_1_T0    = 1,
    Prescaller_8_T0    = 2,
    Prescaller_64_T0   = 3,
    Prescaller_256_T0  = 4,
    Prescaller_1024_T0 = 5,
    ExternalSource_FallingEdge_T0 = 6,
    ExternalSource_RisingEdge_T0  = 7
} Prescaller_t;

typedef enum
{
    Normal_Mode,
    PWM_PhaseCorrect_Mode,
    CTC_Mode,
    PWM_FastPWM
} WaveForm_Modes_t;

void Timer0_voidInit(WaveForm_Modes_t mode, Prescaller_t Prescaller);
u8   Timer0_u8_my_delay_ms_OVF(u16 ms);
u8   Timer0_u8_my_delay_ms_CTC(u16 ms);
void Timer0_voidSetCompareValue(u8 CompareValue);
void Timer0_voidSet_OVF_CallBack(void (*Timer0_CallBack)(void));
void Timer0_voidSet_CTC_CallBack(void (*Timer0_CallBack)(void));
void Timer0_voidEnableTimer(void);
void Timer0_voidDisableTimer(void);

#endif