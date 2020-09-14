/****
	*	@name		GRIPPER
	*	@file 		Gripper.c
	*
	*	@author 	Uladzislau 'vladubase' Dubatouka
	*				<vladubase@gmail.com>.
	*	@version	V1.0
	*	@date 		Created on 2020.09.09.
	*
	*	@brief 		This program is controlling the servo on gripper.
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

#define     MIN_PWM     60
#define     MAX_PWM     165   


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
        delay_ms (500);		
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
}
