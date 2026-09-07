/**
 * @file    EXTI_Program.c
 * @brief   This is the implementation of the Driver APIs and Helper Function
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../GIE/GIE_Interface.h"
#include "../DIO/DIO_Interface.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"

static void (*EXTI0_CallBack_GlobalSet)(void) = NULL;
static void (*EXTI1_CallBack_GlobalSet)(void) = NULL;
static void (*EXTI2_CallBack_GlobalSet)(void) = NULL;

void EXTI_voidInit(EXTI_Numbers_t EXTI_Number, u8 SourceControl)
{
    if (SourceControl > Rising_Edge1_0 || (EXTI_Number == EXTI_2 && SourceControl > Rising_Edge2))
        return;
    switch (EXTI_Number)
    {
    case EXTI_0:
        DIO_voidSetPinDirection(EXTI0_DIO_Port, EXTI0_DIO_Pin, DIO_INPUT);
        MCUCR_Reg = (MCUCR_Reg & EXTI0_SenseControl_ClearingMask) | (SourceControl<<ISC00);
        break;
    case EXTI_1:
        DIO_voidSetPinDirection(EXTI1_DIO_Port, EXTI1_DIO_Pin, DIO_INPUT);
        MCUCR_Reg = (MCUCR_Reg & EXTI1_SenseControl_ClearingMask) | (SourceControl<<ISC10);
        break;
    case EXTI_2:
        DIO_voidSetPinDirection(EXTI2_DIO_Port, EXTI2_DIO_Pin, DIO_INPUT);
        MCUCSR_Reg = (MCUCSR_Reg & EXTI2_SenseControl_ClearingMask) | (SourceControl<<ISC2);
        break;
    default:
        return;
        break;
    }
    if (!GET_BIT(SREG_Reg,Interrupt_Pin))
    {
            GIE_Enable();
    }
    

}
void EXTI_Enable(EXTI_Numbers_t EXTI_Number)
{

    switch (EXTI_Number)
    {
    case EXTI_0:
        SET_BIT(GICR_Reg, INT0);
        break;
    case EXTI_1:
        SET_BIT(GICR_Reg, INT1);
        break;
    case EXTI_2:
        SET_BIT(GICR_Reg, INT2);
        break;
    }
}
void EXTI_Disable(EXTI_Numbers_t EXTI_Number)
{

    switch (EXTI_Number)
    {
    case EXTI_0:
        CLR_BIT(GICR_Reg, INT0);
        break;
    case EXTI_1:
        CLR_BIT(GICR_Reg, INT1);
        break;
    case EXTI_2:
        CLR_BIT(GICR_Reg, INT2);
        break;
    }
}

inline void EXTI_voidChangeSourceControl(EXTI_Numbers_t EXTI_Number, u8 SourceControl)
{
    EXTI_voidInit(EXTI_Number, SourceControl);
}
void EXTI_voidSetCallBackFunction(EXTI_Numbers_t EXTI_Number, void (*EXTI_CallBack)(void))
{

    switch (EXTI_Number)
    {
    case EXTI_0:
        EXTI0_CallBack_GlobalSet = EXTI_CallBack;
        break;
    case EXTI_1:
        EXTI1_CallBack_GlobalSet = EXTI_CallBack;
        break;
    case EXTI_2:
        EXTI2_CallBack_GlobalSet = EXTI_CallBack;
        break;
    }
}
/**
 * ISR of EXTI 0
 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if (EXTI0_CallBack_GlobalSet != NULL)
    {
        EXTI0_CallBack_GlobalSet();
    }
    else
    {
        return;
    }
}
/**
 * ISR of EXTI 1
 */
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    if (EXTI1_CallBack_GlobalSet != NULL)
    {
        EXTI1_CallBack_GlobalSet();
    }
    else
    {
        return;
    }
}
/**
 * ISR of EXTI 2
 */
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    if (EXTI2_CallBack_GlobalSet != NULL)
    {
        EXTI2_CallBack_GlobalSet();
    }
    else
    {
        return;
    }
}