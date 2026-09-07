#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/Timer1/Timer1_Interface.h"
#include "MCAL/Timer1/Timer1_Private.h"
#include "MCAL/GIE/GIE_Interface.h"

#define SPCR_Reg    *((volatile u8*)0x2D)
#define SPDR_Reg    *((volatile u8*)0x2F)
#define SPSR_Reg    *((volatile u8*)0x2E)
void SPI_MasterInit(void)
{
/* Set MOSI and SCK output, all others input */
    DIO_voidSetPortDirection(DIO_PORTA,0xA0);
/* Enable SPI, Master, set clock rate fck/16 */
SPCR_Reg = (1<<6)|(1<<4)|(1<<0);
}
void SPI_MasterTransmit(char cData)
{
/* Start transmission */
SPDR_Reg = cData;
/* Wait for transmission complete */
while(!(SPSR_Reg & (1<<7)))
;
}

void TogglePin()
{
    static volatile u8 count = 0;

    if ((count++) % 2)
    {
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_HIGH);
    }
    else
    {
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_LOW);
    }
}

int main(void)
{

    SPI_MasterInit();
    LCD_voidInit();
    u8 Result=0;
    while (1)
    {
        SPI_MasterTransmit('5');
        
    }

    return 0;
}