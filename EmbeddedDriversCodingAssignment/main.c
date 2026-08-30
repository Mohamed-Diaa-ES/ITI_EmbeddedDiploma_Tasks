#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"

#include "HAL/KPD_4X4/KPD4x4_Interface.h"

#include "HAL/KPD_3X3/KPD3x3_Interface.h"
#include "HAL/7SegDriver/Seven_Seg_Interface.h"

inline void Led_Animation_Loading()
{
    
    DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
} 

void LedsAnimationFunction(u8 KeyValue)
{
    switch()
    {

    }
}
int main(void)
{

    DIO_voidSetPortDirection(DIO_PORTA,DIO_OUTPUT);
    DIO_voidSetPortDirection(DIO_PORTA,DIO_OUTPUT);


    while (1)
    {

    }

    return 0;
}