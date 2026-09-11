#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/Timer1/Timer1_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"

int main(void)
{
    // OC1A is PD5 on Atmega32
    DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);

    Timer1_u8Init(PWM_FastPWM, Prescaller_8_T1);
    GIE_Enable();

    u16 current_angle_ticks;

    while (1)
    {
        // Sweep UP: 0 deg to 180 deg (inclusive)
        for (current_angle_ticks = TIMER1_SERVO_0_DEG_TICKS;
             current_angle_ticks <= TIMER1_SERVO_180_DEG_TICKS;
             current_angle_ticks += TIMER1_SERVO_10_DEG_STEP)
        {
            Timer1_u8SetCompareValue(current_angle_ticks, 1);
            Timer1_u8_my_delay_ms(1000);
        }

        // Sweep DOWN: 170 deg down to 10 deg (prevents 2-second hold at boundaries)
        for (current_angle_ticks = TIMER1_SERVO_180_DEG_TICKS - TIMER1_SERVO_10_DEG_STEP;
             current_angle_ticks > TIMER1_SERVO_0_DEG_TICKS;
             current_angle_ticks -= TIMER1_SERVO_10_DEG_STEP)
        {
            Timer1_u8SetCompareValue(current_angle_ticks, 1);
            Timer1_u8_my_delay_ms(1000);
        }
    }

    return 0;
}