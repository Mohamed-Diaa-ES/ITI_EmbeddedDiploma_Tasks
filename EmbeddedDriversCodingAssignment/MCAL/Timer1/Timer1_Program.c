#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timer1_Interface.h"
#include "Timer1_Private.h"

static volatile u32 s_timer1_20ms_ticks = 0;

u8 Timer1_u8Init(u8 mode, u8 prescaller)
{
    // Reset control registers
    TCCR1A_Reg = 0x00;
    TCCR1B_Reg = 0x00;

    switch (mode)
    {
    case PWM_FastPWM: // Assuming mapped to Mode 14 in your WaveForm_Modes_t
        // Fast PWM, TOP = ICR1 (WGM13:0 = 1110)
        CLR_BIT(TCCR1A_Reg, WGM10);
        SET_BIT(TCCR1A_Reg, WGM11);
        SET_BIT(TCCR1B_Reg, WGM12);
        SET_BIT(TCCR1B_Reg, WGM13);

        // Setup Non-Inverting PWM on OC1A (Clear on match, set at BOTTOM)
        SET_BIT(TCCR1A_Reg, COM1A1);
        CLR_BIT(TCCR1A_Reg, COM1A0);

        // Set deterministic TOP value
        ICR1_Reg = TIMER1_ICR1_20MS_TOP;
        break;
    default:
        return False_Setting;
    }

    // Enable Overflow Interrupt
    SET_BIT(TIMSK_Reg, TOIE1);

    // Apply Prescaler
    TCCR1B_Reg = (TCCR1B_Reg & Prescaller_ClearingMask) | (prescaller & 0x07);

    return True_Setting;
}

/* Delay using the 20ms Fast PWM overflows */
u8 Timer1_u8_my_delay_ms(u16 ms)
{
    u32 start_time = s_timer1_20ms_ticks;
    u32 target_ticks = ms / 20U; // Convert ms to 20ms overflow counts

    if (target_ticks == 0)
        target_ticks = 1;

    while ((s_timer1_20ms_ticks - start_time) < target_ticks)
    {
        // Wait for interrupt to increment ticks
    }

    return True_Setting;
}

u8 Timer1_u8SetCompareValue(u16 CompareValue, u8 A_or_B)
{
    if (A_or_B == 1) // OCRA
    {
        OCR1A_Reg = CompareValue;
        return True_Setting;
    }
    return False_Setting;
}

/* Timer1 Overflow ISR (Triggers every 20ms in Mode 14) */
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
    s_timer1_20ms_ticks++;
}