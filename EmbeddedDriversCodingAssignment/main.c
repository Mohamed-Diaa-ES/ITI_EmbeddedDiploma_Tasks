#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/Timer0/Timer0_Interface.h"

int main(void)
{
    ADC_voidInit();
    DIO_voidSetPortDirection(DIO_PORTB, ALL_OUTPUT);
    DIO_voidSetPortValue(DIO_PORTB, ALL_OUTPUT);



    while (1)
    {


    }

    return 0;
}