#include "gpio.h"
#include "timer.h"
#include "peripheral.h"
#include "clock.h"
#include "common.h"
#include "utilities.h"

int main(void) {
	WDTCTL = WDTPW + WDTHOLD; // Stop WDT

	setupDigitalOscillator();
	initializeUART(4, 5, PERIPHERAL_SMCLK, 104);
	setDigitalIO(1, 0, OUTPUT, LOW);
	__enable_interrupt();

	while (1) {
		char* intString = uint16ToString(99);
		sendUARTChar("Hello World, Version");
		sendUARTChar(intString);
		sendUARTChar(newline);
		if (readDigitalInput(1, 0) == LOW) {
			setDigitalIO(1, 0, OUTPUT, HIGH);
		} else {
			setDigitalIO(1, 0, OUTPUT, LOW);
		}
		__delay_cycles(1000000);
	}
}
