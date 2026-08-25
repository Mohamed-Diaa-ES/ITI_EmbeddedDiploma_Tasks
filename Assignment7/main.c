#include <stdint.h>
#include "registerSummary.h"
#define High 1
#define Low 0
#define Output 1
#define Input 0
#define SetBit(Reg, Bit) Reg |= (1 << Bit)
#define ClearBit(Reg, Bit) Reg &= ~(1 << Bit)
#include <util/delay.h>

int main()
{
    int i;
    for (i = 0; i < 8; i++)
    {
        Pin_Mode(&DDRB_Reg, i, Output);
    }

    while (1)
    {
        for (i = 0; i < 8; i++)
        {
                  digital_write(&PORTB_Reg, i,High);
                  _delay_ms(300);
        }
  
    }
}