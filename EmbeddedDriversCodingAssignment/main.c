#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/Timer1/Timer1_Interface.h"
#include "MCAL/Timer1/Timer1_Private.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"

void TogglePin()
{
    TOG_BIT(DIO_u8_DDRB_REG,DIO_PIN0);

}

int main(void)
{
    
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN0, DIO_OUTPUT);
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_HIGH);


    EXTI_voidSetCallBackFunction(EXTI_0,TogglePin);
    EXTI_voidInit(EXTI_0,Failling_Edge1_0);



    while (1)
    {
        
    }

    return 0;
}