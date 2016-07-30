#!/usr/bin/env python
# Filename: countLines.py

'''
Created on 24 Jul 2016

@author: ledi.mambix@gmail.com
'''

import sys
import json

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('Not enough argumets!!!')
        print('python countLines.py name ')
        print('python countLines.py PK1306A01B0')
        quit()
    name = sys.argv[1]

    cnt = {'count': {}, 'wire': {}}
    with open('%s.json' % name, 'r') as f:
        jsonData = json.load(f)

        for key in jsonData:
            line0 = jsonData[key][0]
            line1 = jsonData[key][1]
            row0 = line0.split(':')[0]
            row1 = line1.split(':')[0]

            if row0 not in cnt['wire']:
                cnt['wire'][row0] = [row1]
            else:
                cnt['wire'][row0].append(row1)

            if row1 not in cnt['wire']:
                cnt['wire'][row1] = [row0]
            else:
                cnt['wire'][row1].append(row0)

            if row0 not in cnt['count']:
                cnt['count'][row0] = 1
            else:
                cnt['count'][row0] = cnt['count'][row0] + 1

            if row1 not in cnt['count']:
                cnt['count'][row1] = 1
            else:
                cnt['count'][row1] = cnt['count'][row1] + 1
        with open('%s_count.json' % name, 'w') as f:
            f.write(json.dumps(cnt, indent=2, sort_keys=True))
