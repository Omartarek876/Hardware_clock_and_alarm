# Hardware_clock_and_alarm

a real time digital clock and alarm project based on the concepts of timer and interrupt using Atmega32 , 6 multiplexed seven segments for the clock , 4 multiplexed seven segments for the alarm and their decoders 

The clock : 

It is incorporating real time clock functionality hours , minutes and seconds each in 2 seven segments

The alarm : 

The user can set it to certain time ( hours & minutes ) using 4 buttons 
 BUT1 => to increase minutes
 BUT2 => to decrease minutes
 BUT3 => to increase hours 
 BUT4 => to decrease hours 

and another two buttons one to save the time in the alarm and another one to stop the alarm ( stop the led display) 

and the led will display when the clock time reaches to the saved time in the alarm 

used drivers : 

     -   DIO 
     -   TIMER ( TIM0 )  
     -   INTERRUPT 
