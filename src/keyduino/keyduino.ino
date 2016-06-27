#include "MCP23S17.h"

const int chipSelectPin = 10;
MCP23S17 IO(chipSelectPin);

//           76543210765432107654321076543210
unsigned long ROWS = 0x000001FF; //B00000000000000000000000111111111L;
unsigned long COLS = 0x0FFFFE00; //B00000000111111111111111000000000L;

unsigned long pinAddress[] = {
  0x00000001, 0x00000002, 0x00000004, 0x00000008, 0x00000010, 0x00000020, 0x00000040, 0x00000080,
  0x00000100, 0x00000200, 0x00000400, 0x00000800, 0x00001000, 0x00002000, 0x00004000, 0x00008000,
  0x00010000, 0x00020000, 0x00040000, 0x00080000, 0x00100000, 0x00200000, 0x00400000, 0x00800000,
  0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000,
};

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.print("Keyduino v0.1\r\n");

  IO.begin();
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
//  IO.pinMode(0xFF7FFFFF);
//  IO.pinWrite(0x00800000);
  delay(1);
  unsigned long key = IO.pinRead();  
  Serial.print(key, HEX);
  Serial.print("\r\n");
}
