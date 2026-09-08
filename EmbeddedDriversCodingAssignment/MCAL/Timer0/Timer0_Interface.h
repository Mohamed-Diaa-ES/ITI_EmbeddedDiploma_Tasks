/**
 * @file    Timer_Interface.h
 * @brief   This shows The APIs needed by the Timer driver
 * @author  mohammed diaa <mohammeddiaato@gmail.com>
 */
#ifndef _Timer_Interface_H
#define _Timer_Interface_H
#include "Timer0_Config.h"
/**
 * @enum PrescallerValues_t
 * @brief
 */
typedef enum
{
    No_Clock_Source,
    Prescaller_1,
    Prescaller_8,
    Prescaller_64,
    Prescaller_256,
    Prescaller_1024,
    ExternalSource_FallingEdge,
    ExternalSource_RisingEdge,

} Prescaller_t;
typedef enum
{
    No_Clock_Source_Value = 0,
    Prescaller_1_Value = 1,
    Prescaller_8_Value = 8,
    Prescaller_64_Value = 64,
    Prescaller_256_Value = 256,
    Prescaller_1024_Value = 1024,
    ExternalSource_FallingEdge_Value = EXTERNAL_CLOCK_FALLIN,
    ExternalSource_RisingEdge_Value = EXTERNAL_CLOCK_RISING,

} PrescallerValues_t;

/**
 * @enum WaveForm_Modes_t
 * @brief
 */
typedef enum
{
    Normal_Mode,
    PWM_PhaseCorrect_Mode,
    CTC_Mode,
    PWM_FastPWM,

} WaveForm_Modes_t;

/**
 * @enum COM_NoNPWM_Modes_t
 * @brief
 */
typedef enum
{
    Normal_PORT_Fast_pwm,
    Toggle_OC0,
    Clear_OC0,
    Set_OC0,

} COM_NoNPWM_Modes_t;

/**
 * @enum COM_FAST_PWM_Modes_t
 * @brief
 */

typedef enum
{
    Normal_PORT,
    RESERVED_DO_NOT_USE,
    Non_Inverting,
    Inverting,

} COM_FAST_PWM_Modes_t;
/**
 * @struct Timer_Configuration_t
 * @brief
 */

typedef struct
{
    volatile WaveForm_Modes_t mode;
    volatile Prescaller_t Prescaller;
} Timer_Configuration_t;

/**
 * @fn
 * @brief
 * @details
 */
void Timer0_voidInit(WaveForm_Modes_t mode, Prescaller_t Prescaller);
/**
 * @fn
 * @brief
 * @details
 */

u8 Timer0_u8_my_delay_ms_OVF(u16 ms);
/**
 * @fn
 * @brief
 * @details
 */
u8 Timer0_u8_my_delay_us_OVF(u16 us);
/**
 * @fn
 * @brief
 * @details
 */

u8 Timer0_u8_my_delay_ms_CTC(u16 ms);
/**
 * @fn
 * @brief
 * @details
 */
u8 Timer0_u8_my_delay_us_CTC(u16 us);
/**
 * @fn
 * @brief
 * @details
 */
u8 Timer0_u8SetCompareValue(u8 CompareValue);
/**
 * @fn
 * @brief
 * @details
 */
void Timer0_voidSet_OVF_CallBack(void (*Timer0_CallBack)(void));
/**
 * @fn
 * @brief
 * @details
 */
void Timer0_voidSet_CTC_CallBack(void (*Timer0_CallBack)(void));
/**
 * @fn
 * @brief
 * @details
 */
void Timer0_voidEnableTimer();
/**
 * @fn
 * @brief
 * @details
 */

void Timer0_voidDisableTimer();
/**
 * @fn
 * @brief
 * @details
 */

void Timer0_voidActionTimer(u8 mode, u8 Action);

#endif