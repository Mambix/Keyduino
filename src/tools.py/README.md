# How to decode new keyboard?

## 1. Keyboard
Attach your keyboard to Keyduino board. This can be done via onboard 26 pin connector. 
Or with the use of adapter board if the new keyboard uses different connector.

## 2. Arduino
Next we need to set up code in arduino so we can use python tools.
This can be easily done by just commenting out all the keyboard header files in main ino project file.

Next step is to enable all columns for outputs with `#define KEYBOARD_COLS (0xFFFFFFFF)`

Now compile the code and load it into Arduino

## 3. Python scripts
### mapKeyboard.py
First thing we're going to record is what signals are activated for each key pressed.
This is going to help us figure out which signals are columns and which are rows.
I'm going to give you an example for keyboard PK1306A01B0. On my system arduino is printing data out on COM13.
And I'm doing this on windows so I will run this command:  
  
`python mapKeyboard.py PK1306A01B0 COM13 104`  

First parameter is the name of the file that will be saved. Second is COM port.
And third is the number of keys on the keyboard, so 104 in the case of PK1306A01B0.
After you're done you will have a new file called `PK1306A01B0.json` in your folder.

### countLines.py
Now we are going to run the script that will count how many times each line is used.
Simply type `python countLines.py PK1306A01B0` into the console and execute.

This will give us a new json file `PK1306A01B0_count.json`.
We're interested in first part of json file:  
```json
{
  "count": {
    "8000": 1, 
    "8001": 7, 
    "8002": 2, 
    "8003": 2, 
    "8004": 1, 
    "8005": 8, 
    "8006": 2, 
    "8007": 7, 
    "8008": 8, 
    "8009": 8, 
    "800A": 8, 
    "800B": 6, 
    "800C": 7, 
    "800D": 6, 
    "800E": 8, 
    "800F": 8, 
    "8010": 8, 
    "8011": 7, 
    "8012": 14, 
    "8013": 14, 
    "8014": 14, 
    "8015": 13, 
    "8016": 11, 
    "8017": 13, 
    "8018": 11, 
    "8019": 14
  }
}
```

It's not hard to see that lines from 0x12 to 0x19 are colums we're are looking for. Ignore the fact that numbers are larger than 8000.
This is just something I added in arduino so I could read the lines in COM terminal better.

Now we can write our `KEYBOARD_COLS` constant. 
If we write binary number from left to right starting with 0x19 down to 0x00 we get `11 1111 1100 0000 0000 0000 0000`.
If we convert our blocks of four bits to hexadecimal we get this:  

0011 > 3  
1111 > F  
1100 > C  
0000 > 0  

So our constant is `0x03FC0000` because we have 32 inputs/outputs.

** Now we change the value of the constant in arduino project and push it into arduino again**
`#define KEYBOARD_COLS (0x03FC0000)`

### mapKeyboard.py
We are going to run this script again but were going to add another paramater at the end.  

`python mapKeyboard.py PK1306A01B0 COM13 104 2`  

Two at the end indicates that arduino now only returns 2 lines instead of four for each key pressed.
Running the srcipt gives us another json file `PK1306A01B0_decoded.json` after we go through all 104 keys.
It is important you press keys in the same pattern you did it first time we ran this script!

### generateLibrary.py
Final script we need to run is to generate arduino librares.  

`generateLibrary.py PK1306A01B0`  

This will give us two new files: `PK1306A01B0.cpp` and `PK1306A01B0_map.h`. Copy this two files into arduino project directory.
Create subfolder named `PK1306A01B0` and copy generated json files inside. Also add `README.md` file to the folder and add some information about the keyboard ;)

Copy one of the header files of the existing keyboard like

`copy PK1306R1A08.h PK1306A01B0.h`

Modify these lines, so that the name of the variable is correct:  
```
#ifndef PK1306A01B0_h
#define PK1306A01B0_h
#endif
```

Modify `KEYBOARD_COLS` constant so that it has the value we decoded earlier (0x03FC0000 in case of PK1306A01B0 keyboard used for this sample).
```
#define KEYBOARD_COLS (0x03FC0000)
#define KEYBOARD_ROWS (0x0003FFFF)
```

## 4. Arduino
Open arduino project again and add this line to ino file:  
`#include "PK1306A01B0.h"`  
Make sure the project compiles.

Last thing we need to modify before we can use our keyboard is the `PK1306A01B0_map.h` file.
This file contains the mappings between function calls of arduino to the acctual keyboard characters we send to host operating sytem.
I started at top left corner when pressing keys. That's why KEY_00 needs to be mapped to ESC key. KEY_01 to F1 and so on. Until we get to key #104 or KEY_67.
You guessed it 0x67 in hex is 104 in decimal ;)

Once you map the keys you can push the code to arduino and test the keyboard out.
