#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timer1_Interface.h"
#include "Timer1_Private.h"
#include "Timer1_Config.h"
#include <stddef.h> // Included for NULL definition

static volatile u16 count_ms = 0;
static void (*Timer1_CallBack_GlobalSet)(void) = NULL;

u8 Timer1_u8Init(u8 mode, u8 prescaller)
{
    TCCR1B_Reg = (TCCR1B_Reg & Prescaller_ClearingMask) | (prescaller & 0x07);

    switch (mode)
    {
    case Normal_Mode:
        CLR_BIT(TCCR1A_Reg, WGM10);
        CLR_BIT(TCCR1A_Reg, WGM11);
        CLR_BIT(TCCR1B_Reg, WGM12);
        CLR_BIT(TCCR1B_Reg, WGM13);
        TCNT1_Reg = Preloaded_Value_For_1ms;
        break;
    case PWM_PhaseCorrect_ICR1:
        CLR_BIT(TCCR1A_Reg, WGM10);
        SET_BIT(TCCR1A_Reg, WGM11);
        CLR_BIT(TCCR1B_Reg, WGM12);
        SET_BIT(TCCR1B_Reg, WGM13);
        break;
    case CTC_ICR1:
        CLR_BIT(TCCR1A_Reg, WGM10);
        CLR_BIT(TCCR1A_Reg, WGM11);
        SET_BIT(TCCR1B_Reg, WGM12);
        SET_BIT(TCCR1B_Reg, WGM13);
        break;
    case PWM_FastPWM:
        CLR_BIT(TCCR1A_Reg, WGM10);
        SET_BIT(TCCR1A_Reg, WGM11);
        SET_BIT(TCCR1B_Reg, WGM12);
        SET_BIT(TCCR1B_Reg, WGM13);
        break;
    default:
        return False_Setting;
    }

    SET_BIT(TIMSK_Reg, TOIE1);
    return True_Setting; 
}

u8 Timer1_u8_my_delay_ms(u16 ms)
{
    
    return True_Setting; 
}

u8 Timer1_u8SetCompareValue(u16 CompareValue, u8 A_or_B)
{
    if (A_or_B == OCRA)
    {
        OCR1A_Reg = CompareValue;
        return True_Setting;
    }
    if (A_or_B == OCRB)
    {
        OCR1B_Reg = CompareValue;
        return True_Setting;
    }
    return False_Setting;
}

void Timer1_voidSet_OVE_CallBack(void (*Timer1_CallBack)(void))
{
    Timer1_CallBack_GlobalSet = Timer1_CallBack; 
}

void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
    TCNT1_Reg = Preloaded_Value_For_1ms;

    count_ms++;
    if (count_ms == 1000)
    {
        count_ms = 0;
        

        if (Timer1_CallBack_GlobalSet != NULL)
        {
            Timer1_CallBack_GlobalSet();
        }
    }
}

u8 Timer1_u8SetAction(u8 Action)
{
    CLR_BIT(TCCR1B_Reg,COM1B0);
    SET_BIT(TCCR1B_Reg,COM1B0);
    return True_Setting;
}

u8 Timer1_SetICR(u16 Value)
{
    ICR1_Reg = Value;
    return True_Setting; 
}