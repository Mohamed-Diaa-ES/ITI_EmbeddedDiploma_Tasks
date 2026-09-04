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

    if ((count++) % 2)
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

    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN0, DIO_OUTPUT);
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_HIGH);

    Timer1_voidSet_OVE_CallBack(TogglePin);
    Timer1_u8Init(PWM_FastPWM, Prescaller_8);
    Timer1_SetICR(1999u);

    GIE_Enable();
    SET_BIT(SREG_Reg, 7); 



    while (1)
    {
        
    }

    return 0;
}