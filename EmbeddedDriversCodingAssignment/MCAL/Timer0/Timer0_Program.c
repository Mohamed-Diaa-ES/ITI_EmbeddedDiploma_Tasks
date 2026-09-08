/**
 * @file    Timer_Program.c
 * @brief   This is the implementation of the Driver APIs and Helper Function
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Macros/Macros.h"
#include "Timer0_Interface.h"
#include "Timer0_Private.h"
#include "Timer0_Config.h"

static volatile u32 OVerFlowCounting = 0;
static volatile u32 CTC_Counting = 0;
static Timer_Configuration_t Timer_ModeAndPrescaller;
static void (*Timer0_CallBack_OVF)(void) = NULL;

static void (*Timer0_CallBack_CTC)(void) = NULL;

void Timer0_voidInit(WaveForm_Modes_t mode, Prescaller_t Prescaller)
{
    if (mode == Normal_Mode)
    {
        Timer_ModeAndPrescaller.mode = mode;
        CLR_BIT(TCCR0_Reg, WGM00_Bit);
        CLR_BIT(TCCR0_Reg, WGM01_Bit);
    }
    else if (mode == PWM_PhaseCorrect_Mode)
    {
        Timer_ModeAndPrescaller.mode = mode;
        SET_BIT(TCCR0_Reg, WGM00_Bit);
        CLR_BIT(TCCR0_Reg, WGM01_Bit);
    }
    else if (mode == CTC_Mode)
    {
        Timer_ModeAndPrescaller.mode = mode;
        CLR_BIT(TCCR0_Reg, WGM00_Bit);
        SET_BIT(TCCR0_Reg, WGM01_Bit);
    }
    else if (mode == PWM_FastPWM)
    {
        Timer_ModeAndPrescaller.mode = mode;
        SET_BIT(TCCR0_Reg, WGM00_Bit);
        SET_BIT(TCCR0_Reg, WGM01_Bit);
    }
    else // timer mode out of range
    {
    }
    switch (Prescaller)
    {
    case No_Clock_Source:
        Timer_ModeAndPrescaller.Prescaller = No_Clock_Source_Value;
        break;
    case Prescaller_1:
        Timer_ModeAndPrescaller.Prescaller = Prescaller_1_Value;
        break;
    case Prescaller_8:
        Timer_ModeAndPrescaller.Prescaller = Prescaller_8_Value;
        break;
    case Prescaller_64:
        Timer_ModeAndPrescaller.Prescaller = Prescaller_64_Value;
        break;
    case Prescaller_256:
        Timer_ModeAndPrescaller.Prescaller = Prescaller_256_Value;
        break;
    case Prescaller_1024:
        Timer_ModeAndPrescaller.Prescaller = Prescaller_1024_Value;
        break;
    case ExternalSource_FallingEdge:
        Timer_ModeAndPrescaller.Prescaller = ExternalSource_FallingEdge_Value;
        break;
    case ExternalSource_RisingEdge:
        Timer_ModeAndPrescaller.Prescaller = ExternalSource_RisingEdge_Value;
        break;
    default:
        return;
    }
    TCCR0_Reg = (TCCR0_Reg & Prescaller_ClearingMask) | ((Prescaller_SetMask & Prescaller) << CS00_Bit);
}
u8 Timer0_u8_my_delay_ms_OVF(u16 ms)
{
    u32 required_ticks;
    u32 full_overflows;
    u32 remaining_ticks;
    u32 prescaler;
    u32 denominator;

    if ((ms == 0U) || (Timer_ModeAndPrescaller.Prescaller == 0UL))
    {
        return Fail;
    }

    required_ticks = TIMER0_REQUIRED_TICKS_MS(ms, Timer_ModeAndPrescaller.Prescaller);

    if (required_ticks == 0UL)
    {
        required_ticks = 1UL;
    }

    full_overflows = required_ticks / Timer0_Overflow_Value;
    remaining_ticks = required_ticks % Timer0_Overflow_Value;

    if (remaining_ticks != 0UL)
    {
        TCNT0_Reg = (u8)(Timer0_Overflow_Value - remaining_ticks);
        OVerFlowCounting = full_overflows + 1UL;
    }
    else
    {
        TCNT0_Reg = 0U;
        OVerFlowCounting = full_overflows;
    }

    SET_BIT(TIMSK_Reg, TOIE0_Bit);

    while (OVerFlowCounting != 0UL)
    {
    }

    CLR_BIT(TIMSK_Reg, TOIE0_Bit);

    return Success;
}
u8 Timer0_u8_my_delay_us_OVF(u16 us)
{
    u32 required_ticks;
    u32 full_overflows;
    u32 remaining_ticks;
    u32 prescaler;
    u32 denominator;

    if ((us == 0U) || (Timer_ModeAndPrescaller.Prescaller == 0UL))
    {
        return Fail;
    }

    required_ticks = TIMER0_REQUIRED_TICKS_US(us, Timer_ModeAndPrescaller.Prescaller);

    if (required_ticks == 0UL)
    {
        required_ticks = 1UL;
    }

    full_overflows = required_ticks / Timer0_Overflow_Value;
    remaining_ticks = required_ticks % Timer0_Overflow_Value;

    if (remaining_ticks != 0UL)
    {
        TCNT0_Reg = (u8)(Timer0_Overflow_Value - remaining_ticks);
        OVerFlowCounting = full_overflows + 1UL;
    }
    else
    {
        TCNT0_Reg = 0U;
        OVerFlowCounting = full_overflows;
    }

    SET_BIT(TIMSK_Reg, TOIE0_Bit);

    while (OVerFlowCounting != 0UL)
    {
    }

    CLR_BIT(TIMSK_Reg, TOIE0_Bit);

    return Success;
}
void Timer0_voidActionTimer(u8 mode, u8 Action)
{
    if ((mode == PWM_FastPWM || mode == PWM_PhaseCorrect_Mode) && Action == RESERVED_DO_NOT_USE)
    {
        return;
    }

    TCCR0_Reg = (TCCR0_Reg & Action_ClearingMask) | ((Action_SetMask & Action) << COM00_Bit);
}
u8 Timer0_u8_my_delay_ms_CTC(u16 ms)
{
    u32 required_ticks;
    u32 compare_count;
    u32 ticks_per_compare;

    if ((ms == 0U) ||
        (Timer_ModeAndPrescaller.Prescaller == 0UL) ||
        (Timer_ModeAndPrescaller.mode != CTC_Mode))
    {
        return Fail;
    }

    required_ticks = TIMER0_REQUIRED_TICKS_MS(
        ms,
        Timer_ModeAndPrescaller.Prescaller);

    if (required_ticks == 0UL)
    {
        required_ticks = 1UL;
    }

    compare_count =
        (required_ticks + Timer0_Overflow_Value - 1UL) /
        Timer0_Overflow_Value;

    ticks_per_compare =
        (required_ticks + compare_count - 1UL) /
        compare_count;

    OCR0_Reg = (u8)(ticks_per_compare - 1UL);
    TCNT0_Reg = 0U;
    CTC_Counting = compare_count;

    SET_BIT(TIFR_Reg, OCF0_Bit);
    SET_BIT(TIMSK_Reg, OCIE0_Bit);

    while (CTC_Counting != 0UL)
    {
    }

    CLR_BIT(TIMSK_Reg, OCIE0_Bit);

    return Success;
}
u8 Timer0_u8_my_delay_us_CTC(u16 us)
{
    u32 required_ticks;
    u32 compare_count;
    u32 ticks_per_compare;

    if ((us == 0U) ||
        (Timer_ModeAndPrescaller.Prescaller == 0UL) ||
        (Timer_ModeAndPrescaller.mode != CTC_Mode))
    {
        return Fail;
    }

    required_ticks = TIMER0_REQUIRED_TICKS_US(
        us,
        Timer_ModeAndPrescaller.Prescaller);

    if (required_ticks == 0UL)
    {
        required_ticks = 1UL;
    }

    compare_count =
        (required_ticks + Timer0_Overflow_Value - 1UL) /
        Timer0_Overflow_Value;

    ticks_per_compare =
        (required_ticks + compare_count - 1UL) /
        compare_count;

    OCR0_Reg = (u8)(ticks_per_compare - 1UL);
    TCNT0_Reg = 0U;
    CTC_Counting = compare_count;

    SET_BIT(TIFR_Reg, OCF0_Bit);
    SET_BIT(TIMSK_Reg, OCIE0_Bit);

    while (CTC_Counting != 0UL)
    {
    }

    CLR_BIT(TIMSK_Reg, OCIE0_Bit);

    return Success;
}

u8 Timer0_u8SetCompareValue(u8 CompareValue)
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

void __vector_10(void) __attribute__((signal));

void __vector_10(void)
{
    if (Timer_ModeAndPrescaller.mode == CTC_Mode)
        CTC_Counting--;

    if (Timer0_CallBack_CTC != NULL)
    {
        Timer0_CallBack_CTC();
    }
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    if (OVerFlowCounting > 0UL)
    {
        OVerFlowCounting--;
    }

    if (Timer0_CallBack_OVF != NULL)
    {
        Timer0_CallBack_OVF();
    }
}

void Timer0_voidEnableTimer()
{
    TCCR0_Reg = (TCCR0_Reg & Prescaller_ClearingMask) | ((Prescaller_SetMask & Timer_ModeAndPrescaller.Prescaller) << CS00_Bit);
}

void Timer0_voidDisableTimer()
{
    TCCR0_Reg &= Prescaller_ClearingMask;
}