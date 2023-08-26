#ifndef __ADC_
#define __ADC_
#include "common.h"
/****************************************************
 * Clock Module
****************************************************/

// Control 0
#define ADC_CONTROL_0                 ADC10CTL0

#define AVCC_AVSS_REFERECE            SREF_0

#define ADC_SAMPLE_HOLD_4CLOCK        ADC10SHT_0
#define ADC_SAMPLE_HOLD_8CLOCK        ADC10SHT_1
#define ADC_SAMPLE_HOLD_16CLOCK       ADC10SHT_2
#define ADC_SAMPLE_HOLD_64CLOCK       ADC10SHT_3

#define ADC_ON                        ADC10ON
#define ADC_CONVERSION_ENABLE         ENC
#define ADC_CONVERSION_START          ADC10SC

// Control 1
#define ADC_CONTROL_1                 ADC10CTL1

#define ADC_INPUT_1                   INCH_0
#define ADC_INPUT_2                   INCH_1
#define ADC_INPUT_3                   INCH_2
#define ADC_INPUT_4                   INCH_3
#define ADC_INPUT_5                   INCH_4
#define ADC_INPUT_6                   INCH_5

#define ADC_CLOCK_ADCOSC              ADC10SSEL_0
#define ADC_CLOCK_ACLK                ADC10SSEL_1
#define ADC_CLOCK_MCLK                ADC10SSEL_2
#define ADC_CLOCK_SMCLK               ADC10SSEL_3

#define ADC_CLOCK_DIVID_0             ADC10DIV_0
#define ADC_CLOCK_DIVID_1             ADC10DIV_1
#define ADC_CLOCK_DIVID_2             ADC10DIV_2
#define ADC_CLOCK_DIVID_3             ADC10DIV_3
#define ADC_CLOCK_DIVID_4             ADC10DIV_4
#define ADC_CLOCK_DIVID_5             ADC10DIV_5
#define ADC_CLOCK_DIVID_6             ADC10DIV_6
#define ADC_CLOCK_DIVID_7             ADC10DIV_7

#define ADC_BUSY                      ADC10BUSY

// ADC Input enable
#define ADC_0_ENABLE                  ADC10AE0

// ADC Memory
#define ADC_RECEIVE_BUFFER            ADC10MEM

#endif
