/**
 * @file    LCD_Program.c
 * @brief   Provides the Implementation of the Interface APIs
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../LIB/STD_TYPES.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
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
    LCD_voidSendCommand(DisplayOnCommand);
    _delay_ms(5);
}
void LCD_voidSendData(u8 Data)
{
    DIO_voidSetPinValue(LCD_RSPin_Group, LCD_RSPin_Number, DIO_HIGH);

    // assuming RW is on the ground
    DIO_voidSetPortValue(LCD_DataPins_Group, Data);
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

void LCD_voidSendString(u8 *PcString)
{
    if (PcString)
    {
        for (int i = 0; PcString[i] != '\0'; i++)
        {
            LCD_voidSendData(PcString[i]);
        }
    }
}
void LCD_voidSendNumber(s32 Number)
{
    u8 digits[10];
    if (Number < 0)
    {
        LCD_voidSendData('-');
        Number *= -1;
    }
    else if (Number == 0)
    {

        LCD_voidSendData('0');
        return;
    }
    int i = 0;
    for (; Number != 0; i++)
    {
        // to transform it to a character to be understood by the LCD
        digits[i] = (Number % 10) + '0';
        Number /= 10;
    }
    while(i--)
    {
        LCD_voidSendData(digits[i]);
    }
}
void LCD_voidSetPosition(u8 X, u8 Y)
{
    u8 Address = 0;

    Address = X + (Y ? 0x40 : 0x00);
    LCD_voidSendCommand(Set_DDRAM_Address(Address));
}
void LCD_voidClearDisplay(void)
{
    LCD_voidSendCommand(ClearDisplayCommand);
}
void LCD_voidReturnHome(void)
{
    LCD_voidSendCommand(ReturnHomeCommand);
}

void LCD_voidSendSpecialCharecter(u8 BlockNum, u8 *ArrayPattern, u8 X, u8 Y)
{

    if(ArrayPattern&& (BlockNum < 8))
    {

        u8 CGRAMAddress = BlockNum * 8;
        
      
        LCD_voidSendCommand(Set_CGRAM_Address(CGRAMAddress));
        
     
        for(u8 i = 0; i < 8; i++)
        {
            LCD_voidSendData(ArrayPattern[i]); 
        }
        
     
        LCD_voidSetPosition(X, Y);
        

        LCD_voidSendData(BlockNum);
    }
}
