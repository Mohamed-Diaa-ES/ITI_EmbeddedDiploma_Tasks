/**
 * @file    Timer_Interface.h
 * @brief   This shows The APIs needed by the Timer driver
 * @author  mohammed diaa <mohammeddiaato@gmail.com>
 */
#ifndef _Timer_Interface_H
#define _Timer_Interface_H

u8 Timer0_u8Init();
u8 Timer0_u8_my_delay_ms(u16 ms);
u8 Timer0_u8SetCompareValue(u16 ms);
void Timer0_voidSet_OVE_CallBack(void(*Timer0_CallBack));

#endif