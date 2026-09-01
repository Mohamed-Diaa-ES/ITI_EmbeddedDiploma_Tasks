/**
 * @file    Timer_Program.c
 * @brief   This is the implementation of the Driver APIs and Helper Function
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timer_Interface.h"
#include "Timer_Private.h"
#include "Timer_Config.h"

static u16 count_ms=0;

u8 Timer0_u8Init()
{

    u8 Temp_Control = TCCR0_Reg;
    CLR_BIT(Temp_Control, WGM00);
    CLR_BIT(Temp_Control, WGM01);

    CLR_BIT(Temp_Control, COM00);
    CLR_BIT(Temp_Control, COM01);

    Temp_Control |= PrescallerValue;
}
u8 Timer0_u8_my_delay_ms(u16 ms)
{
    count_ms=ms;
    while (count_ms>0)
    {
        
    }
    

}
u8 Timer0_u8SetCompareValue(u16 ms)
{

}
void Timer0_voidSet_OVE_CallBack(void(*Timer0_CallBack))
{
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    if (count_ms >=0)
    {
        count_ms--;
    }
    
}