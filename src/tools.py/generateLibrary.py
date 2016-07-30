#!/usr/bin/env python
# Filename: generateLibrary.py

'''
Created on 24 Jul 2016

@author: ledi.mambix@gmail.com
'''

import sys
import json
import collections

if __name__ == '__main__':
    keyboardMatrix = {}

    if len(sys.argv) < 2:
        print('Not enough argumets!!!')
        print('python countLines.py name ')
        print('python countLines.py PK1306A01B0')
        quit()
    name = sys.argv[1]

    with open('%s_decoded.json' % name, 'r') as f:
        jsonData = json.load(f)
        orderedData = collections.OrderedDict(sorted(jsonData.items()))

        with open('%s_map.h' % name, 'w') as f:
            f.write('// Map keyboard keys into arduino characters\n// https://www.arduino.cc/en/Reference/KeyboardModifiers\n\n#include <Keyboard.h>\n\n')
            for key in orderedData:
                f.write('#define %s (\'?\')\n' % key)

        for key in jsonData:
            values = jsonData[key][0].split(':')
            column = '0x%s' % values[0][2:]
            if column not in keyboardMatrix:
                keyboardMatrix[column] = {}
            row = '0x0%s' % values[1][2:-2]
            keyboardMatrix[column][row] = key

        with open('%s_matrix.json' % name, 'w') as f:
            f.write(json.dumps(keyboardMatrix, indent=2, sort_keys=True))

        with open('%s.cpp' % name, 'w') as f:
            f.write('#include "%s.h"\n' % name)
            f.write('#include "%s_map.h"\n' % name)
            f.write('\n')
            f.write('laptopKeyboard::laptopKeyboard() {\n')
            f.write('};\n')
            f.write('\n')
            f.write('void laptopKeyboard::sendKey(char key, uint8_t bPress) {\n')
            f.write('\tif (bPress == 1) {\n')
            f.write('\t\tKeyboard.press(key);\n')
            f.write('\t} else {\n')
            f.write('\t\tKeyboard.release(key);\n')
            f.write('\t}\n')
            f.write('};\n')
            f.write('\n')
            f.write('void laptopKeyboard::processKey(uint16_t col, uint32_t row, uint8_t bPress) {\n')
            f.write('\tswitch (col) {\n')
            for col in keyboardMatrix:
                f.write('\t\tcase %s:\n' % col)
                for row in keyboardMatrix[col]:
                    f.write('\t\t\tif (row == %s) {sendKey(%s, bPress);}\n' % (row, keyboardMatrix[col][row]))
                f.write('\t\t\tbreak;\n')
            f.write('\t}\n')
            f.write('};')
            f.write('\n')