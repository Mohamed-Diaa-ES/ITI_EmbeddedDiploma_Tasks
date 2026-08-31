/**
 * @file    ADC_Private.h
 * @brief   This shows The private macros to be not changed and adddresses in memory
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */
#ifndef _ADC_Private_H
#define _ADC_Private_H

typedef enum
{
    MUX0_Bit,
    MUX1_Bit,
    MUX2_Bit,
    MUX3_Bit,
    MUX4_Bit,
    ADLAR_Bit,
    REFS0_Bit,
    REFS1_Bit,
} ADCMUX_Bits_t;
typedef enum
{
    ADPS0_Bit,
    ADPS1_Bit,
    ADPS2_Bit,
    ADIE_Bit,
    ADIF_Bit,
    ADATE_Bit,
    ADSC_Bit,
    ADEN_Bit,
} ADCSRA_Bits_t;

typedef enum
{
    AREF_Internal_Off,
    AVCC_Ex_Cap,
    Reserved,
    Internal_EX_Cap,
} Voltage_Refernce_Modes_t;

typedef enum
{
    DivisionFactor_2,
    DivisionFactor_2_Again,
    DivisionFactor_4,
    DivisionFactor_8,
    DivisionFactor_16,
    DivisionFactor_32,
    DivisionFactor_64,
    DivisionFactor_128,
} ADC_Prescaller_Choices_t;

#define ADC_PrescallerBitsClear_Mask 0xF8

#define ADC_MuxChoiceClearMask 0xE0

#define FLAG_Is_DOWN    0
#define ADMUX_Reg *((volatile u8 *)0x27)
#define ADCSRA_Reg *((volatile u8 *)0x26)

#define ADCData_Reg *((volatile u16 *)0x24)
#define SFIOR_Reg *((volatile u8 *)0x50)
#endif