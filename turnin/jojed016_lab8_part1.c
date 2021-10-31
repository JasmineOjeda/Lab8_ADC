/*	Author: Jasmine Ojeda jojed016@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab 8  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: https://youtube.com/shorts/nmad4A9eDUM?feature=share
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
    unsigned char tmp_D = 0x00;
    unsigned short x;

    ADC_init();
    /* Insert your solution below */
    while (1) {
        x = ADC;

        tmp_B = (char)x;
	tmp_D = (char)((x & 0x0300) >> 8);

	PORTB = tmp_B;
	PORTD = tmp_D;
    }
    return 1;
}
