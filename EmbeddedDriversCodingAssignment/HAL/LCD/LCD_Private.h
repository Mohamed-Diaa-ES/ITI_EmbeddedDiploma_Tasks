/**
 * @file    LCD_Private.h
 * @brief   Provides the private macros of the LCD.
 * @author Mohammed Diaa <mohammeddiaato@gmail.com>
 */

#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define ClearDisplayCommand     0b00000001

#define ReturnHomeCommand       0b00000010

#define EnteryHomeSetCommand    0b00000010

#define DisplayControlCommand   0x0C

#define FunctionSetCommand      0b00111100
#define FunctionSetCommand      0b00111100
#define Set_CGRAM_Address(Address)     (0x40|(Address&(0b00111111)))
#define Set_DDRAM_Address(Address)     (0x80|(Address&(0b01111111)))


#endif