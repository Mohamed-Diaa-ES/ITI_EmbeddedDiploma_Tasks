/**
 * @file    LCD_Interface.h
 * @brief   provides the APIs of the LCD Display
 * @author Mohammed Diaa <mohammeddiaato@gmail.com>
 */

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidSendCommand(u8 Copy_u8Command);

void LCD_voidInit(void);
void LCD_voidSendString(u8 *PcCopy_String);
void LCD_voidSendNumber(s32 Copy_s32Number);
void LCD_voidSetPosition(u8 Copy_u8X, u8 Copy_u8Y);
void LCD_voidClearDisplay(void);
void LCD_voidReturnHome(void);

void LCD_voidSendSpecialCharecter(u8 Copy_u8BlockNum, u8 *Pu8ArrayPattern, u8 Copy_u8X, u8 Copy_u8Y);

#endif