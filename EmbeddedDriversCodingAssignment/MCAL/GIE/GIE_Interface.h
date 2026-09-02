/**
 * @file    GIE_Interface.h
 * @brief   This contains the interrupt pin Number and The enabler and disabler of the GIE
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */
#ifndef _GIE_Interface_H
#define _GIE_Interface_H
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#define SREG_Reg *((volatile u8 *)0x5F)
#define Interrupt_Pin 7
#define GIE_Enable() SET_BIT(SREG_Reg, Interrupt_Pin)
#define GIE_Disable() CLR_BIT(SREG_Reg, Interrupt_Pin)
#endif