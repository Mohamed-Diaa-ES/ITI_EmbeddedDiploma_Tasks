/**
 * @file    EXTI_Private.h
 * @brief   This shows The private macros to be not changed and adddresses in memory
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */
#ifndef _EXTI_Private_H
#define _EXTI_Private_H

typedef enum
{
    ISC00,
    ISC01,
    ISC10,
    ISC11,
} MCUCR_EXTI_Bits;

typedef enum
{
    ISC2 = 6,
} MCUCSR_EXTI_Bits;

typedef enum
{
    INT2 = 5,
    INT0 = 6,
    INT1 = 7,
} GICR_EXTI_Bits; // interrupt enable bits

typedef enum
{
    INTF2 = 5,
    INTF0 = 6,
    INTF1 = 7,
} GIFR_EXTI_Bits; // interrupt Flags bits

typedef enum
{
    Low_Level,
    Any_logical,
    Failling_Edge,
    Rising_Edge,

} EXTI_0_1_SensControl_Options;

typedef enum
{
    Failling_Edge2,
    Rising_Edge2,

} EXTI_2_SensControl_Options;

#define MCUCR_Reg *((volatile u8 *)0x55)
#define MCUCSR_Reg *((volatile u8 *)0x54)
#define GICR_Reg *((volatile u8 *)0x5B)
#define GIFR_Reg *((volatile u8 *)0x5A)

#endif