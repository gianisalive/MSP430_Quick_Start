#ifndef __NECTAR_TIMER_
#define __NECTAR_TIMER_

#include "common.h"

/****************************************************
 * Timer0_A3
****************************************************/
#define TIMER_1                       1
/* Control egisters */
#define TIMER_1_CONTROL               TA0CTL
#define TIMER_1_VECTOR                TA0IV
#define TIMER_1_COUNTER               TA0R
#define TIMER_1_COUNTER_INTERRUPT     TAIE
#define TIMER_1_OVERFLOW              TA0IV_TAIFG

#define TIMER_1_CONTROL_0              0
#define TIMER_1_CONTROL_1              1
#define TIMER_1_CONTROL_2              2
#define TIMER_1_CONTROL_SELECT_0      TA0CCTL0
#define TIMER_1_CONTROL_SELECT_1      TA0CCTL1
#define TIMER_1_CONTROL_SELECT_2      TA0CCTL2

#define TIMER_1_VALUE_0               0
#define TIMER_1_VALUE_1               1
#define TIMER_1_VALUE_2               2
#define TIMER_1_VALUE_SELECT_0        TA0CCR0
#define TIMER_1_VALUE_SELECT_1        TA0CCR1
#define TIMER_1_VALUE_SELECT_2        TA0CCR2

/* Timer Interrupt */
#define TIMER_1_CONTROL_INTERRUPT     CCIE

/* Clock Select */
#define TIMER_TACLK                   TASSEL_0
#define TIMER_ACLK                    TASSEL_1
#define TIMER_SMCLK                   TASSEL_2
#define TIMER_INCLK                   TASSEL_3

/* Clock Divider, aka Prescaler */
#define TIMER_DIVIDE_1                ID_0
#define TIMER_DIVIDE_2                ID_1
#define TIMER_DIVIDE_4                ID_2
#define TIMER_DIVIDE_8                ID_3

/* Timer Interrupt Mode */
#define TIMER_STOP                    MC_0
#define TIMER_UP_TO_SET_TIME          MC_1
#define TIMER_CONTINUOUS              MC_2
#define TIMER_UP_DOWN                 MC_3

/* Timer Capture/Compare Control */
#define TIMER_CAPTURE                 CAP

/* Timer Compare Output */
#define TIMER_OUTPUT_CLEAR            OUTMOD_0
#define TIMER_OUTPUT_HIGH             OUTMOD_1
#define TIMER_OUTPUT_TOGGLE_RESET     OUTMOD_2
#define TIMER_OUTPUT_SET_RESET        OUTMOD_3
#define TIMER_OUTPUT_TOGGLE           OUTMOD_4
#define TIMER_OUTPUT_RESET            OUTMOD_5
#define TIMER_OUTPUT_TOGGLE_SET       OUTMOD_6
#define TIMER_OUTPUT_RESET_SET        OUTMOD_7

/* Timer Capture Input */
#define TIMER_CAPTURE_INPUT_1         CCIS_0
#define TIMER_CAPTURE_INPUT_2         CCIS_1

/* Timer Capture Edge */
#define TIMER_CAPTURE_EDGE_HIGH       CM_1
#define TIMER_CAPTURE_EDGE_LOW        CM_2
#define TIMER_CAPTURE_EDGE_BOTH       CM_3

void setInterruptTimer(int timer, int source, int countMode, int prescaler, int enableISR);
void setCompareClock(int control, int outputMode, int enableISR);
void setCaptureClock(int control, int inputPin, int edgeCapture, int enableISR);
void setInterruptClock(int timer, int interruptTime);
void createPulseWidthModulation(int frequency, int dutyCycle);

#endif
