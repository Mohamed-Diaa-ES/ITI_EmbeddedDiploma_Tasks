#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timer0_Interface.h"
#include "Timer0_Private.h"
#include "Timer0_Config.h"

static volatile u32 OVerFlowCounting = 0;
static volatile u32 CTC_Counting = 0;

static WaveForm_Modes_t Timer0_CurrentMode = Normal_Mode;
static Prescaller_t Timer0_CurrentPrescaler = No_Clock_Source;

static void (*Timer0_CallBack_OVF)(void) = NULL;
static void (*Timer0_CallBack_CTC)(void) = NULL;

void Timer0_voidInit(WaveForm_Modes_t mode, Prescaller_t Prescaller)
{
    Timer0_CurrentMode = mode;
    Timer0_CurrentPrescaler = Prescaller;

    // Reset TCCR0
    TCCR0_Reg = 0x00;

    switch (mode)
    {
    case Normal_Mode:
        CLR_BIT(TCCR0_Reg, WGM00_Bit);
        CLR_BIT(TCCR0_Reg, WGM01_Bit);
        break;
    case PWM_PhaseCorrect_Mode:
        SET_BIT(TCCR0_Reg, WGM00_Bit);
        CLR_BIT(TCCR0_Reg, WGM01_Bit);
        break;
    case CTC_Mode:
        CLR_BIT(TCCR0_Reg, WGM00_Bit);
        SET_BIT(TCCR0_Reg, WGM01_Bit);
        break;
    case PWM_FastPWM:
        SET_BIT(TCCR0_Reg, WGM00_Bit);
        SET_BIT(TCCR0_Reg, WGM01_Bit);
        break;
    }

    // Set clock source directly using enum bit value
    TCCR0_Reg = (TCCR0_Reg & Prescaller_ClearingMask) | (Prescaller & Prescaller_SetMask);
}

u8 Timer0_u8_my_delay_ms_OVF(u16 ms)
{
    if (ms == 0U || Timer0_CurrentMode != Normal_Mode)
    {
        return Fail;
    }

    OVerFlowCounting = ms;

    TCNT0_Reg = TIMER0_TCNT0_1MS_PRELOAD_8MHZ_64;

    SET_BIT(TIFR_Reg, TOV0_Bit);
    SET_BIT(TIMSK_Reg, TOIE0_Bit);

    while (OVerFlowCounting != 0UL)
    {
    }

    CLR_BIT(TIMSK_Reg, TOIE0_Bit);
    return Success;
}

u8 Timer0_u8_my_delay_ms_CTC(u16 ms)
{
    if (ms == 0U || Timer0_CurrentMode != CTC_Mode)
    {
        return Fail;
    }

    CTC_Counting = ms;

    OCR0_Reg = TIMER0_OCR0_1MS_COMPARE_8MHZ_64;
    TCNT0_Reg = 0U;

    SET_BIT(TIFR_Reg, OCF0_Bit);
    SET_BIT(TIMSK_Reg, OCIE0_Bit);

    while (CTC_Counting != 0UL)
    {
    }

    CLR_BIT(TIMSK_Reg, OCIE0_Bit);
    return Success;
}

void Timer0_voidSetCompareValue(u8 CompareValue)
{
    OCR0_Reg = CompareValue;
}

void Timer0_voidSet_OVF_CallBack(void (*Timer0_CallBack)(void))
{
    Timer0_CallBack_OVF = Timer0_CallBack;
}

void Timer0_voidSet_CTC_CallBack(void (*Timer0_CallBack)(void))
{
    Timer0_CallBack_CTC = Timer0_CallBack;
}

void Timer0_voidEnableTimer(void)
{
    TCCR0_Reg = (TCCR0_Reg & Prescaller_ClearingMask) | (Timer0_CurrentPrescaler & Prescaller_SetMask);
}

void Timer0_voidDisableTimer(void)
{
    TCCR0_Reg &= Prescaller_ClearingMask;
}

/* ISR CTC */
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    if (CTC_Counting > 0UL)
    {
        CTC_Counting--;
    }

    if (Timer0_CallBack_CTC != NULL)
    {
        Timer0_CallBack_CTC();
    }
}

/* ISR OVF */
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    // Reload preload for the next 1ms cycle
    TCNT0_Reg = TIMER0_TCNT0_1MS_PRELOAD_8MHZ_64;

    if (OVerFlowCounting > 0UL)
    {
        OVerFlowCounting--;
    }

    if (Timer0_CallBack_OVF != NULL)
    {
        Timer0_CallBack_OVF();
    }
}
