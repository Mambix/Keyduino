// Rows
int ROWS[] = {2, 3, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Columns
int EN = A0;
int CLK = 14;
int DATA = 15;
int LATCH = 16;

int Row = 0;
byte Led = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.print("Keyduino v0.1\r\n");

  for (int i = 0; i<11; i++) {
    pinMode(ROWS[i], OUTPUT);
  }

  pinMode(EN, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DATA, INPUT);

  digitalWrite(EN, HIGH);
  digitalWrite(LATCH, HIGH);
  digitalWrite(CLK, HIGH);
}

byte sendClockPulse() {
  digitalWrite(CLK, LOW);
  delay(1);
  byte ret = digitalRead(DATA);
  digitalWrite(CLK, HIGH);
  delay(1);
  return ret;
}

unsigned int readKeyboard() {
  unsigned int ret = 0;
  byte tmp = 0;

  //Parallel load
  digitalWrite(EN, HIGH);
  delay(1);
  digitalWrite(LATCH, LOW);
  delay(1);
  digitalWrite(LATCH, HIGH);

  //Serial shift
  digitalWrite(EN, LOW);
  delay(1);

  for (byte i=0; i<16; i++) {
    tmp = sendClockPulse();
    if (tmp == 1) {
      ret |= 0x0001;
    }
    if (i < 15) {ret = ret << 1;}
  }
  digitalWrite(EN, HIGH);
  return ret;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ROWS[Row], HIGH);
  delay(25);
  unsigned int key = readKeyboard();
  Serial.print(key, HEX);
  Serial.print("\r\n");
  digitalWrite(ROWS[Row], LOW);
  delay(25);

  if (Row++ >= 11) {
    Serial.print("Row zero...\r\n");
    Row = 0;
  }
//  int LED = Led++ & 0x80;
//  if (LED > 0) {
//    digitalWrite(PD5, HIGH);
//  } else {
//    digitalWrite(PD5, LOW);
//  }
//  delay(25);
}
