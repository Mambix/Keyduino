#ifndef PK1306R1A08_h
#define PK1306R1A08_h

#ifndef keyboard_h
#define keyboard_h
#else
#error Keyboard already defined! Include only one keyboard file!
#endif

#define KEYBOARD_COLS (0x03FC0000)
#define KEYBOARD_ROWS (0x0003FFFF)

#include <Arduino.h>
#include <Keyboard.h>

class keyboardPK1306R1A08 {
	public:
    keyboardPK1306R1A08();
    void sendKey(char, uint8_t);
    void processKey(uint16_t, uint32_t, uint8_t);
//	private:
};
#else
#error Include only one Keyboard file in the project!!!
#endif
