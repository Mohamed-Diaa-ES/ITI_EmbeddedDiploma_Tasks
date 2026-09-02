/**
 * @file    Timer_Program.c
 * @brief   This is the implementation of the Driver APIs and Helper Function
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timer0_Interface.h"
#include "Timer0_Private.h"
#include "Timer0_Config.h"

static volatile u16 count_ms=0;
static void(*Timer0_CallBack_GlobalSet)(void);
u8 Timer0_u8Init()
{

    u8 Temp_Control = TCCR0_Reg;
    CLR_BIT(Temp_Control, WGM00);
    CLR_BIT(Temp_Control, WGM01);

    CLR_BIT(Temp_Control, COM00);
    CLR_BIT(Temp_Control, COM01);
    SET_BIT(TIMSK_Reg,TOIE0);
    Temp_Control |= PrescallerValue;
    TCCR0_Reg=Temp_Control;
    SET_BIT(SREG_Reg,Global_Interrupt_Pin);
    return 1;
}
u8 Timer0_u8_my_delay_ms(u16 ms)
{
    count_ms=ms;
    while (count_ms>0)
    {
        
    }
    return 1;

}
u8 Timer0_u8SetCompareValue(u8 CompareValue)
{
    OCR0_Reg=CompareValue;
    return 1;
}
void Timer0_voidSet_OVE_CallBack(void(*Timer0_CallBack)(void))
{
    Timer0_CallBack_GlobalSet=Timer0_CallBack;
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    if (count_ms > 0)
    {
        count_ms--;
    }
    
}