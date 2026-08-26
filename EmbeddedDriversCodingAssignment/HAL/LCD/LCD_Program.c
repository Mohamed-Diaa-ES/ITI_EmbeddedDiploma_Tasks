/**
 * @file    LCD_Program.c
 * @brief   Provides the Implementation of the Interface APIs
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../LIB/STD_TYPES.h"
#include "LCD_Interface.h"

void LCD_voidInit(void)
{}
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidSendCommand(u8 Copy_u8Command);

void LCD_voidSendString(u8 *PcCopy_String);
void LCD_voidSendNumber(s32 Copy_s32Number);
void LCD_voidSetPosition(u8 Copy_u8X, u8 Copy_u8Y);
void LCD_voidClearDisplay(void);
void LCD_voidReturnHome(void);

void LCD_voidSendSpecialCharecter(u8 Copy_u8BlockNum, u8 *Pu8ArrayPattern, u8 Copy_u8X, u8 Copy_u8Y);

