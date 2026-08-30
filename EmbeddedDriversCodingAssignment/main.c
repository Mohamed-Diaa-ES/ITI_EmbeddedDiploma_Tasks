#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include <util/delay.h>
#include "HAL/KPD/KPD_Interface.h"
#include "HAL/7SegDriver/Seven_Seg_Interface.h"
int main(void)
{

    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_OUTPUT);

    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_HIGH);

    while (1)
    {
        _delay_ms(1000);
        DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
        DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_HIGH);
        _delay_ms(1000);
        DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_LOW);
        _delay_ms(1000);
        
        DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_LOW);
        DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);

    }

    return 0;
}