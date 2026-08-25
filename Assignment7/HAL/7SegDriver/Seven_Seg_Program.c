#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Seven_Seg_Config.h"
#include "Seven_Seg_Private.h"
#include "Seven_Seg_Interface.h"

#if Seg_UsedType == Segment_Type_CommAnode
static const u8 NumberArr[10] = SevenSegMentArrCommAnode;
#elif Seg_UsedType == Segment_Type_CommCath
static const u8 NumberArr[10] = SevenSegMentArrCommCath;
#endif

void SSD_voidInitialDataPort(void)
{
#if DisplayOnSamePort == DisplayingonSamePort
    DIO_voidSetPortDirection(Segment_A_Group, 0xFF);
#elif DisplayOnSamePort == DisplayingonDifferentPorts
    DIO_voidSetPinDirection(Segment_A_Group, Segment_A_Pin, DIO_OUTPUT);
    DIO_voidSetPinDirection(Segment_B_Group, Segment_B_Pin, DIO_OUTPUT);
    DIO_voidSetPinDirection(Segment_C_Group, Segment_C_Pin, DIO_OUTPUT);
    DIO_voidSetPinDirection(Segment_D_Group, Segment_D_Pin, DIO_OUTPUT);
    DIO_voidSetPinDirection(Segment_E_Group, Segment_E_Pin, DIO_OUTPUT);
    DIO_voidSetPinDirection(Segment_F_Group, Segment_F_Pin, DIO_OUTPUT);
    DIO_voidSetPinDirection(Segment_G_Group, Segment_G_Pin, DIO_OUTPUT);
#endif
DIO_voidSetPinDirection(SegmentPower_Group, SegmentPower_Pin, DIO_OUTPUT);
}

void SSD_voidSendNumber(u8 Number)
{
    if (Number < 10)
    {
#if DisplayOnSamePort == DisplayingonSamePort
        DIO_voidSetPortValue(Segment_A_Group, NumberArr[Number]);
#elif DisplayOnSamePort == DisplayingonDifferentPorts
        DIO_voidSetPinValue(Segment_A_Group, Segment_A_Pin, (NumberArr[Number] >> 0) & 0x01);
        DIO_voidSetPinValue(Segment_B_Group, Segment_B_Pin, (NumberArr[Number] >> 1) & 0x01);
        DIO_voidSetPinValue(Segment_C_Group, Segment_C_Pin, (NumberArr[Number] >> 2) & 0x01);
        DIO_voidSetPinValue(Segment_D_Group, Segment_D_Pin, (NumberArr[Number] >> 3) & 0x01);
        DIO_voidSetPinValue(Segment_E_Group, Segment_E_Pin, (NumberArr[Number] >> 4) & 0x01);
        DIO_voidSetPinValue(Segment_F_Group, Segment_F_Pin, (NumberArr[Number] >> 5) & 0x01);
        DIO_voidSetPinValue(Segment_G_Group, Segment_G_Pin, (NumberArr[Number] >> 6) & 0x01);
#endif
    }
}
void SSD_voidEnable()
{
#if Seg_UsedType == Segment_Type_CommAnode
    
    DIO_voidSetPinValue(SegmentPower_Group, SegmentPower_Pin, DIO_HIGH);
#elif Seg_UsedType == Segment_Type_CommCath

    DIO_voidSetPinValue(SegmentPower_Group, SegmentPower_Pin, DIO_LOW);
#endif
}

void SSD_voidDisable()
{
#if Seg_UsedType == Segment_Type_CommAnode

    DIO_voidSetPinValue(SegmentPower_Group, SegmentPower_Pin, DIO_LOW);
#elif Seg_UsedType == Segment_Type_CommCath

    DIO_voidSetPinValue(SegmentPower_Group, SegmentPower_Pin, DIO_HIGH);
#endif
}