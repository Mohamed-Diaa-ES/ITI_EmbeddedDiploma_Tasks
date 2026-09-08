#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/Timer0/Timer0_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"

static void Motor_CW(void)
{
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_HIGH);
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN1, DIO_LOW);
}

static void Motor_CCW(void)
{
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_LOW);
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN1, DIO_HIGH);
}

static void Motor_Stop(void)
{
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN0, DIO_LOW);
    DIO_voidSetPinValue(DIO_PORTB, DIO_PIN1, DIO_LOW);
}

int main(void)
{
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN0, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);
    Motor_Stop();

    // Enable Global Interrupts
    GIE_Enable();

    // --- Phase 1: Normal / OVF Mode ---
    Timer0_voidInit(Normal_Mode, Prescaller_64);
    Motor_CW();
    Timer0_u8_my_delay_ms_OVF(5000);
    Motor_CCW();
    Timer0_u8_my_delay_ms_OVF(3000);
    Motor_Stop();
    Timer0_u8_my_delay_ms_OVF(5000);

    // --- Phase 2: CTC Mode ---
    Timer0_voidInit(CTC_Mode, Prescaller_64);
    Motor_CW();
    Timer0_u8_my_delay_ms_CTC(5000);
    Motor_CCW();
    Timer0_u8_my_delay_ms_CTC(3000);
    Motor_Stop();
    Timer0_u8_my_delay_ms_CTC(5000);

    while (1)
    {
    }

    return 0;
}