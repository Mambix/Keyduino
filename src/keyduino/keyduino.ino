// Hardware v0.2

#include "MCP23S17.h"
//#include "PK1306R1A08.h"
#include "PK1306A01B0.h"

const int chipSelectPin1 = 2;
const int chipSelectPin2 = 3;
const int chipReset = 10;
MCP23S17 IO(chipSelectPin1, chipSelectPin2);
#ifdef keyboard_h
  #ifdef PK1306R1A08_h 
    keyboardPK1306R1A08 KEY; 
  #endif
  #ifdef PK1306A01B0_h
    keyboardPK1306A01B0 KEY;
  #endif
#else
  #define KEYBOARD_COLS (0x03FC0000)
  #define KEYBOARD_ROWS (0xFFFFFFFF)
#endif

byte pinPOS = 0;
unsigned long key=0;

unsigned long oldKey[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned long pinAddress[] = {
  0x00000001, 0x00000002, 0x00000004, 0x00000008, 0x00000010, 0x00000020, 0x00000040, 0x00000080,
  0x00000100, 0x00000200, 0x00000400, 0x00000800, 0x00001000, 0x00002000, 0x00004000, 0x00008000,
  0x00010000, 0x00020000, 0x00040000, 0x00080000, 0x00100000, 0x00200000, 0x00400000, 0x00800000,
  0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000
};

void setup() {
#ifdef keyboard_h
  Keyboard.begin();
#else
  Serial.begin(115200);
  delay(1000);
  Serial.print("Keyduino v0.1\r\n");
#endif

  ::pinMode(chipReset, OUTPUT);
  ::digitalWrite(chipReset, HIGH);

  ::pinMode(4, INPUT); ::digitalWrite(4, HIGH);
  ::pinMode(5, INPUT); ::digitalWrite(5, HIGH);
  ::pinMode(6, INPUT); ::digitalWrite(6, HIGH);
  ::pinMode(7, INPUT); ::digitalWrite(7, HIGH);

  IO.begin();
  IO.speedSPI(10000000);
  delay(100);
}

#ifdef keyboard_h
/* EMULATE KEYBOARD */
void loop() {
  unsigned int pos = pinPOS & 0x1F;
  if ((pinAddress[pos] & KEYBOARD_COLS) > 0) {
    unsigned long key = 0xFFFFFFFF ^ pinAddress[pos];
    IO.pinMode(key);
    IO.pinWrite(key);
    delay(1);
    key ^= IO.pinRead();
    if (key!=oldKey[pos]) {
      unsigned long diff = key ^ oldKey[pos];
      for (int i = 0; i<32; i++) {
        if (pinAddress[i] & diff) {
          uint8_t bPress = 0;
          if (key & pinAddress[i]) {bPress = 1;}
          KEY.processKey(pos, pinAddress[i], bPress);
        }
      }
      oldKey[pos]=key;
    }
  }
  pinPOS++;
}
#else
/* MAP KEYBOARD */
void loop() {
  unsigned int pos = pinPOS & 0x1F;
  if ((pinAddress[pos] & KEYBOARD_COLS) > 0) {
    unsigned long key = 0xFFFFFFFF ^ pinAddress[pos];
    IO.pinMode(key);
    IO.pinWrite(key);
    delay(1);
    key ^= IO.pinRead();
    if (key!=oldKey[pos]) {
      Serial.print(pos | 0x8000, HEX);
      Serial.print(": ");
      Serial.print(key | 0x80000000, HEX);
      Serial.print("\r\n");
      oldKey[pos]=key;
    }
  }
  pinPOS++;
}
#endif
