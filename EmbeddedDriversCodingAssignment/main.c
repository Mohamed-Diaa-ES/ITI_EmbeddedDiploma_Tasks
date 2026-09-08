#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/Timer0/Timer0_Interface.h"
#include "MCAL/Timer0/Timer0_Private.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"

void TogglePin()
{
    static volatile int count = 0;

    if (((count++)+1) % 2)
    {
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_HIGH);
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN1, DIO_LOW);
    }
    else
    {
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_LOW);
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN1, DIO_HIGH);
    }
}

int main(void)
{
    GIE_Enable();
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN0, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_LOW);
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN1, DIO_HIGH);

    mTIMER0_Init();

    while (1)
    {
        TogglePin();
        mTIMER0_Delay_ms(5000);
        TogglePin();
        mTIMER0_Delay_ms(3000);
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_LOW);
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN1, DIO_LOW);
        mTIMER0_Delay_ms(5000);
    }

    return 0;
}