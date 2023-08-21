#include "timer.h"

void setInterruptTimer(int timer, int source, int countMode, int prescaler, int enableISR) {
  volatile int *timerControl;
  volatile int selectedInterrupt;
  if (timer == TIMER_1) {
    timerControl = &TIMER_1_CONTROL;
    selectedInterrupt = TIMER_1_COUNTER_INTERRUPT;
  }
  *timerControl |= (source | countMode | prescaler | (enableISR == TRUE ? selectedInterrupt : 0x0));
}

void setCompareClock(int control, int outputMode, int enableISR) {
  volatile int *selectedControl;
  volatile int selectedInterrupt;
  if (control == TIMER_1_CONTROL_0) {
    selectedControl = &TIMER_1_CONTROL_SELECT_0;
    selectedInterrupt = TIMER_1_CONTROL_INTERRUPT;
  }
  if (control == TIMER_1_CONTROL_1) {
    selectedControl = &TIMER_1_CONTROL_SELECT_1;
    selectedInterrupt = TIMER_1_CONTROL_INTERRUPT;
  }
  if (control == TIMER_1_CONTROL_2) {
    selectedControl = &TIMER_1_CONTROL_SELECT_2;
    selectedInterrupt = TIMER_1_CONTROL_INTERRUPT;
  }
  *selectedControl &= ~TIMER_CAPTURE;
  *selectedControl |= (outputMode | (enableISR == TRUE ? selectedInterrupt : 0x0));
}

void setCaptureClock(int control, int inputPin, int edgeCapture, int enableISR) {
  volatile int *selectedControl;
  volatile int selectedInterrupt;
  if (control == TIMER_1_CONTROL_0) {
    selectedControl = &TIMER_1_CONTROL_SELECT_0;
    selectedInterrupt = TIMER_1_CONTROL_INTERRUPT;
  }
  if (control == TIMER_1_CONTROL_1) {
    selectedControl = &TIMER_1_CONTROL_SELECT_1;
    selectedInterrupt = TIMER_1_CONTROL_INTERRUPT;
  }
  if (control == TIMER_1_CONTROL_2) {
    selectedControl = &TIMER_1_CONTROL_SELECT_2;
    selectedInterrupt = TIMER_1_CONTROL_INTERRUPT;
  }
  *selectedControl |= TIMER_CAPTURE;
  *selectedControl |= (inputPin | edgeCapture | (enableISR == TRUE ? selectedInterrupt : 0x0));
}

void setInterruptClock(int timer, int interruptTime) {
  volatile int *selectedTimer;
  if (timer == TIMER_1_VALUE_0) {
    selectedTimer = &TIMER_1_VALUE_SELECT_0;
  }
  if (timer == TIMER_1_VALUE_1) {
    selectedTimer = &TIMER_1_VALUE_SELECT_1;
  }
  if (timer == TIMER_1_VALUE_2) {
    selectedTimer = &TIMER_1_VALUE_SELECT_2;
  }
  *selectedTimer = interruptTime;
}

void createPulseWidthModulation(int frequency, int dutyCycle) {
  int calculatedDutyCycle = frequency - (frequency / dutyCycle);
  setInterruptClock(TIMER_1_VALUE_1, calculatedDutyCycle);
	setInterruptClock(TIMER_1_VALUE_0, frequency);
}

// timerFrequency = clockIn/(prescaler * compareReg)
void __attribute__((interrupt(TIMER0_A0_VECTOR))) TIMER_A0_ISR(void) {
}

void __attribute__((interrupt(TIMER0_A1_VECTOR))) TIMER_A1_ISR(void) {
  switch (__even_in_range(TIMER_1_VECTOR, TIMER_1_OVERFLOW)) {
    case 0: // No interrupt
      break;
    case 2: // CCR1 interrupt
      break;
    case 4: // CCR2 interrupt
      break;
    case TIMER_1_OVERFLOW: // Overflow not used
      break;
    default:
      break;
  }
}
