/**
 * @file    DIO_Program.c
 * @brief   Implementation of the DIO Interfaces
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 * @date    25/8/2026
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

void DIO_voidSetPinValue(u8 PortGroup, u8 Pin, u8 Value)
{
    if (Pin < DIO_PIN0 || Pin > DIO_PIN7)
    {
        return;
    }
    else
    {
        switch (PortGroup)
        {
        case DIO_PORTA:
            if (Value == DIO_HIGH)
            {
                SET_BIT(DIO_u8_PORTA_REG, Pin);
            }
            else
            {
                CLR_BIT(DIO_u8_PORTA_REG, Pin);
            }
            break;
        case DIO_PORTB:
            if (Value == DIO_HIGH)
            {
                SET_BIT(DIO_u8_PORTB_REG, Pin);
            }
            else
            {
                CLR_BIT(DIO_u8_PORTB_REG, Pin);
            }
            break;
        case DIO_PORTC:
            if (Value == DIO_HIGH)
            {
                SET_BIT(DIO_u8_PORTC_REG, Pin);
            }
            else
            {
                CLR_BIT(DIO_u8_PORTC_REG, Pin);
            }
            break;
        case DIO_PORTD:
            if (Value == DIO_HIGH)
            {
                SET_BIT(DIO_u8_PORTD_REG, Pin);
            }
            else
            {
                CLR_BIT(DIO_u8_PORTD_REG, Pin);
            }
            break;
        }
    }
}

void DIO_voidSetPinDirection(u8 PortGroup, u8 Pin, u8 Direction)
{
    if (Pin < DIO_PIN0 || Pin > DIO_PIN7)
    {
        return;
    }
    else
    {
        switch (PortGroup)
        {
        case DIO_PORTA:
            if (Direction == DIO_OUTPUT)
            {
                SET_BIT(DIO_u8_DDRA_REG, Pin);
            }
            else
            {
                CLR_BIT(DIO_u8_DDRA_REG, Pin);
            }
            break;
        case DIO_PORTB:
            if (Direction == DIO_OUTPUT)
            {
                SET_BIT(DIO_u8_DDRB_REG, Pin);
            }
            else
            {
                CLR_BIT(DIO_u8_DDRB_REG, Pin);
            }
            break;
        case DIO_PORTC:
            if (Direction == DIO_OUTPUT)
            {
                SET_BIT(DIO_u8_DDRC_REG, Pin);
            }
            else
            {
                CLR_BIT(DIO_u8_DDRC_REG, Pin);
            }
            break;
        case DIO_PORTD:
            if (Direction == DIO_OUTPUT)
            {
                SET_BIT(DIO_u8_DDRD_REG, Pin);
            }
            else
            {
                CLR_BIT(DIO_u8_DDRD_REG, Pin);
            }
            break;
        }
    }
}

void DIO_voidGetPinValue(u8 PortGroup, u8 Pin, u8 *Input)
{

    if (Pin < DIO_PIN0 || Pin > DIO_PIN7)
    {
        return;
    }
    else
    {
        switch (PortGroup)
        {
        case DIO_PORTA:
            *Input = GET_BIT(DIO_u8_PINA_REG, Pin);
            break;
        case DIO_PORTB:
            *Input = GET_BIT(DIO_u8_PINB_REG, Pin);
            break;
        case DIO_PORTC:
            *Input = GET_BIT(DIO_u8_PINC_REG, Pin);
            break;
        case DIO_PORTD:
            *Input = GET_BIT(DIO_u8_PIND_REG, Pin);
            break;
        }
    }
}

void DIO_voidSetPortValue(u8 PortGroup, u8 Value)
{

    switch (PortGroup)
    {
    case DIO_PORTA:
        DIO_u8_PORTA_REG = Value;
        break;
    case DIO_PORTB:
        DIO_u8_PORTB_REG = Value;
        break;
    case DIO_PORTC:
        DIO_u8_PORTC_REG = Value;
        break;
    case DIO_PORTD:
        DIO_u8_PORTD_REG = Value;
        break;
    }
}

void DIO_voidSetPortDirection(u8 PortGroup, u8 Direction)
{
    switch (PortGroup)
    {
    case DIO_PORTA:
        DIO_u8_DDRA_REG = Direction;
        break;
    case DIO_PORTB:
        DIO_u8_DDRB_REG = Direction;
        break;
    case DIO_PORTC:
        DIO_u8_DDRC_REG = Direction;
        break;
    case DIO_PORTD:
        DIO_u8_DDRD_REG = Direction;
        break;
    }
}

void DIO_voidGetPortValue(u8 PortGroup, u8 *Input)
{
    switch (PortGroup)
    {
    case DIO_PORTA:
        *Input = DIO_u8_PINA_REG;
        break;
    case DIO_PORTB:
        *Input = DIO_u8_PINB_REG;
        break;
    case DIO_PORTC:
        *Input = DIO_u8_PINC_REG;
        break;
    case DIO_PORTD:
        *Input = DIO_u8_PIND_REG;
        break;
    }
}
