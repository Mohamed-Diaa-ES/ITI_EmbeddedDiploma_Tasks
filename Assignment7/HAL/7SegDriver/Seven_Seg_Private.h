/**
 * @file Seven_Seg_Private.h
 */
#ifndef _SEVEN_SEG_PRIVATE_H_
#define _SEVEN_SEG_PRIVATE_H_
#include "Seven_Seg_Config.h"
#include "../../LIB/STD_Types.h"
/**
 * These numbers indicate the next:
 *  at each bit tells us what the value should be at the pin of the segment:
 * 7 6 5  4  3  2  1  0
 * h g f  e  d  c  b  a
 * h -> power pin
 */
#define CommonCathode_Number_0 (u8)0x3F
#define CommonCathode_Number_1 (u8)0x06
#define CommonCathode_Number_2 (u8)0x5B
#define CommonCathode_Number_3 (u8)0x4f
#define CommonCathode_Number_4 (u8)0x66
#define CommonCathode_Number_5 (u8)0x6D
#define CommonCathode_Number_6 (u8)0x7D
#define CommonCathode_Number_7 (u8)0x07
#define CommonCathode_Number_8 (u8)0x7F
#define CommonCathode_Number_9 (u8)0x6F

/**
 * Common Anode is the flip of the number
 * CommonANODE ==~ commoncathode and vice versa
 */
#define CommonAnode_Number_0    ~(u8)(CommonCathode_Number_0)
#define CommonAnode_Number_1    ~(u8)(CommonCathode_Number_1)
#define CommonAnode_Number_2    ~(u8)(CommonCathode_Number_2)
#define CommonAnode_Number_3    ~(u8)(CommonCathode_Number_3)
#define CommonAnode_Number_4    ~(u8)(CommonCathode_Number_4)
#define CommonAnode_Number_5    ~(u8)(CommonCathode_Number_5)
#define CommonAnode_Number_6    ~(u8)(CommonCathode_Number_6)
#define CommonAnode_Number_7    ~(u8)(CommonCathode_Number_7)
#define CommonAnode_Number_8    ~(u8)(CommonCathode_Number_8)
#define CommonAnode_Number_9    ~(u8)(CommonCathode_Number_9)

#define SevenSegMentArrCommAnode \
    {CommonAnode_Number_0,       \
     CommonAnode_Number_1,       \
     CommonAnode_Number_2,       \
     CommonAnode_Number_3,       \
     CommonAnode_Number_4,       \
     CommonAnode_Number_5,       \
     CommonAnode_Number_6,       \
     CommonAnode_Number_7,       \
     CommonAnode_Number_8,       \
     CommonAnode_Number_9}
#define SevenSegMentArrCommCath \
    {CommonCathode_Number_0,    \
     CommonCathode_Number_1,    \
     CommonCathode_Number_2,    \
     CommonCathode_Number_3,    \
     CommonCathode_Number_4,    \
     CommonCathode_Number_5,    \
     CommonCathode_Number_6,    \
     CommonCathode_Number_7,    \
     CommonCathode_Number_8,    \
     CommonCathode_Number_9}

#endif
