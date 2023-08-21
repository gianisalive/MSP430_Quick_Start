#ifndef __NECTAR_GPIO_
#define __NECTAR_GPIO_

#include "common.h"

/****************************************************
 * GPIO
****************************************************/
/* Enable Pull Up/Down Resistor for Input */
#define ENABLE_RES(port) PORT_##port##_RESISTOR
#define PORT_1_RESISTOR           P1REN
#define PORT_2_RESISTOR           P2REN

/* Set Output High/Low */
#define PORT_OUT(port) PORT_##port##_OUTPUT
#define PORT_1_OUTPUT             P1OUT
#define PORT_2_OUTPUT             P2OUT

/* Set Input High/Low */
#define PORT_IN(port) PORT_##port##_INPUT
#define PORT_1_INPUT              P1IN
#define PORT_2_INPUT              P2IN

/* Interrupt Vector, Used to Link Interrupt Function */
#define INTERRUPT_PORT(port) PORT_##port##_VECTOR
#define PORT_1_VECTOR             PORT1_VECTOR
#define PORT_2_VECTOR             PORT2_VECTOR

/* Interrupt Trigger Edge */
#define EDGE_SELECT(port) PORT_##port##_EDGE_SELECT
#define PORT_1_EDGE_SELECT        P1IES
#define PORT_2_EDGE_SELECT        P2IES

/* Interrupt Flag */
#define PORT_INTERRUPT_FLAG(port) PORT_##port##_INTERRUPT_FLAG
#define PORT_1_INTERRUPT_FLAG     P1IFG
#define PORT_2_INTERRUPT_FLAG     P2IFG

/* Enable Interrupt */
#define PORT_INTERRUPT_ENABLE(port) PORT_##port##_INTERRUPT_ENABLE
#define PORT_1_INTERRUPT_ENABLE   P1IE
#define PORT_2_INTERRUPT_ENABLE   P2IE

void setDigitalIO(int port, char pin, int mode, int state);
int readDigitalInput(int port, char pin);
void clearInterruptFlag(int port, char pin);
int isInterrupted(int port, char pin);
void digitalInterrupt(int port, char pin, int triggerEdge);

#endif