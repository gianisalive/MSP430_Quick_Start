const char hexTable[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

char* charToHexString(char data[]) {
  static char hexStringBuffer[32];
  int bufferIndex = 0;
  // Reset buffer array
  for(int x = 0; x < 32; x += 1) {
    hexStringBuffer[x] = 0;
  }
  for (int i = 0; data[i] != '\0'; i += 1) {
    char valueLSB = (data[i] & 0x0F);
    char valueMSB = (data[i] & 0xF0) >> 4;
    hexStringBuffer[bufferIndex] = hexTable[valueMSB];
    hexStringBuffer[bufferIndex + 1] = hexTable[valueLSB];
    bufferIndex += 2;
  }
  return hexStringBuffer;
}
// 48 - 57
// 1023
char* uint16ToString(int number) {
  static char intStringBuffer[6] = "00000";
  char strPosition = 4;
  for(int i = 0; intStringBuffer[i] != '\0'; i += 1) {
    intStringBuffer[i] = '0';
  }
  for (int digit = number; digit != 0; digit = digit / 10) {
    char remainder = digit % 10;
    intStringBuffer[strPosition] = remainder + '0';
    strPosition = strPosition - 1;
  }
  return intStringBuffer;
}
