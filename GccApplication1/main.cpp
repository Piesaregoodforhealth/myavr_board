#define F_CPU 16000000
#include <avr\io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "docycle.h"
#include "IExecutable.h"









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

	DoCycle mycycle(PF0, PORTB,PINB0,20);

//myCycle(PF0, PORTB,PINB0,20);
//myCycle(PF1, PORTB,PINB1,20);
//myCycle(PF2, PORTB,PINB2,20);
	while (1) {
		_delay_ms(1);
	cycle_counter++;
//myCycle.doExec(cycle_counter);
//myCycle.doExec(cycle_counter);
//myCycle.doExec(cycle_counter);

	};
		
		
		
		//sharetime(20, ADC_Read(PF0),0 );
	return 0;
};





