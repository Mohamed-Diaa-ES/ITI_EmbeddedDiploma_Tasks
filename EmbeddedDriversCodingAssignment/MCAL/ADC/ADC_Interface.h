/**
 * @file    ADC_Interface.h
 * @brief   This shows the interface and the APIs of the ADC that can Sense the signals
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */
#ifndef _ADC_Interface_H
#define _ADC_Interface_H

typedef enum
{
    Not_suitable_channel,
    Success_code_Synch,
    Success_code_ASynch,
    Fail_code_Synch,
    Fail_code_ASynch,
    Error_Null_ReadingPtr,
}ADC_Status_Codes_t;

void ADC_voidInit();

ADC_Status_Codes_t ADC_u8ConvertSynch(u8 channel,u16*ReadData);

// sets the call back fucntion that will be used
ADC_Status_Codes_t ADC_u8ConvertASynch(u8 channel,u16*ReadData,void (*PtrFunc)(void));

void ADC_voidEnable();
void ADC_voidDisable();

#endif