#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/Timer1/Timer1_Interface.h"
#include "MCAL/Timer1/Timer1_Private.h"
#include "MCAL/GIE/GIE_Interface.h"
void TogglePin()
{
    static volatile u8 count = 0;

    if ((count++)%2)
    {
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_HIGH);
    
    }
    else
    {
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_LOW);
    }
}
int main(void)
{
    ADC_voidInit();

    GIE_Enable();
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN0, DIO_OUTPUT);
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_HIGH);

    Timer1_u8Init(Normal_Mode, Prescaller_8);
    Timer1_voidSet_OVE_CallBack(TogglePin);
    SET_BIT(SREG_Reg,7);
    while (!GET_BIT(TIMSK_Reg,TOV1))
    {
        /* code */
    }
    

    while (1)
    {
        // TogglePin();
    }

    return 0;
}