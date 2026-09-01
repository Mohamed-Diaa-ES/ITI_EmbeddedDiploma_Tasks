#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"

int main(void)
{

    DIO_voidSetPortDirection(DIO_PORTB, 0x07);
    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_INPUT);
    u8 channelToUse = 0x00;

    f32 onethird = 5 / 4;
    ADC_voidInit();
    u16 result_toBe;
    ADC_u8ConvertSynch(channelToUse, &result_toBe);
    f32 VoltageResult = result_toBe * 5 / 1024;

    while (1)
    {
        if (VoltageResult < onethird)
        {
            DIO_voidSetPortValue(DIO_PORTB, 0x00);
        }
        else if (VoltageResult < onethird * 2)
        {
            DIO_voidSetPortValue(DIO_PORTB, 0x01);
        }
        else if (VoltageResult < onethird * 3)
        {
            DIO_voidSetPortValue(DIO_PORTB, 0x03);
        }
        else 
        {
            DIO_voidSetPortValue(DIO_PORTB, 0x07);
        }
        _delay_ms(2000);
        ADC_u8ConvertSynch(channelToUse, &result_toBe);
         VoltageResult = result_toBe * 5 / 1024;
    }

    return 0;
}