#include "gpio.h"
#include "timer.h"
#include "peripheral.h"
#include "clock.h"
#include "common.h"
#include "utilities.h"

int main(void) {
	WDTCTL = WDTPW + WDTHOLD; // Stop WDT

	ADC10CTL0 = (SREF_0 | ADC10SHT_2 | ADC10ON);
	ADC10CTL1 = (INCH_0 | ADC10SSEL_3 | ADC10DIV_7);
	ADC10AE0 |= BIT0;

	setupDigitalOscillator();
	initializeUART(4, 5, PERIPHERAL_SMCLK, 104);

	__enable_interrupt();
	int current = 1001;
	while (1) {
		ADC10CTL0 |= ENC + ADC10SC; // Sampling and conversion start
		while(ADC10CTL1 & ADC10BUSY); // Wait while ADC is busy
		unsigned int adc_result = ADC10MEM;
		char* intString = uint16ToString(adc_result);
		sendUARTChar("intString: ");
		sendUARTChar(intString);
		sendUARTChar(newline);
		current = current + 1;
		__delay_cycles(1000000);
	}
}
