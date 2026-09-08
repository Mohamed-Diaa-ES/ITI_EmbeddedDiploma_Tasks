#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/Timer1/Timer1_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/Timer1/Timer1_Config.h"

int main(void)
{
    // OC1A is PD5 on Atmega32. Configure it as OUTPUT.
    DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);
    
    Timer1_u8Init(PWM_FastPWM, Prescaller_8_T1);
    GIE_Enable();

    u16 current_angle_ticks = TIMER1_SERVO_0_DEG_TICKS;
    
    while (1)
    {
        // Increment by 10 degrees
        for (current_angle_ticks = TIMER1_SERVO_0_DEG_TICKS; 
             current_angle_ticks <= TIMER1_SERVO_180_DEG_TICKS; 
             current_angle_ticks += TIMER1_SERVO_10_DEG_STEP)
        {
            Timer1_u8SetCompareValue(current_angle_ticks, 1);
            Timer1_u8_my_delay_ms(1000); // 1-second deterministic delay
        }
        
        // Return to 0 degrees instantly
        Timer1_u8SetCompareValue(TIMER1_SERVO_0_DEG_TICKS, 1);
        Timer1_u8_my_delay_ms(1000); // Wait 1 second before restarting
    }

    return 0;
}