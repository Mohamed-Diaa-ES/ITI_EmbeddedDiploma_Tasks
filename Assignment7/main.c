
#include "MCAL/DIO/DIO_Interface.h"

#include <util/delay.h>

int main()
{
    DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
    DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_HIGH);

    while (1)
    {

    }
}