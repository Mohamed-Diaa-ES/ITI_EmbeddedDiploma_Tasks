
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/7SegDriver/Seven_Seg_Interface.h"
#include <util/delay.h>

int main()
{
    SSD_voidInitialDataPort();
    SSD_voidEnable();
    SSD_voidSendNumber(5);
    while (1)
    {

    }
}