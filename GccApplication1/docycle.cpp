#include <avr\io.h>
#include "docycle.h"

uint16_t ADC_Read(uint8_t channel) {
	// Select ADC channel (clear MUX bits first)
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);

	// Start conversion
	ADCSRA |= (1 << ADSC);

	// Wait for conversion to complete
	while (ADCSRA & (1 << ADSC));

	// Return 10-bit ADC result
	return ADC;
}




DoCycle::DoCycle(uint8_t input_pin, volatile uint8_t &output_port, uint8_t output_pin, int cycle_duration)
: 
	minput_pin(input_pin), 
	moutput_port(output_port), 
	moutput_pin(output_pin), 
	mcycle_duration(cycle_duration) 
{}
	

	
void DoCycle::doExec(int cycle_counter) {
	uint16_t adc_value = ADC_Read(minput_pin);
	float cycle_divider = static_cast<float>(adc_value) / 1023.0f;

	if ((cycle_counter % mcycle_duration) < (mcycle_duration * cycle_divider)) {
		moutput_port |= (1 << moutput_pin);
		} else {
		moutput_port &= ~(1 << moutput_pin);
	}
	
}
