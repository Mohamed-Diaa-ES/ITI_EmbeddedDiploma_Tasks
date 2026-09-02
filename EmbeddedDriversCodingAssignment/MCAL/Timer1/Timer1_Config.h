/**
 * @file    Timer_Config.h
 * @brief   This shows the configurable macros that we can configure for the Timer Driver
 * @author  mohammed diaa <mohammeddiaato@gmail.com>
 */
#ifndef _Timer_Config_H
#define _Timer_Config_H

#define CPU_F 8000000UL
#define PrescallerValue Prescaller_8
#define WorkingMode Normal_Mode
#define PortAction Normal_PORT

#define Timer0_OverflowTime 1

#define OCRA 1
#define OCRB 0

#define True_Setting 1
#define False_Setting 0

#define CLock_TIME (PrescallerValue / CPU_F) //->should be 1us for clock
#define OVERFLOW_TIME (0xFFFF * CLock_TIME)
#define one_MilliSecond (1000 * CLock_TIME)

#define Preloaded_Value_For_1ms     (0xFFFF - 1000)
#define NumberOfCountsFor_OneSecond (1000*one_MilliSecond)/0xFFFF
#define Preloaded_Value_For_oneSeoncd     (0xFFFF - 1000)

#endif