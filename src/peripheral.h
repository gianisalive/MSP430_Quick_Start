#ifndef __NECTAR_PERIPHERAL_
#define __NECTAR_PERIPHERAL_

#include "common.h"

/****************************************************
 * Common
****************************************************/
/* Clock Source */
#define PERIPHERAL_UCLK                     UCSSEL_0
#define PERIPHERAL_ACLK                     UCSSEL_1
#define PERIPHERAL_SMCLK                    UCSSEL_2

/* 0:LSB, 1:MSB */
#define MOST_SIGNIFICANT_BIT                UCMSB

/* 0:slave, 1:master */
#define MASTER_SELECT                       UCMST

/* 0:UART, 1:SPI, I2C */
#define SYNCHRONOUS_ENABLE                  UCSYNC
#define PERIPHERAL_STATE_RESET              UCSWRST

/* Mode During Synchronous Mode */
#define SPI_3_PIN_SELECT                    UCMODE_0
#define SPI_4_PIN_ACTIVE_LOW                UCMODE_1
#define SPI_4_PIN_ACTIVE_HIGH               UCMODE_2
#define I2C_SELECT                          UCMODE_3

/* I2C Transmit */
#define I2C_TRANSMIT_START                  UCTXSTT
#define I2C_TRANSMIT_STOP                   UCTXSTP

/****************************************************
 * A0, UART
****************************************************/
/* Control Register */
#define ASYNC_MODULATION_CONTROL            UCA0MCTL
#define ASYNC_DATA_CONTROL_0                UCA0CTL0
#define ASYNC_DATA_CONTROL_1                UCA0CTL1

/* UART Baudrate */
#define ASYNC_BAUD_LOWER_8_BITS             UCA0BR0
#define ASYNC_BAUD_UPPER_8_BITS             UCA0BR1

/* A0 Data Buffers */
#define ASYNC_RECEIVE_BUFFER                UCA0RXBUF
#define ASYNC_SEND_BUFFER                   UCA0TXBUF

/* Interrupt Enable */
#define ASYNC_RECEIVE_INTERRUPT_ENABLE      UCA0RXIE
#define ASYNC_SEND_INTERRUPT_ENABLE         UCA0TXIE

/* Interrupt Flag */
#define ASYNC_RECEIVE_INTERRUPT_FLAG        UCA0RXIFG
#define ASYNC_SEND_INTERRUPT_FLAG           UCA0TXIFG

#define ASYNC_TX_PENDING	                  0x02
#define ASYNC_RX_PENDING	                  0x01

/****************************************************
 * B0, (SPI, I2C)
****************************************************/
/* B0 Control Register */
#define SYNC_DATA_CONTROL_0                 UCB0CTL0
#define SYNC_DATA_CONTROL_1                 UCB0CTL1

/* UART Baudrate */
#define SYNC_BAUD_LOWER_8_BITS              UCB0BR0
#define SYNC_BAUD_UPPER_8_BITS              UCB0BR1

/* Data Buffers */
#define SYNC_RECEIVE_BUFFER                 UCB0RXBUF
#define SYNC_SEND_BUFFER                    UCB0TXBUF

/* Interrupt Enable */
#define SYNC_RECEIVE_INTERRUPT_ENABLE       UCB0RXIE
#define SYNC_SEND_INTERRUPT_ENABLE          UCB0TXIE

/* Interrupt Flag */
#define SYNC_RECEIVE_INTERRUPT_FLAG         UCB0RXIFG
#define SYNC_SEND_INTERRUPT_FLAG            UCB0TXIFG

/* Set Slave Address */
#define SYNC_I2C_SLAVE_ADDRESS              UCB0I2CSA

#define SYNC_TX_PENDING	                    0x08
#define SYNC_RX_PENDING	                    0x04


void initializeUART(int rxPin, int txPin, int clock, int baudrate);
void sendUARTChar(char data[]);
void initializeSPI(int dataOutPin, int dataInPin, int clock);
void sendSPIData(char data);
void initializeI2C(int dataPin, int clockPin, int clockSource);
void I2CStartSend(char slaveAddress);
void I2CWrite(char command);
char I2CRead(char slaveAddress);
void I2CStop();

#endif