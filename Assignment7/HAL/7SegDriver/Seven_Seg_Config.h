/**
 * @file    Seven_Seg_Config.h
 * @brief   
 * @details 
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 * 
 */
#ifndef _SEVEN_SEG_CONFIG_H_
#define _SEVEN_SEG_CONFIG_H_

#include "../../MCAL/DIO/DIO_Interface.h"



#define Segment_Type_CommAnode      1 
#define Segment_Type_CommCath       0    
   

#define Segment_A_Pin   DIO_u8_PIN0
#define Segment_B_Pin   DIO_u8_PIN1
#define Segment_C_Pin   DIO_u8_PIN2
#define Segment_D_Pin   DIO_u8_PIN3
#define Segment_E_Pin   DIO_u8_PIN4
#define Segment_F_Pin   DIO_u8_PIN5
#define Segment_G_Pin   DIO_u8_PIN6

#define Segment_A_Group  DIO_u8_PORTA
#define Segment_B_Group  DIO_u8_PORTA
#define Segment_C_Group  DIO_u8_PORTA
#define Segment_D_Group  DIO_u8_PORTA
#define Segment_E_Group  DIO_u8_PORTA
#define Segment_F_Group  DIO_u8_PORTA
#define Segment_G_Group  DIO_u8_PORTA

#define SegmentPower_Pin DIO_u8_PIN7



#endif