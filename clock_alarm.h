/*
 * clock_alarm.h
 *
 *  Created on: Oct 12, 2023
 *      Author: omar tarek
 */


#ifndef INC_SEVEN_SEGMENT_H_
#define INC_SEVEN_SEGMENT_H_

#include "StdTypes.h"


/* ALARM 7 SEGMENT PINS */
#define S1_A    DIO_PORTA, DIO_PIN0
#define S1_B    DIO_PORTA, DIO_PIN1
#define S1_C    DIO_PORTA, DIO_PIN2
#define S1_D    DIO_PORTA, DIO_PIN3

#define S1_H2   DIO_PORTC, DIO_PIN6
#define S1_H1   DIO_PORTC, DIO_PIN7
#define S1_M2   DIO_PORTD, DIO_PIN0
#define S1_M1   DIO_PORTD, DIO_PIN1

/* CLOCK 7 SEGMENT PINS */
#define S2_A    DIO_PORTA, DIO_PIN4
#define S2_B    DIO_PORTA, DIO_PIN5
#define S2_C    DIO_PORTA, DIO_PIN6
#define S2_D    DIO_PORTA, DIO_PIN7

#define S2_H2   DIO_PORTC, DIO_PIN0
#define S2_H1   DIO_PORTC, DIO_PIN1
#define S2_M2   DIO_PORTC, DIO_PIN2
#define S2_M1   DIO_PORTC, DIO_PIN3
#define S2_S2   DIO_PORTC, DIO_PIN4
#define S2_S1   DIO_PORTC, DIO_PIN5


#define STOP    DIO_PORTB,DIO_PIN1
#define LED     DIO_PORTB,DIO_PIN2
#define SAVE    DIO_PORTB,DIO_PIN3
#define BUT1    DIO_PORTB,DIO_PIN4
#define BUT2    DIO_PORTB,DIO_PIN5
#define BUT3    DIO_PORTB,DIO_PIN6
#define BUT4    DIO_PORTB,DIO_PIN7

typedef enum
{
    CLOCK,
    ALARM
} SEV_SEG_MODE ;

typedef enum
{
    SEV_SEG_1_H_2,
    SEV_SEG_1_H_1,
    SEV_SEG_1_M_2,
    SEV_SEG_1_M_1,

    SEV_SEG_2_H_2,
    SEV_SEG_2_H_1,
    SEV_SEG_2_M_2,
    SEV_SEG_2_M_1,
    SEV_SEG_2_S_2,
    SEV_SEG_2_S_1,

} SEV_SEG_OUT_PIN ;


void CLOCK_INIT(void);
void ALARM_INIT(void);

void CLOCK_Display(u8 number);
void ALARM_Display(u8 number);

void CLOCK_Disable_All(void);
void ALARM_Disable_All(void);

void CLOCK_Enable_All(void);
void ALARM_Enable_All(void);



#endif /* INC_SEVEN_SEGMENT_H_ */
