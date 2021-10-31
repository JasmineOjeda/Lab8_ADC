/*	Author: Jasmine Ojeda jojed016@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab 8  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: https://youtube.com/shorts/rH4uj528Yow?feature=share
 *
 *	NOTE: Recording with phone, and flashlight is on phone. 
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRB = 0xFF; PORTB = 0x00;
    DDRD = 0xFF; PORTD = 0x00;

    unsigned char tmp_B = 0x00;
    unsigned short x;
    
    ADC_init();
    /* Insert your solution below */
    while (1) {
        x = ADC;
        
	if (x >= 110) {
            tmp_B = 0xFF;
	}
	else if (x >= 96) {
            tmp_B = 0x7F;
	}
	else if (x >= 82) {
	    tmp_B = 0x3F;
	}
	else if (x >= 68) {
            tmp_B = 0x1F;
        }
        else if (x >= 55) {
            tmp_B = 0x0F;
        }
        else if (x >= 41) {
            tmp_B = 0x07;
        }
        else if (x >= 27) {
            tmp_B = 0x03;
        }
	else if (x >= 13) {
            tmp_B = 0x01;
        }
        else {
            tmp_B = 0x00;
        }

	PORTB = tmp_B;
    }
    return 1;
}
