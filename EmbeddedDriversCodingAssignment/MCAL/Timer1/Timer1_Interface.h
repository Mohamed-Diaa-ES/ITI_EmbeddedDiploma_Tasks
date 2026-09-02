/**
 * @file    Timer_Interface.h
 * @brief   This shows The APIs needed by the Timer driver
 * @author  mohammed diaa <mohammeddiaato@gmail.com>
 */
#ifndef _Timer_Interface_H
#define _Timer_Interface_H

u8 Timer1_u8Init(u8 mode,u8 prescaller);
u8 Timer1_u8SetAction(u8 Action);
u8 Timer1_SetICR(u16 Value);
u8 Timer1_u8_my_delay_ms(u16 ms);
u8 Timer1_u8SetCompareValue(u16 CompareValue,u8 A_or_B);
void Timer1_voidSet_OVE_CallBack(void(*Timer1_CallBack)(void));


#endif