#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/Timers/Timer_Interface.h"

int main(void)
{

    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_INPUT);
    DIO_voidSetPinValue(DIO_PORTD, DIO_PIN0, DIO_HIGH);

    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_HIGH);

    u8 val = 1;
    while (1)
    {
        DIO_voidGetPinValue(DIO_PORTD, DIO_PIN0, &val);
        if (val == 0)
        {
            _delay_ms(20);
            DIO_voidGetPinValue(DIO_PORTD, DIO_PIN0, &val);
            if (val == 0)
            {
                // Turn RL1 OFF first, then turn RL3 ON
                DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_LOW);
                _delay_ms(10);
                DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
            }
        }
        else
        {
            // Turn RL3 OFF first, then turn RL1 ON
            DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
            _delay_ms(10);
            DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_HIGH);
        }
    }

    return 0;
}