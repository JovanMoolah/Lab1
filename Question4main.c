
//#include <p18cxxx.h>
#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <p18f4550.h>
#include <usart.h>
#include "serial.h"


//#include <windows.h>
//#include <unistd.h>
//#include <sys/times.h> // gcc cyclicx.c -o cyclicx
#define SLOTX 4
#define CYCLEX 5
#define SLOT_T 5000 // 5 sec slot time


#define _XTAL_FREQ   2000000




void timer_delay (void);

#pragma code InterruptHanderHigh = 0x08

void InterruptVectorHigh (void)

{
  _asm goto timer_delay _endasm
}

#pragma code
#pragma interrupt timer_delay

void timer_delay()
{
    INTCONbits.GIE = 0;
    
    if (PIR1bits.TMR1IF == 1)  
    {
        TMR1H = 0x08;
        TMR1L = 0x00;
    }
    T1CONbits.TMR1ON = 0;
}


void LetSleep(void)
{   
   
    INTCONbits.PEIE =1;
    INTCONbits.GIE = 1;
    TMR1H = 0x00;
    TMR1L = 0x00;
    T1CONbits.TMR1ON = 0;
    PIR1bits.TMR1IF = 0;
    T1CONbits.TMR1ON = 1;
    Sleep ();
   
}

void serial(void *pvParameters)
{
    for(;;)
    {
        print_line_better("my string\r\n");
    }
}
void hardware_initialize(void)
{
    TRISB = 0;
    PORTBbits.RB0=0;
    
    initialize_USART();
    //for(;;)
    //{
    print_line_better("my string\r\n");
    //}
    LetSleep;

}

void taks();
void one(){
    print_line_better("Task 1 running\r\n");
    LetSleep;
}

void two(){
    print_line_better("task 2 running\r\n");
    LetSleep;
}

void three()
{
    print_line_better("task 3 running\r\n");
    LetSleep;
}

void four()
{
    print_line_better("task 4 running\r\n");
    LetSleep;
}

void five()
{
    print_line_better("task 5 running\r\n");
    LetSleep;
}



void main(void) {
    
    T1CONbits.TMR1CS = 0;
    T1CONbits.T1CKPS0 = 1;
    T1CONbits.T1CKPS1 = 1; 
    PIE1bits.TMR1IE = 1;    
    hardware_initialize();
    one;
    two;
    three;
    four;
    five;
    PORTBbits.RB6 = 0;
    TRISBbits.TRISB6 = 0;
    
    

 
 }



