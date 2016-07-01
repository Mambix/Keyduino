#ifndef keyboard_h
#define keyboard_h

#define KEYBOARD_ROWS (0x000001FF)
#define KEYBOARD_COLS (0x0FFFFE00)

#include <Arduino.h>

class laptopKeyboard {
	public:
    laptopKeyboard();
    void processKey(uint16_t, uint32_t);
//	private:
};

#endif
