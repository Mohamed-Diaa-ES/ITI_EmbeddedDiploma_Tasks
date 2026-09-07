/**
 * @file    EXTI_Interface.h
 * @brief   This shows the interface and the APIs of the EXTI that can Sense the signals
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */

#ifndef _EXTI_Interface_H
#define _EXTI_Interface_H

typedef enum
{
    EXTI_0,
    EXTI_1,
    EXTI_2
} EXTI_Numbers_t;

#define EXTI0_DIO_Pin   DIO_PIN2

#define EXTI1_DIO_Pin   DIO_PIN3

#define EXTI2_DIO_Pin   DIO_PIN2

#define EXTI0_DIO_Port  DIO_PORTD

#define EXTI1_DIO_Port  DIO_PORTD

#define EXTI2_DIO_Port  DIO_PORTB

void EXTI_voidInit(EXTI_Numbers_t EXTI_Number, u8 SourceControl);
void EXTI_Enable(EXTI_Numbers_t EXTI_Number);
void EXTI_Disable(EXTI_Numbers_t EXTI_Number);

inline void EXTI_voidChangeSourceControl(EXTI_Numbers_t EXTI_Number, u8 SourceControl);
void EXTI_voidSetCallBackFunction(EXTI_Numbers_t EXTI_Number, void (*EXTI_CallBack)(void));

#endif