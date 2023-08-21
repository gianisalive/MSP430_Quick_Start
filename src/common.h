#ifndef __NECTAR_COMMON_
#define __NECTAR_COMMON_
#include <msp430.h>

/****************************************************
 * Universal Variable
****************************************************/

/* DIY Boolean */
typedef int bool;
#define TRUE                        1
#define FALSE                       0

/* Digital State */
#define OUTPUT                      1
#define INPUT                       0
#define HIGH                        1
#define LOW                         0

/****************************************************
 * Port & Pin Select
****************************************************/
#define PORT_1_SELECT               P1SEL
#define PORT_1_SELECT2              P1SEL2
#define PORT_2_SELECT               P2SEL
#define PORT_2_SELECT2              P2SEL2
#define PORT_3_SELECT               P3SEL

/****************************************************
 * Port & Pin Direction
****************************************************/
#define PORT_DIR(port) PORT_##port##_DIRECTION
#define PORT_1_DIRECTION            P1DIR
#define PORT_2_DIRECTION            P2DIR

/****************************************************
 * Interrupt Enable
****************************************************/
#define MASKABLE_INTERRUPT          IE2
#define MASKABLE_INTERRUPT_FLAG     IFG2

/****************************************************
 * Interrupt Callback
****************************************************/
typedef void (*isr_function)();

#endif
