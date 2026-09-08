#ifndef _Timer_Config_H
#define _Timer_Config_H

#define CPU_F 8000000UL // Set your system clock frequency

#define Fail    0
#define Success 1

/*
 * Deterministic 1 ms timebase:
 * At 8 MHz with Prescaler 64:
 * 1 tick = 64 / 8,000,000 = 8 us
 * 1 ms (1000 us) = 125 ticks
 *
 * CTC Mode: OCR0 = 124 (counts 0 to 124 = 125 ticks -> exactly 1 ms)
 * Normal Mode (OVF): Preload TCNT0 = (256 - 125) = 131 every interrupt -> exactly 1 ms
 */
#define TIMER0_TCNT0_1MS_PRELOAD_8MHZ_64   (256U - 125U) // 131
#define TIMER0_OCR0_1MS_COMPARE_8MHZ_64    (124U)

#endif