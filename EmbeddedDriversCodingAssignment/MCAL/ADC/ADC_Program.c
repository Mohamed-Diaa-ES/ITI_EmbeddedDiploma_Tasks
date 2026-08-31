/**
 * @file    ADC_Program.c
 * @brief   This is the implementation of the Driver APIs and Helper Function
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"
#include "ADC_Config.h"

void ADC_voidInit()
{
    SET_BIT(ADMUX_Reg, REFS0_Bit);
    CLR_BIT(ADMUX_Reg, REFS1_Bit);
    CLR_BIT(ADMUX_Reg, ADLAR_Bit);

    CLR_BIT(ADCSRA_Reg, ADATE_Bit);
    ADCSRA_Reg &= ADC_PrescallerBitsClear_Mask;
    ADCSRA_Reg |= PrescallerValue;
    SET_BIT(ADCSRA_Reg, ADEN_Bit);
}

void ADC_voidEnable()
{
    SET_BIT(ADCSRA_Reg, ADEN_Bit);
}

void ADC_voidDisable()
{
    CLR_BIT(ADCSRA_Reg, ADEN_Bit);
}

ADC_Status_Codes_t ADC_u8ConvertSynch(u8 channel, u16 *ReadData)
{
    if (channel > 32)
    {
        return Not_suitable_channel;
    }
    else if (ReadData == NULL)
    {
        return Error_Null_ReadingPtr;
    }

    ADMUX_Reg &= ADC_MuxChoiceClearMask;
    ADMUX_Reg |= channel;

    SET_BIT(ADCSRA_Reg, ADSC_Bit);
    while (GET_BIT(ADCSRA_Reg, ADIF_Bit) == FLAG_Is_DOWN)
        ;
    // clear the flag of the interrupt
    SET_BIT(ADCSRA_Reg, ADIF_Bit);

    if (GET_BIT(ADMUX_Reg, ADLAR_Bit) == 0)
    {
        *ReadData = ADCData_Reg;
    }
    else
    {
        *ReadData = ADCData_Reg >> 6;
    }
}
ADC_Status_Codes_t ADC_u8ConvertASynch(u8 channel, u16 *ReadData, void (*PtrFunc)(void))
{
}