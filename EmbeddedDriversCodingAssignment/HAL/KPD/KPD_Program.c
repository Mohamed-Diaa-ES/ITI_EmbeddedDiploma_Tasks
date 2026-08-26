/**
 * @file    KPD_Program.c
 * @brief   The implementation of the Interface APIs.
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "KPD_Interface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"
#include <util/delay.h>

u8 ColumnsPins[NumberOfColumns] = {
    Column_Number_One_Pin,
    Column_Number_Two_Pin,
    Column_Number_Three_Pin,
    Column_Number_Four_Pin,
};
u8 RowsPins[NumberOfRows] = {
    Row_Number_One_Pin,
    Row_Number_Two_Pin,
    Row_Number_Three_Pin,
    Row_Number_Four_Pin,
};
void KPD_voidInit()
{
    DIO_voidSetPortDirection(KPD_Port, InitMask_ForSamePort);
    // setting the columns to high and the rows to Pull up enabled inputs
    DIO_voidSetPortValue(KPD_Port, InitMask_ForSamePort);
}
u8 KPD_u8GetKey()
{

    const u8 KPD_Array[NumberOfRows][NumberOfColumns] =
        {
            {'1', '2', '3', '4'},
            {'5', '6', '7', '8'},
            {'9', '0', 'A', 'C'},
            {'U', 'E', 'F', 'H'}

        };

    int col = 0, row = 0;

    u8 ReadingPressed = 0;
    u8 KeyPressed = 0;
    for (row = 0; row < NumberOfRows; row++)
    {
        for (col = 0; col < NumberOfColumns; col++)
        {
            DIO_voidSetPinValue(KPD_Port,ColumnsPins[col],DIO_LOW);
            
            DIO_voidGetPinValue(KPD_Port, RowsPins[row], &ReadingPressed);
            _delay_ms(20);// debounce delay
            if (ReadingPressed==0)
            {
                KeyPressed=KPD_Array[row][col];
                return KeyPressed;
            }
            DIO_voidSetPinValue(KPD_Port,ColumnsPins[col],DIO_HIGH);
            
        }
    }
}