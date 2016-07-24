#include "PK1306R1A08.h"
#include "PK1306R1A08_map.h"

laptopKeyboard::laptopKeyboard() {
};

laptopKeyboard::sendKey(char key, uint8_t press) {
	if (press == 1) {
		Keyboard.press(key);
	} else {
		Keyboard.release(key);
	}
};

void laptopKeyboard::processKey(uint16_t col, uint32_t row, uint8_t press) {
	switch (col) {
		case 0x19:
			if (row == 0x00000002) {sendKey(KEY_15, press);}
			if (row == 0x00020000) {sendKey(KEY_44, press);}
			if (row == 0x00000020) {sendKey(KEY_26, press);}
			if (row == 0x00000400) {sendKey(KEY_3D, press);}
			if (row == 0x00001000) {sendKey(KEY_2F, press);}
			if (row == 0x00000800) {sendKey(KEY_0F, press);}
			if (row == 0x00000200) {sendKey(KEY_2C, press);}
			if (row == 0x00000008) {sendKey(KEY_5D, press);}
			if (row == 0x00010000) {sendKey(KEY_55, press);}
			if (row == 0x00002000) {sendKey(KEY_1F, press);}
			if (row == 0x00000080) {sendKey(KEY_17, press);}
			if (row == 0x00000100) {sendKey(KEY_2A, press);}
			if (row == 0x00008000) {sendKey(KEY_61, press);}
			if (row == 0x00004000) {sendKey(KEY_31, press);}
			break;
		case 0x18:
			if (row == 0x00020000) {sendKey(KEY_45, press);}
			if (row == 0x00000020) {sendKey(KEY_48, press);}
			if (row == 0x00000400) {sendKey(KEY_5A, press);}
			if (row == 0x00001000) {sendKey(KEY_41, press);}
			if (row == 0x00000800) {sendKey(KEY_5C, press);}
			if (row == 0x00000200) {sendKey(KEY_4C, press);}
			if (row == 0x00010000) {sendKey(KEY_10, press);}
			if (row == 0x00004000) {sendKey(KEY_5E, press);}
			if (row == 0x00008000) {sendKey(KEY_60, press);}
			if (row == 0x00000100) {sendKey(KEY_4B, press);}
			if (row == 0x00000040) {sendKey(KEY_5B, press);}
			break;
		case 0x17:
			if (row == 0x00000002) {sendKey(KEY_37, press);}
			if (row == 0x00000020) {sendKey(KEY_49, press);}
			if (row == 0x00000400) {sendKey(KEY_4F, press);}
			if (row == 0x00001000) {sendKey(KEY_50, press);}
			if (row == 0x00000200) {sendKey(KEY_4D, press);}
			if (row == 0x00010000) {sendKey(KEY_35, press);}
			if (row == 0x00002000) {sendKey(KEY_51, press);}
			if (row == 0x00000080) {sendKey(KEY_4A, press);}
			if (row == 0x00000100) {sendKey(KEY_3A, press);}
			if (row == 0x00008000) {sendKey(KEY_40, press);}
			if (row == 0x00000040) {sendKey(KEY_59, press);}
			break;
		case 0x16:
			if (row == 0x00020000) {sendKey(KEY_22, press);}
			if (row == 0x00000002) {sendKey(KEY_36, press);}
			if (row == 0x00000020) {sendKey(KEY_38, press);}
			if (row == 0x00000004) {sendKey(KEY_52, press);}
			if (row == 0x00000400) {sendKey(KEY_4E, press);}
			if (row == 0x00000200) {sendKey(KEY_3C, press);}
			if (row == 0x00000080) {sendKey(KEY_39, press);}
			if (row == 0x00000100) {sendKey(KEY_3B, press);}
			if (row == 0x00008000) {sendKey(KEY_42, press);}
			if (row == 0x00004000) {sendKey(KEY_5F, press);}
			break;
		case 0x15:
			if (row == 0x00000002) {sendKey(KEY_25, press);}
			if (row == 0x00000010) {sendKey(KEY_58, press);}
			if (row == 0x00000020) {sendKey(KEY_27, press);}
			if (row == 0x00000400) {sendKey(KEY_3E, press);}
			if (row == 0x00001000) {sendKey(KEY_3F, press);}
			if (row == 0x00000800) {sendKey(KEY_13, press);}
			if (row == 0x00000200) {sendKey(KEY_2B, press);}
			if (row == 0x00010000) {sendKey(KEY_62, press);}
			if (row == 0x00002000) {sendKey(KEY_30, press);}
			if (row == 0x00000080) {sendKey(KEY_28, press);}
			if (row == 0x00000100) {sendKey(KEY_29, press);}
			if (row == 0x00008000) {sendKey(KEY_32, press);}
			if (row == 0x00004000) {sendKey(KEY_47, press);}
			break;
		case 0x14:
			if (row == 0x00000002) {sendKey(KEY_14, press);}
			if (row == 0x00020000) {sendKey(KEY_54, press);}
			if (row == 0x00000020) {sendKey(KEY_16, press);}
			if (row == 0x00000400) {sendKey(KEY_2D, press);}
			if (row == 0x00001000) {sendKey(KEY_2E, press);}
			if (row == 0x00000800) {sendKey(KEY_33, press);}
			if (row == 0x00000200) {sendKey(KEY_1B, press);}
			if (row == 0x00000008) {sendKey(KEY_56, press);}
			if (row == 0x00010000) {sendKey(KEY_43, press);}
			if (row == 0x00002000) {sendKey(KEY_1E, press);}
			if (row == 0x00000080) {sendKey(KEY_18, press);}
			if (row == 0x00000100) {sendKey(KEY_19, press);}
			if (row == 0x00008000) {sendKey(KEY_21, press);}
			if (row == 0x00004000) {sendKey(KEY_20, press);}
			break;
		case 0x13:
			if (row == 0x00000002) {sendKey(KEY_01, press);}
			if (row == 0x00020000) {sendKey(KEY_53, press);}
			if (row == 0x00000020) {sendKey(KEY_02, press);}
			if (row == 0x00000004) {sendKey(KEY_46, press);}
			if (row == 0x00000400) {sendKey(KEY_08, press);}
			if (row == 0x00001000) {sendKey(KEY_1D, press);}
			if (row == 0x00000800) {sendKey(KEY_24, press);}
			if (row == 0x00000200) {sendKey(KEY_1C, press);}
			if (row == 0x00010000) {sendKey(KEY_23, press);}
			if (row == 0x00002000) {sendKey(KEY_0C, press);}
			if (row == 0x00008000) {sendKey(KEY_0E, press);}
			if (row == 0x00000100) {sendKey(KEY_1A, press);}
			if (row == 0x00000080) {sendKey(KEY_04, press);}
			if (row == 0x00004000) {sendKey(KEY_0D, press);}
			break;
		case 0x12:
			if (row == 0x00000002) {sendKey(KEY_00, press);}
			if (row == 0x00020000) {sendKey(KEY_63, press);}
			if (row == 0x00000001) {sendKey(KEY_57, press);}
			if (row == 0x00000020) {sendKey(KEY_03, press);}
			if (row == 0x00000400) {sendKey(KEY_09, press);}
			if (row == 0x00001000) {sendKey(KEY_0A, press);}
			if (row == 0x00000800) {sendKey(KEY_34, press);}
			if (row == 0x00000200) {sendKey(KEY_07, press);}
			if (row == 0x00010000) {sendKey(KEY_12, press);}
			if (row == 0x00002000) {sendKey(KEY_0B, press);}
			if (row == 0x00000080) {sendKey(KEY_05, press);}
			if (row == 0x00000100) {sendKey(KEY_06, press);}
			if (row == 0x00004000) {sendKey(KEY_11, press);}
			break;
	}
};
