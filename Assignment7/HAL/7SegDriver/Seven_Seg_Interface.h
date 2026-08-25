/**
 * @file Seven_Seg_Interface.h
 */
#ifndef _SEVEN_SEG_INTERFACE_H_
#define _SEVEN_SEG_INTERFACE_H_

#include "Seven_Seg_Private.h"
#include "Seven_Seg_Config.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#define Seg_UsedType Segment_Type_CommAnode  

#define DisplayOnSamePort   DisplayingonSamePort

#define Segment_A_Pin   DIO_PIN0
#define Segment_B_Pin   DIO_PIN1
#define Segment_C_Pin   DIO_PIN2
#define Segment_D_Pin   DIO_PIN3
#define Segment_E_Pin   DIO_PIN4
#define Segment_F_Pin   DIO_PIN5
#define Segment_G_Pin   DIO_PIN6

#define Segment_A_Group  DIO_PORTA
#define Segment_B_Group  DIO_PORTA
#define Segment_C_Group  DIO_PORTA
#define Segment_D_Group  DIO_PORTA
#define Segment_E_Group  DIO_PORTA
#define Segment_F_Group  DIO_PORTA
#define Segment_G_Group  DIO_PORTA

#define SegmentPower_Pin DIO_PIN7
#define SegmentPower_Group DIO_PORTA

void SSD_voidInitialDataPort();
void SSD_voidSendNumber(   u8 Number );
void SSD_voidSenditem(   u8 Number );
void SSD_voidEnable();
void SSD_voidDisable();

#endif