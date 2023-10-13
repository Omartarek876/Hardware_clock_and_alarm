/*
 * main.c
 *
 *  Created on: Oct 12, 2023
 *      Author: omar tarek
 */


#include "StdTypes.h"
#include "Registers.h"
#include "macros.h"
#include "Delay.h"
#include "Dio.h"
#include "Interrupts.h"
#include "Gie.h"
#include "ExtInt.h"
#include "Seven_Segment.h"
#include "Gpt.h"

volatile counter = 0;
volatile seconds= 35;
volatile minutes = 59;
volatile hours = 23;


volatile minuteA = 0;
volatile hourA = 0;

volatile SAVE_minuteA = -1;
volatile SAVE_hourA  = -1;

u8 SAVE_flag = 0;
u8 arr[4] = {0};
void Handler_Tim0_Ovf (void)
{
    TCNT0 = 6;
    counter++;
    if (counter == 3000) // 4000
      {
    	  counter = 0;
    	  seconds++;
    	  if (seconds == 60)
    	  {
    		  minutes++;
    		  seconds = 0;
    	  }
    	  if (minutes == 60)
    	  {
    		  hours++;
    		  minutes = 0;
    	  }
    	  if (hours == 24)
    	  {
    		  hours = 0;
    	  }

    	  if (SAVE_minuteA == minutes  && SAVE_hourA == hours && SAVE_flag == 1)
    	  {
    		  Dio_SetPinLevel (LED , DIO_HIGH);
    	  }



      }
    if (counter % 800 == 0)
    {
        if(Dio_ReadPinLevel(BUT1) == 0)
         {
         	    minuteA++;
         	    if(minuteA == 60)
         	    {
           		  minuteA = 0 ;
         	    }
         }

        if(Dio_ReadPinLevel(BUT2) == 0)
         {
          	    minuteA--;
          	    if(minuteA == 0)
          	    {
            		  minuteA = 59;
          	    }
         }


        if(Dio_ReadPinLevel(BUT3) == 0)
         {
          	  hourA++;
          	  if(hourA == 24)
          	  {
          		  hourA = 0 ;
          	  }
         }

        if(Dio_ReadPinLevel(BUT4) == 0)
         {

          	  hourA--;
          	  if(hourA == 0)
          	  {
          		  hourA = 23 ;
          	  }

         }

    }
}

int main (void)
{
	CLOCK_INIT();
	ALARM_INIT();

	Gpt_Init(&Gpt_Configuration);
	Gie_Enable();

    Dio_SetPinMode(GPT_PIN_OC0, DIO_MODE_OUTPUT);
    TCNT0 = 6;
    Gpt_EnableInterrupt(GPT_INT_SOURCE_TIM0_OVF);
    Gpt_SetCallback(GPT_INT_SOURCE_TIM0_OVF, Handler_Tim0_Ovf);

    Dio_SetPinMode(BUT1,DIO_MODE_INPUT_PULLUP);
    Dio_SetPinMode(BUT2,DIO_MODE_INPUT_PULLUP);
    Dio_SetPinMode(BUT3,DIO_MODE_INPUT_PULLUP);
    Dio_SetPinMode(BUT4,DIO_MODE_INPUT_PULLUP);

    Dio_SetPinMode(LED, DIO_MODE_OUTPUT);

    while (1)
    {

    	   CLOCK_Disable_All();
    	   CLOCK_Display(seconds%10);
           Dio_SetPinLevel(S2_S1 ,DIO_HIGH );
           _delay_us(0.5);
           Dio_SetPinLevel(S2_S1 ,DIO_LOW );

           CLOCK_Display(seconds/10);
           Dio_SetPinLevel(S2_S2 ,DIO_HIGH );
           _delay_us(0.5);
           Dio_SetPinLevel(S2_S2 ,DIO_LOW );


           CLOCK_Display(minutes%10);
           Dio_SetPinLevel(S2_M1 ,DIO_HIGH );
           _delay_us(0.5);
           Dio_SetPinLevel(S2_M1 ,DIO_LOW );


           CLOCK_Display(minutes/10);
           Dio_SetPinLevel(S2_M2 ,DIO_HIGH );
           _delay_us(0.5);
           Dio_SetPinLevel(S2_M2 ,DIO_LOW );


           CLOCK_Display(hours%10);
           Dio_SetPinLevel(S2_H1 ,DIO_HIGH );
           _delay_us(0.5);
           Dio_SetPinLevel(S2_H1 ,DIO_LOW );


           CLOCK_Display(hours/10);
           Dio_SetPinLevel(S2_H2 ,DIO_HIGH );
           _delay_us(0.5);
           Dio_SetPinLevel(S2_H2 ,DIO_LOW );
           // CLOCK_Enable_All();

          ///////*****************************************************/////////////////

        ALARM_Disable_All();
   	   ALARM_Display(minuteA%10);
        Dio_SetPinLevel(S1_M1 ,DIO_HIGH );
        _delay_us(1);
        Dio_SetPinLevel(S1_M1 ,DIO_LOW );

  	   ALARM_Display(minuteA/10);
        Dio_SetPinLevel(S1_M2 ,DIO_HIGH );
        _delay_us(1);
        Dio_SetPinLevel(S1_M2 ,DIO_LOW );


  	   ALARM_Display(hourA%10);
        Dio_SetPinLevel(S1_H1 ,DIO_HIGH );
        _delay_us(1);
        Dio_SetPinLevel(S1_H1 ,DIO_LOW );


  	    ALARM_Display(hourA/10);
        Dio_SetPinLevel(S1_H2 ,DIO_HIGH );
        _delay_us(1);
        Dio_SetPinLevel(S1_H2 ,DIO_LOW );



          if(Dio_ReadPinLevel(SAVE) == 1)
          {
        	  SAVE_minuteA = minuteA;
        	  SAVE_hourA   = hourA;
        	  SAVE_flag = 1;
          }


          if(Dio_ReadPinLevel(STOP) == 1)
          {
    		  Dio_SetPinLevel (LED , DIO_LOW);
    		  SAVE_flag = 0;
          }


    }

}

