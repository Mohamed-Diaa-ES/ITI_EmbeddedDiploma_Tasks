/**
 * @file     I2C_Private.h
 * @brief    I2C Private info about the driver.
 */

#ifndef __I2C_PRIVATE_H__
#define __I2C_PRIVATE_H__

#include <stdint.h>

typedef enum
{
    TWIE_Bit,
    TWEN_Bit = 2,
    TWWC_Bit,
    TWSTO_Bit,
    TWSTA_Bit,
    TWEA_Bit,
    TWINT_Bit, 

} TWCR_Bits_t;

typedef enum
{
    TWPS0_Bit,
    TWPS1_Bit,
    TWS3_Bit = 3,
    TWS4_Bit,
    TWS5_Bit,
    TWS6_Bit,
    TWS7_Bit

} TWSR_Bits_t;

typedef enum
{
    PrescalerValue_1 = 1,
    PrescalerValue_4 = 4,
    PrescalerValue_16 = 16,
    PrescalerValue_64 = 64,

} TWIBitRatePrescalerRealValue_t;

typedef enum
{
    Prescaler_1,
    Prescaler_4,
    Prescaler_16,
    Prescaler_64,

} TWIBitRatePrescalerRepresention_t;

#define TWGCE_Bit 0 

#define Calculate_Value_TWI_Bit_Rate(CPU_ClockFrequency, SCL_Freq, Prescaller) ((uint8_t)((((CPU_ClockFrequency) / (SCL_Freq)) - 16) / (2 * (Prescaller))))

#define StatusCodeMask 0xF8 

#define START_ERROR_CodeCheck 0x08
#define REP_START_ERROR_CodeCheck 0x10
#define Slave_Write_Operation_Ack_Recieving_CodeCheck 0x18
#define Slave_Write_Operation_NotAck_Recieving_CodeCheck 0x20
#define SendingData_Ack_Recieving_CodeCheck 0x28
#define SendingData_NotAck_Recieving_CodeCheck 0x30
#define ARBITRATION_LOST_CodeCheck 0x38
#define Slave_Read_ACK_Recieving_CodeCheck 0x40
#define Slave_Read_NotACK_Recieving_CodeCheck 0x48
#define Data_byte_has_been_received_ACK 0x50
#define Data_byte_has_been_received_NACK 0x58

#define PrescallerMask 0x03
#define Global_Interrupt_Bit 7
#define Reserved_Addresses_Scheme 0x78
#define General_Call_InstructionAddress 0x00
#define StatusBitsValue (TWSR_Reg & StatusCodeMask)
#define Write_Command 0x00
#define Read_Command 0x01

#define Clearing_PrescallerBits() (TWSR_Reg &= ~PrescallerMask)

/**
 * @def     TWCR_Reg
 * @brief   The TWCR is used to control the operation of the TWI.
 */
#define TWCR_Reg (*((volatile uint8_t *)0x56))
/**
 * @def     TWDR_Reg
 * @brief   TWI Data Register
 */
#define TWDR_Reg (*((volatile uint8_t *)0x23))
/**
 * @def     TWAR_Reg
 * @brief   TWI (Slave) Address Register
 */
#define TWAR_Reg (*((volatile uint8_t *)0x22))
/**
 * @def     TWSR_Reg
 * @brief   TWI Status Register
 */
#define TWSR_Reg (*((volatile uint8_t *)0x21))
/**
 * @def     TWBR_Reg
 * @brief   TWBR selects the division factor for the bit rate generator.
 */
#define TWBR_Reg (*((volatile uint8_t *)0x20))

/**
 * @def     SREG_Reg
 * @brief   Status register
 */
#define SREG_Reg (*((volatile uint8_t *)0x5F))
#endif
