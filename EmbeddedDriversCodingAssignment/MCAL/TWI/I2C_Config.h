/**
 * @file     I2C_Config.h
 * @brief    I2C Configurable Info.
 */

#ifndef __I2C_CONFIG_H__
#define __I2C_CONFIG_H__

#include "I2C_Private.h"

/* Set to 8 MHz for ATmega32 */
#define F_CPU               8000000UL
#define SCL_Frequency       100000UL  /* 100KHZ */

#define TWI_PrescallerValue               PrescalerValue_1    
#define TWI_PrescallerRepresentation      Prescaler_1    

#define GeneralCall_Enabling   0

/* Software timeout loop count to prevent infinite blocking during bare-metal polling */
#define I2C_TIMEOUT_LOOPS      100000UL

#endif