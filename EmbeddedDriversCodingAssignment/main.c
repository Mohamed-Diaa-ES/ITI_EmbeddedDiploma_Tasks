#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"



#include "HAL/KPD_3X3/KPD3x3_Interface.h"
#include "HAL/7SegDriver/Seven_Seg_Interface.h"

inline void Led_Animation_Loading()
{
    DIO_voidSetPortDirection(DIO_PORTA, 0xFF);
    for (int i = 0; i < 7; i++)
    {
        DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0 + i, DIO_HIGH);
        _delay_ms(1000);
    }
}

void LedsAnimationFunction(u8 KeyValue)
{
    switch (KeyValue)
    {
    case 1:
        Led_Animation_Loading();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    }
}
int main(void)
{

    DIO_voidSetPortDirection(DIO_PORTA, DIO_OUTPUT);
    KPD3x3_voidInit();
    u8 result = KPD3x3_u8GetKey();
    while (1)
    {
        result = KPD3x3_u8GetKey();
        LedsAnimationFunction(result);
    }

    return 0;
}