/*
 * File:   newmain.c
 * Author: Jovan
 *
 * Created on October 6, 2024, 6:26 PM
 */


#include <p18cxxx.h>
//#include <stdio.h>>




#define unsigned int value = 500;
#define FALSE (1==0)
#define TRUE (1==1)



void same_char (void)
{
    if (PIR1bits.RCIF == 1) 
    {
        return TRUE;
    }
}

unsigned int interval ();

const int ON = 1;
const int OFF = 0;





void main(void) {
    
  enum 
{
    ON, OFF 
} state;

int state = OFF; 


    switch (state) 
    {
        case ON:
            if (same_char && interval > value )
            {
                state = OFF;
            }
            if (!same_char)
            {
                state = OFF ;
            }
            if (interval <value)
            {
                state = ON;
            }
            break;
            
        case OFF:
            if (same_char && interval > value)
            {
                state = ON; 
            }
            if  (!same_char)
            {
                state = ON; 
            }
            if (interval <value)
            {
                state = OFF; 
            }
            break; 
            
        default: 
            state = OFF; 
            break;      
    }
    return;
}
