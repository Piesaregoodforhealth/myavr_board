#ifndef DOCYCLE_H
#define DOCYCLE_H

#include <stdint.h>
#include "IExecutable.h"

class DoCycle : public IExecutable {
	public:
	DoCycle(uint8_t input_pin, volatile uint8_t &output_port, uint8_t output_pin, int cycle_duration);
	~DoCycle();
	void doExec(int cycle_counter) override;

	private:
	uint8_t minput_pin;
	volatile uint8_t &moutput_port;
	uint8_t moutput_pin;
	int mcycle_duration;
};

#endif // DOCYCLE_H
