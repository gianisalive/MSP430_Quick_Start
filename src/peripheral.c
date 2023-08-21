#include "peripheral.h"

// Based on section 15.3.1 on MSP430 User Guide
void initializeUART(int rxPin, int txPin, int clockSource, int clockDivide) {
  int rxPinSelect = 1 << rxPin;
  int txPinSelect = 1 << txPin;
  PORT_3_SELECT |= (rxPinSelect | txPinSelect);
  ASYNC_DATA_CONTROL_1 |= clockSource;
  ASYNC_BAUD_LOWER_8_BITS = clockDivide;
  ASYNC_BAUD_UPPER_8_BITS = 0;
  ASYNC_DATA_CONTROL_1 &= ~PERIPHERAL_STATE_RESET;
}

void sendUARTChar(char data[]) {
  for (int i = 0; data[i] != '\0'; i += 1) {
    // Only send when interrupt bit is cleared
    while(
      (
        MASKABLE_INTERRUPT_FLAG
        & ASYNC_SEND_INTERRUPT_FLAG
      ) != ASYNC_TX_PENDING
    );
    ASYNC_SEND_BUFFER = data[i];
  }
}

void initializeSPI(int dataOutPin, int dataInPin, int clockSource) {
  int dataOutPinSelect = 1 << dataOutPin;
  int dataInPinSelect = 1 << dataInPin;
  // Master out
  PORT_3_SELECT |= dataOutPinSelect;
  // Master in
  PORT_3_SELECT |= dataInPinSelect;
  // SPI clock output
  PORT_3_SELECT |= 1 << 3;
  SYNC_DATA_CONTROL_0 |= (MOST_SIGNIFICANT_BIT | MASTER_SELECT | SYNCHRONOUS_ENABLE);
  SYNC_DATA_CONTROL_1 |= clockSource;
  SYNC_DATA_CONTROL_1 &= ~PERIPHERAL_STATE_RESET;
}

void sendSPIData(char data) {
  while (
    (
      MASKABLE_INTERRUPT_FLAG
      & SYNC_SEND_INTERRUPT_FLAG
    ) != SYNC_TX_PENDING
  );
  SYNC_SEND_BUFFER = data;
}

// Based on section 17.3.4.2.1 on MSP430 User Guide
void initializeI2C(int dataPin, int clockPin, int clockSource) {
  int dataPinSelect = 1 << dataPin;
  int clockPinSelect = 1 << clockPin;
  PORT_3_SELECT |= dataPinSelect;
  PORT_3_SELECT |= clockPinSelect;
  SYNC_DATA_CONTROL_1 |= PERIPHERAL_STATE_RESET;
  SYNC_DATA_CONTROL_0 |= (MASTER_SELECT | SYNCHRONOUS_ENABLE | I2C_SELECT);
  SYNC_DATA_CONTROL_1 |= (clockSource | PERIPHERAL_STATE_RESET);
  SYNC_BAUD_LOWER_8_BITS = 10;
  SYNC_BAUD_UPPER_8_BITS = 0;
  SYNC_DATA_CONTROL_1 &= ~PERIPHERAL_STATE_RESET;
}

void I2CStartSend(char slaveAddress) {
  UCB0I2CSA = slaveAddress;
  UCB0CTL1 |= UCTR + UCTXSTT;
}

void I2CWrite(char command) {
  while ((IFG2 & UCB0TXIFG) != SYNC_TX_PENDING);
  UCB0TXBUF = command;
  while ((IFG2 & UCB0TXIFG) != SYNC_TX_PENDING);
  UCB0CTL1 |= UCTXSTP;
  while (UCB0CTL1 & UCTXSTP);
}

char I2CRead(char slaveAddress) {
  UCB0I2CSA = slaveAddress;
  UCB0CTL1 &= ~UCTR;
  UCB0CTL1 |= UCTXSTT;
  while (UCB0CTL1 & UCTXSTT);
  UCB0CTL1 |= UCTXSTP;
  while (UCB0CTL1 & UCTXSTP);
  while((IFG2 & UCB0RXIFG) != SYNC_RX_PENDING);
  char readValue = SYNC_RECEIVE_BUFFER;
  return readValue;
}

void I2CStop() {
  UCB0CTL1 |= UCTXSTP;
  while (UCB0CTL1 & UCTXSTP);
}
