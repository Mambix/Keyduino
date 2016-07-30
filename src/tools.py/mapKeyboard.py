#!/usr/bin/env python
# Filename: mapKeyboard.py

'''
Created on 24 Jul 2016

@author: ledi.mambix@gmail.com
'''

import sys
import serial
import json

keys = {}

if __name__ == '__main__':
	linesPerKey = 4
	if len(sys.argv) < 4:
		print('Not enough argumets!!!')
		print('python mapKeyboard.py name comPort numberOfKeys <linesPerKey>')
		print('python mapKeyboard.py PK1306A01B0 COM13 104 2')
		quit()

	name = sys.argv[1]
	comPort = sys.argv[2]

	# name = ''
	# comPort = 'COM13'
	# numKeys = 104

	ser = serial.Serial(comPort, 115200)
	cnt = 0
	
	try:
		numKeys = int(sys.argv[3])
		if len(sys.argv) == 5:
			linesPerKey = int(sys.argv[4])
		if ser.is_open == False:
			ser.open()
		print('Press all %s keys one by one...' % numKeys)
		while cnt<numKeys:
			ln1 = ser.readline()
			ln2 = ser.readline()
			connection = [ln1, ln2]
			if linesPerKey == 4:
				ln3 = ser.readline()
				connection.append(ln3)
				ln4 = ser.readline()
				connection.append(ln4)
			
			keys['KEY_%0.2X' % cnt] = connection
			
			cnt = cnt + 1
			print('Recorded key: %s\r\n' % cnt)
	except Exception as msg:
		print(msg)

	if ser.is_open == True:
		ser.close()
	
	suffix = ''
	if linesPerKey != 4:
		suffix = '_decoded'
	with open('%s%s.json' % (name, suffix), 'w') as f:
		f.write(json.dumps(keys, indent=2, sort_keys=True))
