

#ifndef __I2C_INTERFACE_H__
#define __I2C_INTERFACE_H__

#include <stdint.h>
#include "I2C_Private.h"
#include "../../Macros/Macros.h"


/**
 * @enum I2C_ErrorStatus_t
 * @brief Error and State Status Codes of the I2C system to Handle.
 */
typedef enum {
    I2C_OK = 0,               /** Success, operation completed. */                                       
    I2C_START_ERROR,          /** Failed to transmit START condition. */          
    I2C_REP_START_ERROR,      /** Failed to transmit repeated START condition. */              
    I2C_SLA_W_ACK_REC,        /** SLA+W transmitted, ACK received. */          
    I2C_SLA_W_NACK_REC,       /** SLA+W transmitted, NACK received. */          
    I2C_SLA_W_ERROR,          /** Unexpected hardware status during SLA+W transmission */          
    I2C_SLA_R_ACK_REC,        /** SLA+R transmitted, ACK received. */ 
    I2C_SLA_R_NACK_REC,       /** SLA+R transmitted, NACK received. */ 
    I2C_SLA_R_ERROR,          /** Unexpected hardware status during SLA+R transmission */          
    I2C_DATA_TX_ACK_REC,      /** Data byte transmitted, ACK received. */
    I2C_DATA_TX_NACK_REC,     /** Data byte transmitted, NACK received. */
    I2C_DATA_TX_ERROR,        /** Unexpected hardware status during data byte transmission */
    I2C_DATA_RX_ACK_SENT,     /** Data byte received, ACK returned. */
    I2C_DATA_RX_NACK_SENT,    /** Data byte received, NACK returned. */
    I2C_DATA_RX_ERROR,        /** Unexpected hardware status during data byte reception */
    I2C_ARBITRATION_LOST,     /** Arbitration lost */     
    I2C_TIMEOUT_ERROR,        /** Operation timed out. */ 
    I2C_INVALID_ADDRESS,      /** Invalid Slave Address */
    I2C_NULL_POINTER_ERROR    /** Null pointer passed as an argument. */

}I2C_ErrorStatus_t;

/** 
* @fn       I2C_InitMaster 
* @brief    Initializes the TWI hardware module for Master/Multi-Master operations.
* @param    own_address  The designated 7-bit address of the T-ECU on the bus.
* @return   void
*/
void I2C_InitMaster(uint8_t own_address);
/** 
* @fn       I2C_StartCondition 
* @brief    Sends the start Condition over the I2C bus and blocks until complete.
* @return   I2C_ErrorStatus_t 
*/
I2C_ErrorStatus_t I2C_StartCondition();

/** 
* @fn       I2C_RepeatedStart 
* @brief    Sends a Repeated Start Condition over the I2C bus and blocks until complete.
* @return   I2C_ErrorStatus_t 
*/
I2C_ErrorStatus_t I2C_RepeatedStart();
/** 
* @fn       I2C_StopCondition 
* @brief    Sends a Stop Condition over the I2C bus.
* @details  The ATmega128 does NOT set the TWINT flag after a STOP condition is sent,
*           therefore this function does not use interrupts or semaphores[cite: 2].
* @return   void
*/
void I2C_StopCondition();
/** 
* @fn       I2C_SendSlaveAddressWrite 
* @brief    Sends the 7-bit slave address with the Write bit (0) appended.
* @param    slave_address The 7-bit address of the target slave.
* @return   I2C_ErrorStatus_t 
*/
I2C_ErrorStatus_t I2C_SendSlaveAddressWrite(uint8_t slave_address);
/** 
/** 
* @fn       I2C_SendSlaveAddressRead 
* @brief    Sends the 7-bit slave address with the Read bit (1) appended.
* @param    slave_address The 7-bit address of the target slave.
* @return   I2C_ErrorStatus_t 
*/
I2C_ErrorStatus_t I2C_SendSlaveAddressRead(uint8_t slave_address);
/** 
* @fn       I2C_WriteByte 
* @brief    Sends a single byte of data over the I2C bus.
* @param    data The byte to transmit.
* @return   I2C_ErrorStatus_t 
*/
I2C_ErrorStatus_t I2C_WriteByte(uint8_t data);
/** 
* @fn       I2C_ReadByteAck 
* @brief    Receives a byte of data and responds with an ACK (Acknowledge).
* @param    data Pointer to store the received byte.
* @return   I2C_ErrorStatus_t 
*/
I2C_ErrorStatus_t I2C_ReadByteAck(uint8_t *data);
/** 
* @fn       I2C_ReadByteNack 
* @brief    Receives a byte of data and responds with a NACK (Not Acknowledge).
* @param    data Pointer to store the received byte.
* @return   I2C_ErrorStatus_t 
*/
I2C_ErrorStatus_t I2C_ReadByteNack(uint8_t *data);
#endif