/**
 * @file    LCD_Interface.h
 * @brief   provides the APIs of the LCD Display
 * @author Mohammed Diaa <mohammeddiaato@gmail.com>
 */

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define LCD_DataPins_Group  DIO_PORTA

#define LCD_ENPin_Number    DIO_PIN0
#define LCD_ENPin_Group     DIO_PORTC

#define LCD_RSPin_Number    DIO_PIN1
#define LCD_RSPin_Group     DIO_PORTC
// #define LCD_RWPin_Group     DIO_PORTC // if needed to be put for reading



void LCD_voidInit(void);
void LCD_voidSendData(u8 Data);
void LCD_voidSendCommand(u8 Command);

void LCD_voidSendString(u8 *PcString);
void LCD_voidSendNumber(s32 Number);
void LCD_voidSetPosition(u8 X, u8 Y);
void LCD_voidClearDisplay(void);
void LCD_voidReturnHome(void);

void LCD_voidSendSpecialCharecter(u8 BlockNum, u8 *Pu8ArrayPattern, u8 X, u8 Y);

#endif