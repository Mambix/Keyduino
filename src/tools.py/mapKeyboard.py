#!/usr/bin/env python
# Filename: mapKeyboard.py

'''
Created on 23 Jul 2016

@author: ledi.mambix@gmail.com
'''

import serial
import json

keys = {}

if __name__ == '__main__':
	ser = serial.Serial('COM9', 115200)
	cnt = 0
	
	try:
		if ser.is_open == False:
			ser.open()
		while cnt<100:
			ln1 = ser.readline()
			ln2 = ser.readline()
			# ln3 = ser.readline()
			# ln4 = ser.readline()
			
			keys['KEY_%s' % cnt] = [ln1, ln2] # , ln3, ln4]
			
			cnt = cnt + 1
	except Exception as msg:
		print(msg)

	if ser.is_open == True:
		ser.close()
	print(json.dumps(keys, indent=2))
	