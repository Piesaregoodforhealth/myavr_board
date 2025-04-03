#define F_CPU 16000000
#include <avr\io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "docycle.h"
#include "IExecutable.h"



void operator delete(void* ptr, unsigned int) noexcept {
	free(ptr);
}
void operator delete(void* ptr) noexcept {
	free(ptr);
}




extern "C" void __cxa_pure_virtual() {
	while (1);  // Infinite loop to prevent unexpected behavior
}



float adc_value = 0;
float cycle_divider=0;
uint16_t cycle_counter=0;



void variable_delay_ms(int ms) {
 for (int i = 0; i < ms; i++) {
	_delay_ms(1); 
 }
}

/*
void sharetime(uint8_t cycletime, uint16_t adcvalue, uint8_t channel ) {
	
		float b = 1.0*adcvalue;
		float a=1.0*(b/1023);
	
	float c = 1.0*cycletime;
	float delay1=1.0*c*a;
		PORTB |= (1 << PB0);
		 variable_delay_ms(delay1);

	
	int delay2=c-delay1;
		PORTB &= ~(1 << PB0); 
		variable_delay_ms(delay2);
		
	
}
*/





int main(void) {
	DDRB |= (1 << PB0);
	DDRF &= ~(1 << PF0);
	DDRB |= (1 << PB1);
	DDRF &= ~(1 << PF1);
	DDRB |= (1 << PB2);
	DDRF &= ~(1 << PF2);

	ADMUX = (1 << REFS0);
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

	// Correct way: instantiate objects
	DoCycle mycycle0(PF0, PORTB, PB0, 20);
	DoCycle mycycle1(PF1, PORTB, PB1, 20);
	DoCycle mycycle2(PF2, PORTB, PB2, 20);

	while (1) {
		_delay_ms(1);
		cycle_counter++;
		mycycle0.doExec(cycle_counter);
		mycycle1.doExec(cycle_counter);
		mycycle2.doExec(cycle_counter);
	}

	return 0;
}

//timer atmega почитать + сделать таймер с базером





