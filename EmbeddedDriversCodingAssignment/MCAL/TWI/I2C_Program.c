#include "I2C_Interface.h"
#include "I2C_Config.h"
#include "I2C_Private.h"

/* State Machine Variables */
static volatile I2C_State_t g_i2c_state = I2C_STATE_IDLE;
static uint8_t *g_twi_tx_buffer = NULL;
static uint16_t g_twi_tx_length = 0;
static uint16_t g_twi_tx_index = 0;
static uint8_t g_twi_target_address = 0;
static void (*g_twi_callback)(I2C_ErrorStatus_t) = NULL;

/* Asynchronous Transmit Function */
I2C_ErrorStatus_t I2C_MasterTransmitAsync(uint8_t slave_address, uint8_t *data, uint16_t length, void (*callback)(I2C_ErrorStatus_t))
{
    if (g_i2c_state != I2C_STATE_IDLE)
    {
        return I2C_START_ERROR; // Bus is busy
    }

    /* 1. Setup the background transfer details */
    g_twi_target_address = slave_address;
    g_twi_tx_buffer = data;
    g_twi_tx_length = length;
    g_twi_tx_index = 0;
    g_twi_callback = callback;
    g_i2c_state = I2C_STATE_START_SENT;

    /* 2. Fire the START condition with Interrupt Enabled */
    TWCR_Reg = (1 << TWINT_Bit) | (1 << TWSTA_Bit) | (1 << TWEN_Bit) | (1 << TWIE_Bit);

    /* 3. Return immediately! CPU is free to do other tasks. */
    return I2C_OK;
}

void __vector_19(void) __attribute__((signal, used));
void __vector_19(void)
{
    uint8_t status = StatusBitsValue; // Read masked TWSR register[cite: 20, 21]

    switch (status)
    {
    /* START condition successfully transmitted */
    case START_ERROR_CodeCheck:
        TWDR_Reg = (g_twi_target_address << 1) | Write_Command;          // Load SLA+W[cite: 20, 21]
        TWCR_Reg = (1 << TWINT_Bit) | (1 << TWEN_Bit) | (1 << TWIE_Bit); // Clear flag to send[cite: 21]
        g_i2c_state = I2C_STATE_SLA_W_SENT;
        break;

    /* SLA+W transmitted, ACK received */
    case Slave_Write_Operation_Ack_Recieving_CodeCheck:
    /* Data byte transmitted, ACK received */
    case SendingData_Ack_Recieving_CodeCheck:

        if (g_twi_tx_index < g_twi_tx_length)
        {
            // More data to send
            TWDR_Reg = g_twi_tx_buffer[g_twi_tx_index++];                    // Load next byte[cite: 20]
            TWCR_Reg = (1 << TWINT_Bit) | (1 << TWEN_Bit) | (1 << TWIE_Bit); // Send it[cite: 21]
            g_i2c_state = I2C_STATE_TX_DATA;
        }
        else
        {
            // All data sent. Fire STOP condition.
            TWCR_Reg = (1 << TWINT_Bit) | (1 << TWSTO_Bit) | (1 << TWEN_Bit); // STOP bit set[cite: 21]
            g_i2c_state = I2C_STATE_IDLE;

            if (g_twi_callback != NULL)
            {
                g_twi_callback(I2C_OK); // Notify application it finished successfully
            }
        }
        break;

    /* NACK received or Arbitration Lost (Error Handling) */
    case Slave_Write_Operation_NotAck_Recieving_CodeCheck:
    case SendingData_NotAck_Recieving_CodeCheck:
    case ARBITRATION_LOST_CodeCheck:
        TWCR_Reg = (1 << TWINT_Bit) | (1 << TWSTO_Bit) | (1 << TWEN_Bit); // Abort with STOP[cite: 21]
        g_i2c_state = I2C_STATE_IDLE;

        if (g_twi_callback != NULL)
        {
            g_twi_callback(I2C_DATA_TX_NACK_REC); // Notify application of error
        }
        break;

    default:
        // Unhandled state, reset peripheral
        TWCR_Reg = (1 << TWINT_Bit) | (1 << TWEN_Bit);
        g_i2c_state = I2C_STATE_IDLE;
        break;
    }
}