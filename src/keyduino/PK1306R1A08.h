#ifndef keyboard_h
#define keyboard_h

#define KEYBOARD_COLS (0x03FC0000)
#define KEYBOARD_ROWS (0x0003FFFF)

#include <Arduino.h>

class laptopKeyboard {
	public:
    laptopKeyboard();
    void processKey(uint16_t, uint32_t);
//	private:
};

#endif
