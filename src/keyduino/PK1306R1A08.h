#ifndef keyboard_h
#define keyboard_h

#define KEYBOARD_COLS (0x03FC0000)
#define KEYBOARD_ROWS (0x0003FFFF)

#include <Arduino.h>
#include <Keyboard.h>

class laptopKeyboard {
	public:
    laptopKeyboard();
    void sendKey(char, uint8_t);
    void processKey(uint16_t, uint32_t, uint8_t);
//	private:
};
#else
#error Include only one Keyboard file in the project!!!
#endif
