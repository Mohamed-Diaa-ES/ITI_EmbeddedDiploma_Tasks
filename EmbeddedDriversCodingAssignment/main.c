#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/Timer1/Timer1_Interface.h"
#include "MCAL/Timer1/Timer1_Private.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"

void TogglePin()
{
    static volatile int count = 0;

    if ((count++) % 2)
    {
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN1, DIO_LOW);
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_HIGH);
    }else
    {
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_LOW);
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN1, DIO_HIGH);
    }
}

int main(void)
{

    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN0, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_LOW);
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN1, DIO_HIGH);

    EXTI_voidSetCallBackFunction(EXTI_0, TogglePin);
    EXTI_voidInit(EXTI_0, Rising_Edge1_0);
    DIO_voidSetPinValue(EXTI0_DIO_Port, EXTI0_DIO_Pin, DIO_HIGH);

    while (1)
    {
    }

    return 0;
}