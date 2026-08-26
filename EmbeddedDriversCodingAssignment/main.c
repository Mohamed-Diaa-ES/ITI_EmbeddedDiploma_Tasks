
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/7SegDriver/Seven_Seg_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include <util/delay.h>

int main()
{
    LCD_voidInit();
    u8 stringTobeSent[20]="MohammedDiaa";
    for(int i=0;stringTobeSent[i]!='\0';i++)
    {
        LCD_voidSendData(stringTobeSent[i]);
        LCD_voidSendData('_');
    }
    while (1)
    {

    }
}