/**
 * @file    LCD_Private.h
 * @brief   Provides private command macros of the LCD
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */

#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define ClearDisplayCommand    0x01
#define ReturnHomeCommand      0x02
#define EntryModeSetCommand    0x06  
#define DisplayOnCommand       0x0C  
#define DisplayOffCommand      0x08
#define FunctionSetCommand     0x38  

#define Set_CGRAM_Address(Address)     (0x40 | ((Address) & 0b00111111))
#define Set_DDRAM_Address(Address)     (0x80 | ((Address) & 0b01111111))

#endif