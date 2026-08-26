/**
 * @file    LCD_Interface.h
 * @brief   provides the APIs of the LCD Display
 * @author Mohammed Diaa <mohammeddiaato@gmail.com>
 */

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H




void LCD_voidInit(void);
void LCD_voidSendData(u8 Data);
void LCD_voidSendCommand(u8 Command);

void LCD_voidSendString(u8 *PcString);
void LCD_voidSendNumber(s32 Number);
void LCD_voidSetPosition(u8 X, u8 Y);
void LCD_voidClearDisplay(void);
void LCD_voidReturnHome(void);

void LCD_voidSendSpecialCharecter(u8 BlockNum, u8 *ArrayPattern, u8 X, u8 Y);
#endif