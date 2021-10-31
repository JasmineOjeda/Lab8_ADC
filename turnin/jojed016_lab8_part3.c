/*	Author: Jasmine Ojeda jojed016@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab 8  Exercise 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: https://youtube.com/shorts/CFtRBn7ZgSg?feature=share 
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
    unsigned short MAX = 110 / 2;

    ADC_init();
    /* Insert your solution below */
    while (1) {
        x = ADC;
        
	if (x >= MAX) {
            tmp_B = 0xFF;
	}
	else {
            tmp_B = 0x00;
        }

	PORTB = tmp_B;
    }
    return 1;
}
