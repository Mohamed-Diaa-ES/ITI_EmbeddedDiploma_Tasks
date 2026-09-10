// #include <stddef.h>
#include "FreeRTOS/FreeRTOS.h"
#include "FreeRTOS/task.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "LIB/BIT_MATH.h"

void ToggFunc1()
{

    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_OUTPUT);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_HIGH);
    while (1)
    {
        vTaskDelay(500);
        TOG_BIT(DIO_u8_PORTA_REG, DIO_PIN1);
    }
}
void ToggFunc2()
{

    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN2, DIO_OUTPUT);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN2, DIO_HIGH);
    while (1)
    {
        vTaskDelay(1000);
        TOG_BIT(DIO_u8_PORTA_REG, DIO_PIN2);
    }
}
void ToggFunc3()
{
    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN3, DIO_OUTPUT);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN3, DIO_HIGH);
    while (1)
    {
        vTaskDelay(2000);
        TOG_BIT(DIO_u8_PORTA_REG, DIO_PIN3);
    }
}
#define StackSize 400
int main(void)
{

    xTaskCreate(&ToggFunc1, NULL, StackSize, NULL, 4, NULL);
    xTaskCreate(&ToggFunc2, NULL, StackSize, NULL, 4, NULL);
    xTaskCreate(&ToggFunc3, NULL, StackSize, NULL, 4, NULL);

    vTaskStartScheduler();
    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN4, DIO_OUTPUT);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN4, DIO_HIGH);
    while(1);
    return 0;
}