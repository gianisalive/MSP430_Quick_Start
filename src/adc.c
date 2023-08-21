#include "adc.h"

void initializeADC(char pin) {
  char selectedPin = 1 << pin;
  ADC_CONTROL_0 = (AVCC_AVSS_REFERECE | ADC_SAMPLE_HOLD_16CLOCK | ADC_ON);
	ADC_CONTROL_1 = (selectedPin | ADC_CLOCK_SMCLK | ADC_CLOCK_DIVID_7);
	ADC_0_ENABLE |= BIT0;
}

int readADC() {
  ADC_CONTROL_0 |= ADC_CONVERSION_ENABLE + ADC_CONVERSION_START;
  while(ADC_CONTROL_1 & ADC_BUSY);
  return ADC_RECEIVE_BUFFER;
}
