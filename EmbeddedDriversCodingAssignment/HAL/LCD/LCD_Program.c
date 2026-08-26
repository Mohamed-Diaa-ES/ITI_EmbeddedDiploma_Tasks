/**
 * @file    LCD_Program.c
 * @brief   Provides the Implementation of the Interface APIs
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../LIB/STD_TYPES.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include <util/delay.h>

void LCD_voidInit(void)
{
    DIO_voidSetPortDirection(LCD_DataPins_Group, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_ENPin_Group, LCD_ENPin_Number, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_RSPin_Group, LCD_RSPin_Number, DIO_OUTPUT);
    _delay_ms(20);
    LCD_voidSendCommand(FunctionSetCommand);
    _delay_ms(5);
    LCD_voidSendCommand(FunctionSetCommand);
    _delay_ms(5);
    LCD_voidSendCommand(FunctionSetCommand);
    _delay_ms(5);
    LCD_voidSendCommand(DisplayOffCommand);
    _delay_ms(5);
    LCD_voidSendCommand(ClearDisplayCommand);
    _delay_ms(5);
    LCD_voidSendCommand(EntryModeSetCommand);
    _delay_ms(5);
}
void LCD_voidSendData(u8 Data)
{
    DIO_voidSetPinValue(LCD_RSPin_Group, LCD_RSPin_Number, DIO_High);

    // assuming RW is on the ground
    DIO_voidSetPortValue(LCD_DataPins_Group, Command);
    DIO_voidSetPinValue(LCD_ENPin_Group, LCD_ENPin_Number, DIO_HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_ENPin_Group, LCD_ENPin_Number, DIO_LOW);
    _delay_ms(2);
}
void LCD_voidSendCommand(u8 Command)
{
    DIO_voidSetPinValue(LCD_RSPin_Group, LCD_RSPin_Number, DIO_LOW);

    // assuming RW is on the ground
    DIO_voidSetPortValue(LCD_DataPins_Group, Command);
    DIO_voidSetPinValue(LCD_ENPin_Group, LCD_ENPin_Number, DIO_HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_ENPin_Group, LCD_ENPin_Number, DIO_LOW);
    _delay_ms(2);
}

void LCD_voidSendString(u8 *PcString);
void LCD_voidSendNumber(s32 s32Number);
void LCD_voidSetPosition(u8 u8X, u8 u8Y);
void LCD_voidClearDisplay(void);
void LCD_voidReturnHome(void);

void LCD_voidSendSpecialCharecter(u8 u8BlockNum, u8 *Pu8ArrayPattern, u8 u8X, u8 u8Y);
