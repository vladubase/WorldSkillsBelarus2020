/****
	*	@name		GRIPPER
	*	@file 		Gripper.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>.
	*	@version	V1.0
	*	@date 		Created on 2020.09.09.
	*
	*	@brief 		This program is controlling the servo on gripper .
    *
    *   @note       Chip type               : ATtiny85
    *               AVR Core Clock frequency: 8,000000 MHz
    *               Memory model            : Small
    *               External RAM size       : 0
    *               Data Stack size         : 128     
*****/


/************************************** Includes **************************************/

#include    <tiny85.h>
#include    <delay.h>
#include    <stdint.h>
#include    <stdbool.h>


/*************************************** Defines **************************************/

#define     SIGNAL      PINB & (1 << DDB1)


/*********************************** Global Variables *********************************/

#define     MIN_PWM     40
#define     MAX_PWM     167   


/********************************* Function  prototypes *******************************/

void InitSys (void);


/**************************************** Main ****************************************/

void main (void) { 
    InitSys ();

    while (true) {
        // Read data on SIGNAL port
        if (SIGNAL) {
            // Close gripper
        	OCR0A = MAX_PWM;
        } else {
            // Open gripper
        	OCR0A = MIN_PWM;
        } 
        
        // Delay to minimize the influence of noise.
        delay_ms (1500);		
    }
}


/************************************* Functions **************************************/

void InitSys (void) {
    // Declare your local variables here
    
    // System Clock
    // Crystal Oscillator division factor: 32
        CLKPR=0x85;

    // Input/Output Ports initialization
    // Port B initialization
    // Func5=In Func4=In Func3=In Func2=In Func1=In Func0=Out 
    // State5=T State4=T State3=T State2=T State1=T State0=0 
        PORTB=0x00;
        DDRB=0x01;

    // Timer/Counter 0 initialization
    // Clock source: System Clock
    // Clock value: (System Clock / 256)
    // Mode: Fast PWM top=0xFF
    // OC0A output: Non-Inverted PWM
    // OC0B output: Disconnected
        TCCR0A=0x83;
        TCCR0B=0x04;
        TCNT0=0x00;
        OCR0A=0x00;
        OCR0B=0x00;
	/*
    // Timer/Counter 1 initialization
    // Clock source: System Clock
    // Clock value: Timer1 Stopped
    // Mode: Normal top=0xFF
    // OC1A output: Disconnected
    // OC1B output: Disconnected
    // Timer1 Overflow Interrupt: Off
    // Compare A Match Interrupt: Off
    // Compare B Match Interrupt: Off
        PLLCSR=0x00;

        TCCR1=0x00;
        GTCCR=0x00;
        TCNT1=0x00;
        OCR1A=0x00;
        OCR1B=0x00;
        OCR1C=0x00;

    // External Interrupt(s) initialization
    // INT0: Off
    // Interrupt on any change on pins PCINT0-5: Off
        GIMSK=0x00;
        MCUCR=0x00;
	
    // Timer(s)/Counter(s) Interrupt(s) initialization
    	TIMSK=0x00;

    // Universal Serial Interface initialization
    // Mode: Disabled
    // Clock source: Register & Counter=no clk.
    // USI Counter Overflow Interrupt: Off
        USICR=0x00;

    // Analog Comparator initialization
    // Analog Comparator: Off
        ACSR=0x80;
        ADCSRB=0x00;
        DIDR0=0x00;

    // ADC initialization
    // ADC disabled
        ADCSRA=0x00;  
	*/      
}
