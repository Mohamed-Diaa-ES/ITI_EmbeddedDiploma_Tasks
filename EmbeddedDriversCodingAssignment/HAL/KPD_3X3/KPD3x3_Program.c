/**
 * @file    KPD_Program.c
 * @brief   The implementation of the Interface APIs.
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "KPD3x3_Interface.h"
#include "KPD3x3_Private.h"
#include "KPD3x3_Config.h"
#include <util/delay.h>

u8 ColumnsPins[NumberOfColumns] = {
    Column_Number_One_Pin,
    Column_Number_Two_Pin,
    Column_Number_Three_Pin,
};

u8 RowsPins[NumberOfRows] = {
    Row_Number_One_Pin,
    Row_Number_Two_Pin,
    Row_Number_Three_Pin,
};

void KPD3x3_voidInit()
{
    u8 col, row;

    // Configure Columns as OUTPUTS and set them HIGH
    for (col = 0; col < NumberOfColumns; col++)
    {
        DIO_voidSetPinDirection(KPD_Port, ColumnsPins[col], DIO_OUTPUT);
        DIO_voidSetPinValue(KPD_Port, ColumnsPins[col], DIO_HIGH);
    }

    // Configure Rows as INPUTS and enable internal Pull-Up Resistors
    for (row = 0; row < NumberOfRows; row++)
    {
        DIO_voidSetPinDirection(KPD_Port, RowsPins[row], DIO_INPUT);
        DIO_voidSetPinValue(KPD_Port, RowsPins[row], DIO_HIGH);
    }
}

u8 KPD3x3_u8GetKey()
{
    const u8 KPD_Array[NumberOfRows][NumberOfColumns] =
        {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'},
        };

    int col = 0, row = 0;
    u8 ReadingPressed = 1; // Default HIGH (not pressed due to pull-up)
    u8 KeyPressed = 0;     // 0 means no key pressed

    for (col = 0; col < NumberOfColumns; col++)
    {
        // Activate current column by driving it LOW
        DIO_voidSetPinValue(KPD_Port, ColumnsPins[col], DIO_LOW);

        for (row = 0; row < NumberOfRows; row++)
        {
            // Read current row status
            DIO_voidGetPinValue(KPD_Port, RowsPins[row], &ReadingPressed);

            // If a button press is detected (pin reads LOW)
            if (ReadingPressed == 0)
            {
                _delay_ms(30); // Debounce delay
                DIO_voidGetPinValue(KPD_Port, RowsPins[row], &ReadingPressed);

                if (ReadingPressed == 0) // Check if still pressed
                {
                    KeyPressed = KPD_Array[row][col];

                    // Wait loop: block execution until the user releases the key
                    while (ReadingPressed == 0)
                    {
                        DIO_voidGetPinValue(KPD_Port, RowsPins[row], &ReadingPressed);
                    }

                    // Reset column back to high before returning
                    DIO_voidSetPinValue(KPD_Port, ColumnsPins[col], DIO_HIGH);
                    return KeyPressed;
                }
            }
        }

        // Deactivate column by driving it HIGH again
        DIO_voidSetPinValue(KPD_Port, ColumnsPins[col], DIO_HIGH);
    }

    return 0;
}
