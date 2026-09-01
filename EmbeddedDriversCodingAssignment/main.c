#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/Timers/Timer_Interface.h"

int main(void)
{

    Timer0_u8Init();
    ADC_voidInit();

    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_INPUT);

    f32 voltage_result = 0;
    f32 OneQuarter = 5 / 4;

    u16 adcReading = 0;

    while (1)
    {
        DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_HIGH);
        ADC_u8ConvertSynch(1, &adcReading);
        voltage_result = adcReading * 5. / 1024;

        if (voltage_result >= 5)
        {
            Timer0_u8_my_delay_ms(50*1);
        }
        else if (voltage_result >OneQuarter*3)
        {
            Timer0_u8_my_delay_ms(50*2);
        }
      
        else if (voltage_result > OneQuarter*2)
        {
            Timer0_u8_my_delay_ms(50*3);
        }else
        {
            Timer0_u8_my_delay_ms(50*4);

        }
      

            DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_LOW);
                    if (voltage_result >= 5)
        {
            Timer0_u8_my_delay_ms(50*1);
        }
        else if (voltage_result >OneQuarter*3)
        {
            Timer0_u8_my_delay_ms(50*2);
        }
      
        else if (voltage_result > OneQuarter*2)
        {
            Timer0_u8_my_delay_ms(50*3);
        }else
        {
            Timer0_u8_my_delay_ms(50*4);

        }
    }

    return 0;
}