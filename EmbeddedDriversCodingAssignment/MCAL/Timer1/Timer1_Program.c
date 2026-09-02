/**
 * @file    Timer_Program.c
 * @brief   This is the implementation of the Driver APIs and Helper Function
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timer1_Interface.h"
#include "Timer1_Private.h"
#include "Timer1_Config.h"

static volatile u16 count_ms = 0;
static void (*Timer1_CallBack_GlobalSet)(void);
u8 Timer1_u8Init(u8 mode, u8 prescaller)
{
}
u8 Timer1_u8_my_delay_ms(u16 ms)
{
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

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    if (Timer1_CallBack_GlobalSet != NULL)
    {
        Timer1_CallBack_GlobalSet();
    }
}

u8 Timer1_u8SetAction(u8 Action)
{
}
u8 Timer1_SetICR(u16 Value)
{
    ICR1_Reg = Value;
}