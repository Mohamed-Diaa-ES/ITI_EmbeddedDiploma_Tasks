#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"

#include "HAL/KPD_3X3/KPD3x3_Interface.h"
#include "HAL/7SegDriver/Seven_Seg_Interface.h"

void Led_Animation_Loading()
{
    DIO_voidSetPortValue(DIO_PORTA, 0xFF);

    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
    _delay_ms(100);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_LOW);
    _delay_ms(100);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN2, DIO_LOW);
    _delay_ms(100);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN3, DIO_LOW);
    _delay_ms(100);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN4, DIO_LOW);
    _delay_ms(100);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN5, DIO_LOW);
    _delay_ms(100);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN6, DIO_LOW);
    _delay_ms(100);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN7, DIO_LOW);
    _delay_ms(100);
}

void Led_Animation_OnAndOffThreeTimes()
{
    u8 All_On = 0xFF;
    for (int i = 0; i < 3; i++)
    {
        DIO_voidSetPortValue(DIO_PORTA, All_On);
        _delay_ms(100);
        All_On = ~All_On;
        DIO_voidSetPortValue(DIO_PORTA, All_On);
        _delay_ms(100);
        All_On = ~All_On;
        DIO_voidSetPortValue(DIO_PORTA, All_On);
        _delay_ms(100);
        All_On = ~All_On;
    }
}
void Led_Animation_FirstHalfOnAndOtherOff()
{
    u8 All_On = 0x0F;
    for (int i = 0; i < 3; i++)
    {
        DIO_voidSetPortValue(DIO_PORTA, All_On);
        _delay_ms(100);
        All_On = ~All_On;
        DIO_voidSetPortValue(DIO_PORTA, All_On);
        _delay_ms(100);
        All_On = ~All_On;
        DIO_voidSetPortValue(DIO_PORTA, All_On);
        _delay_ms(100);
        All_On = ~All_On;
    }
}
void Led_Animation_EachoneIsDifferntThanNextone()
{
    u8 All_On = 0xAA;
    for (int i = 0; i < 3; i++)
    {
        DIO_voidSetPortValue(DIO_PORTA, All_On);
        _delay_ms(100);
        All_On = ~All_On;
        DIO_voidSetPortValue(DIO_PORTA, All_On);
        _delay_ms(100);
        All_On = ~All_On;
        DIO_voidSetPortValue(DIO_PORTA, All_On);
        _delay_ms(100);
        All_On = ~All_On;
    }
}
void Led_Animation_GoToRightOnAndtoleftOff()
{

    DIO_voidSetPortValue(DIO_PORTA, 0x00);

    int i = 0;
    for (; i <= 7; i++)
    {
        DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0 + i, DIO_HIGH);
        _delay_ms(100);
    }
    for (; i >= 0; i--)
    {
        DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0 + i, DIO_LOW);
        _delay_ms(100);
    }
}

void LedsAnimationFunction(u8 KeyValue)
{
    switch (KeyValue - '0')
    {
    case 1:
        Led_Animation_Loading();
        break;
    case 2:
        Led_Animation_OnAndOffThreeTimes();
        break;
    case 3:
        Led_Animation_FirstHalfOnAndOtherOff();
        break;
    case 4:
        Led_Animation_EachoneIsDifferntThanNextone();
        break;
    case 5:
        Led_Animation_GoToRightOnAndtoleftOff();

        break;
    case 6: // I think the point is clear that I can do animation but ran out of animation
        break;
    case 7:// I think the point is clear that I can do animation but ran out of animation
        break;
    case 8:// I think the point is clear that I can do animation but ran out of animation
        break;
    case 9:// I think the point is clear that I can do animation but ran out of animation
        break;
    }
}
int main(void)
{

    DIO_voidSetPortDirection(DIO_PORTA, 0xFF);
    DIO_voidSetPortValue(DIO_PORTA, 0xFF);
    // DIO_voidSetPortDirection(DIO_PORTA, );
    KPD3x3_voidInit();
    u8 result = KPD3x3_u8GetKey();
    while (1)
    {
        result = KPD3x3_u8GetKey();
        LedsAnimationFunction(result);
    }

    return 0;
}