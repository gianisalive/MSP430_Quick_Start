#include "gpio.h"

void setDigitalIO(int port, char pin, int mode, int state) {
  volatile char *portDirection;
  volatile char *portResistor;
  volatile char *portOutput;
  char selectedPin = 1 << pin;
  if (port == 1) {
    portDirection = &PORT_DIR(1);
    portResistor = &ENABLE_RES(1);
    portOutput = &PORT_OUT(1);
  }
  if (port == 2) {
    portDirection = &PORT_DIR(2);
    portResistor = &ENABLE_RES(2);
    portOutput = &PORT_OUT(2);
  }
  if (mode == INPUT) {
    *portDirection &= ~selectedPin;
    *portResistor |= selectedPin;
  }
  if (mode == OUTPUT) {
    *portDirection |= selectedPin;
    *portResistor &= ~selectedPin;
  }
  if (state == HIGH) {
    *portOutput |= selectedPin;
  }
  if (state == LOW) {
    *portOutput &= ~selectedPin;
  }
}

int readDigitalInput(int port, char pin) {
  volatile char *portInput;
  char selectedPin = 1 << pin;
  if (port == 1) {
    portInput = &PORT_IN(1);
  }
  if (port == 2) {
    portInput = &PORT_IN(2);
  }
  if ((*portInput & selectedPin) == selectedPin) {
    return HIGH;
  }
  return LOW;
}

void clearInterruptFlag(int port, char pin) {
  volatile char *interruptFlag;
  char selectedPin = 1 << pin;
  if (port == 1) {
    interruptFlag = &PORT_INTERRUPT_FLAG(1);
  }
  if (port == 2) {
    interruptFlag = &PORT_INTERRUPT_FLAG(2);
  }
  *interruptFlag &= ~selectedPin;
}

bool isInterrupted(int port, char pin) {
  volatile char *interruptFlag;
  char selectedPin = 1 << pin;
  if (port == 1) {
    interruptFlag = &PORT_INTERRUPT_FLAG(1);
  }
  if (port == 2) {
    interruptFlag = &PORT_INTERRUPT_FLAG(2);
  }
  if ((*interruptFlag & selectedPin) == selectedPin) {
    return TRUE;
  }
  return FALSE;
}

void digitalInterrupt(int port, char pin, int triggerEdge) {
  volatile char *interruptEdge;
  volatile char *interruptEnable;
  char selectedPin = 1 << pin;
  if (port == 1) {
    interruptEdge = &EDGE_SELECT(1);
    interruptEnable = &PORT_INTERRUPT_ENABLE(1);
  }
  if (port == 2) {
    interruptEdge = &EDGE_SELECT(2);
    interruptEnable = &PORT_INTERRUPT_ENABLE(2);
  }
  if (triggerEdge == LOW) {
    *interruptEdge &= ~selectedPin;
  }
  if (triggerEdge == HIGH) {
    *interruptEdge &= ~selectedPin;
  }
  clearInterruptFlag(port, pin);
  *interruptEnable |= selectedPin;
}
