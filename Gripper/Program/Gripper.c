/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
� Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : Gripper 
Version : 
Date    : 09.09.2020
Author  : vladubase@gmail.com
Company : 
Comments: 


Chip type               : ATtiny85
AVR Core Clock frequency: 8,000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 128
*****************************************************/

#include <tiny85.h>
#include <delay.h>
#include <stdint.h>
#include <stdbool.h>

// Declare your global variables here

void main (void) {
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

	// DDRB |= (1 << DDB1);
    // PORTB |= (1 << 1);
                 
    while (true) {
//    	uint8_t i = 0;
//    	for (i = 30; i < 166; i++) {
//         	OCR0A = i;
//        	delay_ms (30);
//        }
    	OCR0A = 30;			
    }
}
 