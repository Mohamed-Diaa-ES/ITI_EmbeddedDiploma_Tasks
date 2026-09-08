/**
 * @file     I2C_Program.c
 * @brief    Bare-metal I2C Implementation for ATmega32.
 */

#include "I2C_Interface.h"
#include "I2C_Config.h"
#include "I2C_Private.h"

/* Helper function to poll TWINT flag with a timeout */
static I2C_ErrorStatus_t I2C_WaitFlag(void)
{
    uint32_t timeout = I2C_TIMEOUT_LOOPS;
    while (!(TWCR_Reg & (1 << TWINT_Bit)))
    {
        if (--timeout == 0)
        {
            TWCR_Reg = (1 << TWEN_Bit); 
            return I2C_TIMEOUT_ERROR;
        }
    }
    return I2C_OK;
}

void I2C_InitMaster(uint8_t own_address)
{
    if (own_address >= Reserved_Addresses_Scheme || own_address == General_Call_InstructionAddress)
    {
        return;
    }

    SetBit(TWCR_Reg, TWEN_Bit);
    Clearing_PrescallerBits();
    TWSR_Reg |= TWI_PrescallerRepresentation;

    TWBR_Reg = Calculate_Value_TWI_Bit_Rate(F_CPU, SCL_Frequency, TWI_PrescallerValue);
    TWAR_Reg = (own_address << 1) | (GeneralCall_Enabling);
}

I2C_ErrorStatus_t I2C_StartCondition(void)
{
    TWCR_Reg = (1 << TWINT_Bit) | (1 << TWSTA_Bit) | (1 << TWEN_Bit);

    if (I2C_WaitFlag() == I2C_TIMEOUT_ERROR) return I2C_TIMEOUT_ERROR;

    if (StatusBitsValue == START_ERROR_CodeCheck)
    {
        return I2C_OK;
    }
    return I2C_START_ERROR;
}

I2C_ErrorStatus_t I2C_RepeatedStart(void)
{
    TWCR_Reg = (1 << TWINT_Bit) | (1 << TWSTA_Bit) | (1 << TWEN_Bit);

    if (I2C_WaitFlag() == I2C_TIMEOUT_ERROR) return I2C_TIMEOUT_ERROR;

    if (StatusBitsValue == REP_START_ERROR_CodeCheck)
    {
        return I2C_OK;
    }
    return I2C_REP_START_ERROR;
}

void I2C_StopCondition(void)
{
    TWCR_Reg = (1 << TWINT_Bit) | (1 << TWSTO_Bit) | (1 << TWEN_Bit);
}

I2C_ErrorStatus_t I2C_SendSlaveAddressWrite(uint8_t slave_address)
{
    if (slave_address >= Reserved_Addresses_Scheme)
    {
        return I2C_INVALID_ADDRESS;
    }

    TWDR_Reg = (slave_address << 1) | Write_Command;
    TWCR_Reg = (1 << TWINT_Bit) | (1 << TWEN_Bit);

    if (I2C_WaitFlag() == I2C_TIMEOUT_ERROR) return I2C_TIMEOUT_ERROR;

    if (StatusBitsValue == Slave_Write_Operation_Ack_Recieving_CodeCheck)
    {
        return I2C_SLA_W_ACK_REC;
    }
    else if (StatusBitsValue == Slave_Write_Operation_NotAck_Recieving_CodeCheck)
    {
        return I2C_SLA_W_NACK_REC;
    }
    else if (StatusBitsValue == ARBITRATION_LOST_CodeCheck)
    {
        return I2C_ARBITRATION_LOST;
    }
    return I2C_SLA_W_ERROR;
}

I2C_ErrorStatus_t I2C_SendSlaveAddressRead(uint8_t slave_address)
{
    if (slave_address >= Reserved_Addresses_Scheme)
    {
        return I2C_INVALID_ADDRESS;
    }

    TWDR_Reg = (slave_address << 1) | Read_Command;
    TWCR_Reg = (1 << TWINT_Bit) | (1 << TWEN_Bit);

    if (I2C_WaitFlag() == I2C_TIMEOUT_ERROR) return I2C_TIMEOUT_ERROR;

    if (StatusBitsValue == Slave_Read_ACK_Recieving_CodeCheck)
    {
        return I2C_SLA_R_ACK_REC;
    }
    else if (StatusBitsValue == Slave_Read_NotACK_Recieving_CodeCheck)
    {
        return I2C_SLA_R_NACK_REC;
    }
    else if (StatusBitsValue == ARBITRATION_LOST_CodeCheck)
    {
        return I2C_ARBITRATION_LOST;
    }
    return I2C_SLA_R_ERROR;
}

I2C_ErrorStatus_t I2C_WriteByte(uint8_t data)
{
    TWDR_Reg = data;
    TWCR_Reg = (1 << TWINT_Bit) | (1 << TWEN_Bit);

    if (I2C_WaitFlag() == I2C_TIMEOUT_ERROR) return I2C_TIMEOUT_ERROR;

    if (StatusBitsValue == SendingData_Ack_Recieving_CodeCheck)
    {
        return I2C_DATA_TX_ACK_REC;
    }
    else if (StatusBitsValue == SendingData_NotAck_Recieving_CodeCheck)
    {
        return I2C_DATA_TX_NACK_REC;
    }
    else if (StatusBitsValue == ARBITRATION_LOST_CodeCheck)
    {
        return I2C_ARBITRATION_LOST;
    }
    return I2C_DATA_TX_ERROR;
}

I2C_ErrorStatus_t I2C_ReadByteAck(uint8_t *data)
{
    if (data == NULL)
    {
        return I2C_NULL_POINTER_ERROR;
    }

    TWCR_Reg = (1 << TWINT_Bit) | (1 << TWEA_Bit) | (1 << TWEN_Bit);

    if (I2C_WaitFlag() == I2C_TIMEOUT_ERROR) return I2C_TIMEOUT_ERROR;

    if (StatusBitsValue == Data_byte_has_been_received_ACK)
    {
        *data = TWDR_Reg;
        return I2C_DATA_RX_ACK_SENT;
    }
    return I2C_DATA_RX_ERROR;
}

I2C_ErrorStatus_t I2C_ReadByteNack(uint8_t *data)
{
    if (data == NULL)
    {
        return I2C_NULL_POINTER_ERROR;
    }

    TWCR_Reg = (1 << TWINT_Bit) | (1 << TWEN_Bit);
    
    if (I2C_WaitFlag() == I2C_TIMEOUT_ERROR) return I2C_TIMEOUT_ERROR;

    if (StatusBitsValue == Data_byte_has_been_received_NACK)
    {
        *data = TWDR_Reg;
        return I2C_DATA_RX_NACK_SENT;
    }
    return I2C_DATA_RX_ERROR;
}