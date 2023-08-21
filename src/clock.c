#include "clock.h"

void setupDigitalOscillator() {
  DIGITAL_OSCILLATOR = 0;
  DIGITAL_OSCILLATOR = OSCILLATION_1MHZ;
  BASIC_CLOCK_1 = BASIC_CLOCK_1MHZ;
}
