
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


#define DIO_PORTA      0
#define DIO_PORTB      1
#define DIO_PORTC      2
#define DIO_PORTD      3


#define DIO_PIN0       0
#define DIO_PIN1       1
#define DIO_PIN2       2
#define DIO_PIN3       3
#define DIO_PIN4       4
#define DIO_PIN5       5
#define DIO_PIN6       6
#define DIO_PIN7       7


#define DIO_LOW        0
#define DIO_HIGH       1
 
#define DIO_INPUT      0
#define DIO_OUTPUT     1


void DIO_voidSetPinValue(u8 PortGroup, u8 Pin, u8 Value);

void DIO_voidSetPinDirection(u8 PortGroup, u8 Pin, u8 Direction);

void DIO_voidGetPinValue(u8 PortGroup, u8 Pin, u8 *Input);


void DIO_voidSetPortValue(u8 PortGroup, u8 Value);


void DIO_voidSetPortDirection(u8 PortGroup, u8 Direction);


void DIO_voidGetPortValue(u8 PortGroup, u8 *Input);

#endif

