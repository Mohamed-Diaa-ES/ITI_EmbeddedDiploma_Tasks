/**
 * @file    KPD_Program.c
 * @brief   The implementation of the Interface APIs.
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../LIB/STD_TYPES.h"
#include "KPD_Interface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"

const u8 KPD_Array[NumberOfRows][NumberOfColumns] =
    {
        {'1', '2', '3', '4'},
        {'5', '6', '7', '8'},
        {'9', '0', 'A', 'C'},
        {'U', 'E', 'F', 'H'}


};

void KPD_voidInit()
{
    DIO_voidSetPortDirection(KPD_Port,InitMask_ForSamePort);
    // setting the columns to high and the rows to Pull up enabled inputs
    DIO_voidSetPortValue(KPD_Port,InitMask_ForSamePort);

}
u8 KPD_u8GetKey()
{

}