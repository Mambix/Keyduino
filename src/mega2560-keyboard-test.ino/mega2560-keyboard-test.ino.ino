//https://www.raspberrypi.org/forums/viewtopic.php?f=40&t=97080
//pins 1 to 26 ( pin 7 is blank and not connected ) 
//pins 5,7,9,12,18,22,23,24 are the rows ( as i call them )
byte ROWS[] = {00, 00, 00, 00, 00, 01, 00, 01, 00, 01, 00, 00, 01, 00, 00, 00, 00, 00, 01, 00, 00, 00, 01, 01, 01, 00, 00};
//              0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26
//byte ROWS[] = {00, 00, 01, 01, 01, 00, 01, 00, 00, 00, 00, 01, 01, 01, 01, 01, 01, 01, 01, 00, 00, 00, 00, 00, 00, 00, 01};
int PINS[] =  {22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 53, 51, 49, 47, 45, 43, 41, 39, 37, 35, 33};
unsigned long OLD[] = {00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00};

unsigned long vals = 0;
byte tmp = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.print("Keyboard tester v0.1\r\n");
  
  // put your setup code here, to run once:
  for (int i = 0; i<27; i++) {
    pinMode(PINS[i], INPUT);
    digitalWrite(PINS[i], HIGH);
  }

  pinMode(A0, INPUT);
  digitalWrite(A0, HIGH);
}

void loop() {
  for (int j=0; j<27; j++) {
    if ((ROWS[j] == 0) && (digitalRead(A0)==0)) {
      continue;
    }
    pinMode(PINS[j], OUTPUT);
    digitalWrite(PINS[j], LOW);
    delay(1);
    
    vals = 0;
    for (int i = 0; i<27; i++) {
      tmp = digitalRead(PINS[i]);
      if ((tmp == 1) || (j==i)) {
        vals |= 0x0001;
      }
      if (i < 26) {vals = vals << 1;}
    }

    vals = vals xor 0x7FFFFFF;

    if (OLD[j]!=vals) {
      OLD[j]=vals;
      Serial.print("J: ");
      //unsigned long tmp2 = 0x00000001 << j;
//      print_hex(tmp2, 32);
      Serial.print(j);
      Serial.print("  Val: ");
      Serial.print(vals, HEX);
//      print_hex(vals, 32);
      Serial.print("\r\n");
    }

    pinMode(PINS[j], INPUT);
    digitalWrite(PINS[j], HIGH);
    delay(1);
  }
}
