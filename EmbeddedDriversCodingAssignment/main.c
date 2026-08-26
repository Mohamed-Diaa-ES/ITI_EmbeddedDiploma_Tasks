#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include <util/delay.h>
#include "HAL/KPD/KPD_Interface.h"
#include "HAL/7SegDriver/Seven_Seg_Interface.h"
int main(void)
{
   LCD_voidInit();

   KPD_voidInit();
   u8 val = KPD_u8GetKey();
   
   SSD_voidInitialDataPort();
   while (1)
   {
        val = KPD_u8GetKey();
        if (val!=0)
        {
            SSD_voidSendNumber(val-'0');
        }
        
    }
    
    return 0;
}