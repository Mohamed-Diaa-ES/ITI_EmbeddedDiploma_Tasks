#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include <util/delay.h>

int main(void)
{
   
      //  UpperCase 'M'
    const u8 UpperCase_M[8] = {
        0b10001,  
        0b11011,  
        0b10101, 
        0b10001,  
        0b10001,  
        0b10001,  
        0b10001,  
        0b00000   
    };

    //  lowercase 'm'
    const u8 LowerCase_m[8] = {
        0b00000,  
        0b00000,  
        0b11010,  
        0b10101, 
        0b10101, 
        0b10101,  
        0b10101, 
        0b00000   
    };


    LCD_voidInit();

    //first block  first row first column
    LCD_voidSendSpecialCharecter(0, UpperCase_M, 0, 0);
    
    
    //Second block  Second row first column
    LCD_voidSendSpecialCharecter(1, LowerCase_m, 0, 1);

    while (1)
    {
        // Infinite loop to keep the microcontroller running
    }
    
    return 0;
}