#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/Timers/Timer_Interface.h"

int main(void)
{
    ADC_voidInit();
    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_INPUT);
    DIO_voidSetPortDirection(DIO_PORTB, ALL_OUTPUT);

    f32 Voltage_Ref_Val = 5;
    u8 Channel = 0;
    u16 ADC_Reading = 0;

    while (1)
    {
        ADC_u8ConvertSynch(Channel, &ADC_Reading);
        f32 VoltageResult = ADC_f32TransformToVoltage(ADC_Reading);

        for (int i = 1; i <= 3; i++)
        {
            if( (((VoltageResult > Voltage_Ref_Val * i / 3.0) ||(VoltageResult-1)>=3) ))
            {
                DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0 + (i - 1), DIO_HIGH);
            }
            else
            {
                DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0 + (i - 1), DIO_LOW);
                break;
            }
        }
    }

    return 0;
}