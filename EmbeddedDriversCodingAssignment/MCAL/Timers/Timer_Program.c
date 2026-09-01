/**
 * @file    Timer_Program.c
 * @brief   This is the implementation of the Driver APIs and Helper Function
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */


u8 Timer0_u8Init();
u8 Timer0_u8_my_delay_ms(u16 ms);
u8 Timer0_u8SetCompareValue(u16 ms);
void Timer0_voidSet_OVE_CallBack(void(*Timer0_CallBack));