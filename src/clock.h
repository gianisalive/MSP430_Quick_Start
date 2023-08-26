#ifndef __CLOCK_
#define __CLOCK_

#include "common.h"

/****************************************************
 * Clock Module
****************************************************/
#define DIGITAL_OSCILLATOR    DCOCTL
#define BASIC_CLOCK_1         BCSCTL1

/* Calibration Data */
#define OSCILLATION_1MHZ     CALDCO_1MHZ
#define BASIC_CLOCK_1MHZ     CALBC1_1MHZ 

void setupDigitalOscillator();

#endif
