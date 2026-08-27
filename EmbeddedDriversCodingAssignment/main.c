#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include <util/delay.h>
#include "HAL/KPD/KPD_Interface.h"
#include "HAL/7SegDriver/Seven_Seg_Interface.h"
int main(void)
{

    // setting two pins to control the switch
    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);

    // setting pull up resistor to get the switch is pressed or not
    DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_INPUT);
    DIO_voidSetPinValue(DIO_PORTD, DIO_PIN0, DIO_HIGH);
    u8 PinPressed = 1;
    DIO_voidGetPinValue(DIO_PORTD, DIO_PIN0, &PinPressed);
    LCD_voidInit();
    LCD_voidSendData('5');
    while (1)
    {
        DIO_voidGetPinValue(DIO_PORTD, DIO_PIN0, &PinPressed);

        while (PinPressed == 0)
        {
            DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
            DIO_voidGetPinValue(DIO_PORTD, DIO_PIN0, &PinPressed);
        }
        DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
    }

    return 0;
}