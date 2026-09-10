// #include <stddef.h>
#include "FreeRTOS/FreeRTOS.h"
#include "FreeRTOS/task.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "HAL/LCD/LCD_Private.h"
#include "MCAL/DIO/DIO_Private.h"
#include "LIB/BIT_MATH.h"

void LCD1()
{
    u8 StringToSend2[] = "Hello I am task1";

    while (1)
    {
        {

            LCD_voidSendString(StringToSend2);
            vTaskDelay(100);   
        }
    }
}
void LCD2()
{

    u8 StringToSend2[] = "Hello I am task2";
    while (1)
    {
        
        LCD_voidSendString(StringToSend2);
        vTaskDelay(100);
    }
}

#define StackSize 400
int main(void)
{
    GIE_Enable();
    LCD_voidInit();
    xTaskCreate(&LCD1, NULL, StackSize, NULL, 4, NULL);
    xTaskCreate(&LCD2, NULL, StackSize, NULL, 4, NULL);

    vTaskStartScheduler();

    while (1)
        ;
    return 0;
}