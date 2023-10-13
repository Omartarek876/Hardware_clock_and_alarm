/*
 * clock_alarm.c
 *
 *  Created on: Oct 12, 2023
 *      Author: omar tarek
 */


#include "StdTypes.h"
#include "Delay.h"
#include "Macros.h"
#include "Registers.h"
#include "Dio.h"
#include "Seven_Segment.h"




void CLOCK_INIT(void)
{
	Dio_SetPinMode (S2_A , DIO_MODE_OUTPUT);
	Dio_SetPinMode (S2_B , DIO_MODE_OUTPUT);
	Dio_SetPinMode (S2_C , DIO_MODE_OUTPUT);
	Dio_SetPinMode (S2_D , DIO_MODE_OUTPUT);
}

void ALARM_INIT(void)
{
	Dio_SetPinMode (S1_A , DIO_MODE_OUTPUT);
	Dio_SetPinMode (S1_B , DIO_MODE_OUTPUT);
	Dio_SetPinMode (S1_C , DIO_MODE_OUTPUT);
	Dio_SetPinMode (S1_D , DIO_MODE_OUTPUT);
}



void CLOCK_Display(u8 number)
{
	if (number <= 9)
	{
    	Dio_SetPinLevel(S2_A ,GET_BIT(number , 0) );
  	    Dio_SetPinLevel(S2_B ,GET_BIT(number , 1) );
	    Dio_SetPinLevel(S2_C ,GET_BIT(number , 2) );
  	    Dio_SetPinLevel(S2_D ,GET_BIT(number , 3) );
    }
}

void ALARM_Display(u8 number)
{
	if (number <= 9)
	{
    	Dio_SetPinLevel(S1_A ,GET_BIT(number , 0) );
  	    Dio_SetPinLevel(S1_B ,GET_BIT(number , 1) );
	    Dio_SetPinLevel(S1_C ,GET_BIT(number , 2) );
  	    Dio_SetPinLevel(S1_D ,GET_BIT(number , 3) );
    }
}


void CLOCK_Disable_All(void)
{
	Dio_SetPinLevel(S2_H2 , DIO_LOW);
	Dio_SetPinLevel(S2_H1 , DIO_LOW);
	Dio_SetPinLevel(S2_M2 , DIO_LOW);
	Dio_SetPinLevel(S2_M1 , DIO_LOW);
	Dio_SetPinLevel(S2_S2 , DIO_LOW);
	Dio_SetPinLevel(S2_S1 , DIO_LOW);
}

void ALARM_Disable_All(void)
{
	Dio_SetPinLevel(S1_H2 , DIO_LOW);
	Dio_SetPinLevel(S1_H1 , DIO_LOW);
	Dio_SetPinLevel(S1_M2 , DIO_LOW);
	Dio_SetPinLevel(S1_M1 , DIO_LOW);
}


void CLOCK_Enable_All(void)
{
	Dio_SetPinLevel(S2_H2 , DIO_HIGH);
	Dio_SetPinLevel(S2_H1 , DIO_HIGH);
	Dio_SetPinLevel(S2_M2 , DIO_HIGH);
	Dio_SetPinLevel(S2_M1 , DIO_HIGH);
	Dio_SetPinLevel(S2_S2 , DIO_HIGH);
	Dio_SetPinLevel(S2_S1 , DIO_HIGH);
}
void ALARM_Enable_All(void)
{
	Dio_SetPinLevel(S1_H2 , DIO_HIGH);
	Dio_SetPinLevel(S1_H1 , DIO_HIGH);
	Dio_SetPinLevel(S1_M2 , DIO_HIGH);
	Dio_SetPinLevel(S1_M1 , DIO_HIGH);
}






