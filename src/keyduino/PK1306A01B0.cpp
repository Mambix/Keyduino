#include "PK1306A01B0.h"
#include "PK1306A01B0_map.h"

keyboardPK1306A01B0::keyboardPK1306A01B0() {
};

void keyboardPK1306A01B0::sendKey(char key, uint8_t bPress) {
	if (bPress == 1) {
		Keyboard.press(key);
	} else {
		Keyboard.release(key);
	}
};

void keyboardPK1306A01B0::processKey(uint16_t col, uint32_t row, uint8_t bPress) {
	switch (col) {
		case 0x19:
			if (row == 0x00000002) {sendKey(KEY_16, bPress);}
			if (row == 0x00020000) {sendKey(KEY_36, bPress);}
			if (row == 0x00000020) {sendKey(KEY_28, bPress);}
			if (row == 0x00000400) {sendKey(KEY_3F, bPress);}
			if (row == 0x00001000) {sendKey(KEY_31, bPress);}
			if (row == 0x00000800) {sendKey(KEY_0F, bPress);}
			if (row == 0x00000200) {sendKey(KEY_2E, bPress);}
			if (row == 0x00000008) {sendKey(KEY_5F, bPress);}
			if (row == 0x00010000) {sendKey(KEY_47, bPress);}
			if (row == 0x00002000) {sendKey(KEY_20, bPress);}
			if (row == 0x00000080) {sendKey(KEY_18, bPress);}
			if (row == 0x00000100) {sendKey(KEY_2C, bPress);}
			if (row == 0x00008000) {sendKey(KEY_63, bPress);}
			if (row == 0x00004000) {sendKey(KEY_33, bPress);}
			break;
		case 0x18:
			if (row == 0x00020000) {sendKey(KEY_37, bPress);}
			if (row == 0x00000020) {sendKey(KEY_4B, bPress);}
			if (row == 0x00000400) {sendKey(KEY_5C, bPress);}
			if (row == 0x00001000) {sendKey(KEY_43, bPress);}
			if (row == 0x00000800) {sendKey(KEY_5E, bPress);}
			if (row == 0x00000200) {sendKey(KEY_4F, bPress);}
			if (row == 0x00010000) {sendKey(KEY_10, bPress);}
			if (row == 0x00000040) {sendKey(KEY_5D, bPress);}
			if (row == 0x00008000) {sendKey(KEY_62, bPress);}
			if (row == 0x00000100) {sendKey(KEY_4E, bPress);}
			if (row == 0x00004000) {sendKey(KEY_60, bPress);}
			break;
		case 0x17:
			if (row == 0x00000002) {sendKey(KEY_39, bPress);}
			if (row == 0x00020000) {sendKey(KEY_65, bPress);}
			if (row == 0x00000020) {sendKey(KEY_4C, bPress);}
			if (row == 0x00000400) {sendKey(KEY_52, bPress);}
			if (row == 0x00001000) {sendKey(KEY_53, bPress);}
			if (row == 0x00000200) {sendKey(KEY_50, bPress);}
			if (row == 0x00010000) {sendKey(KEY_25, bPress);}
			if (row == 0x00002000) {sendKey(KEY_54, bPress);}
			if (row == 0x00000040) {sendKey(KEY_5B, bPress);}
			if (row == 0x00000080) {sendKey(KEY_4D, bPress);}
			if (row == 0x00000100) {sendKey(KEY_3C, bPress);}
			if (row == 0x00008000) {sendKey(KEY_42, bPress);}
			if (row == 0x00004000) {sendKey(KEY_66, bPress);}
			break;
		case 0x16:
			if (row == 0x00000002) {sendKey(KEY_38, bPress);}
			if (row == 0x00020000) {sendKey(KEY_57, bPress);}
			if (row == 0x00000020) {sendKey(KEY_3A, bPress);}
			if (row == 0x00000004) {sendKey(KEY_55, bPress);}
			if (row == 0x00000400) {sendKey(KEY_51, bPress);}
			if (row == 0x00000200) {sendKey(KEY_3E, bPress);}
			if (row == 0x00010000) {sendKey(KEY_64, bPress);}
			if (row == 0x00000080) {sendKey(KEY_3B, bPress);}
			if (row == 0x00000100) {sendKey(KEY_3D, bPress);}
			if (row == 0x00008000) {sendKey(KEY_44, bPress);}
			if (row == 0x00004000) {sendKey(KEY_61, bPress);}
			break;
		case 0x15:
			if (row == 0x00000002) {sendKey(KEY_27, bPress);}
			if (row == 0x00000010) {sendKey(KEY_5A, bPress);}
			if (row == 0x00000020) {sendKey(KEY_29, bPress);}
			if (row == 0x00000400) {sendKey(KEY_40, bPress);}
			if (row == 0x00001000) {sendKey(KEY_41, bPress);}
			if (row == 0x00000800) {sendKey(KEY_13, bPress);}
			if (row == 0x00000200) {sendKey(KEY_2D, bPress);}
			if (row == 0x00010000) {sendKey(KEY_56, bPress);}
			if (row == 0x00002000) {sendKey(KEY_32, bPress);}
			if (row == 0x00000080) {sendKey(KEY_2A, bPress);}
			if (row == 0x00000100) {sendKey(KEY_2B, bPress);}
			if (row == 0x00008000) {sendKey(KEY_34, bPress);}
			if (row == 0x00004000) {sendKey(KEY_4A, bPress);}
			break;
		case 0x14:
			if (row == 0x00000002) {sendKey(KEY_15, bPress);}
			if (row == 0x00020000) {sendKey(KEY_46, bPress);}
			if (row == 0x00000020) {sendKey(KEY_17, bPress);}
			if (row == 0x00000400) {sendKey(KEY_2F, bPress);}
			if (row == 0x00001000) {sendKey(KEY_30, bPress);}
			if (row == 0x00000800) {sendKey(KEY_23, bPress);}
			if (row == 0x00000200) {sendKey(KEY_1C, bPress);}
			if (row == 0x00000008) {sendKey(KEY_58, bPress);}
			if (row == 0x00010000) {sendKey(KEY_35, bPress);}
			if (row == 0x00002000) {sendKey(KEY_1F, bPress);}
			if (row == 0x00000080) {sendKey(KEY_19, bPress);}
			if (row == 0x00000100) {sendKey(KEY_1A, bPress);}
			if (row == 0x00008000) {sendKey(KEY_22, bPress);}
			if (row == 0x00004000) {sendKey(KEY_21, bPress);}
			break;
		case 0x13:
			if (row == 0x00000002) {sendKey(KEY_01, bPress);}
			if (row == 0x00020000) {sendKey(KEY_45, bPress);}
			if (row == 0x00000020) {sendKey(KEY_02, bPress);}
			if (row == 0x00000004) {sendKey(KEY_49, bPress);}
			if (row == 0x00000400) {sendKey(KEY_08, bPress);}
			if (row == 0x00001000) {sendKey(KEY_1E, bPress);}
			if (row == 0x00000800) {sendKey(KEY_14, bPress);}
			if (row == 0x00000200) {sendKey(KEY_1D, bPress);}
			if (row == 0x00010000) {sendKey(KEY_26, bPress);}
			if (row == 0x00002000) {sendKey(KEY_0C, bPress);}
			if (row == 0x00008000) {sendKey(KEY_0E, bPress);}
			if (row == 0x00000100) {sendKey(KEY_1B, bPress);}
			if (row == 0x00000080) {sendKey(KEY_04, bPress);}
			if (row == 0x00004000) {sendKey(KEY_0D, bPress);}
			break;
		case 0x12:
			if (row == 0x00000002) {sendKey(KEY_00, bPress);}
			if (row == 0x00020000) {sendKey(KEY_48, bPress);}
			if (row == 0x00000001) {sendKey(KEY_59, bPress);}
			if (row == 0x00000020) {sendKey(KEY_03, bPress);}
			if (row == 0x00000400) {sendKey(KEY_09, bPress);}
			if (row == 0x00001000) {sendKey(KEY_0A, bPress);}
			if (row == 0x00000800) {sendKey(KEY_24, bPress);}
			if (row == 0x00000200) {sendKey(KEY_07, bPress);}
			if (row == 0x00010000) {sendKey(KEY_12, bPress);}
			if (row == 0x00002000) {sendKey(KEY_0B, bPress);}
			if (row == 0x00000080) {sendKey(KEY_05, bPress);}
			if (row == 0x00000100) {sendKey(KEY_06, bPress);}
			if (row == 0x00008000) {sendKey(KEY_67, bPress);}
			if (row == 0x00004000) {sendKey(KEY_11, bPress);}
			break;
	}
};
