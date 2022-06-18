#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3);

// joystick direction regulator
//  ----------------
//  |0000|0001|0010|
//  |--------------|
//  |0011|0100|0101|
//  |--------------|
//  |0110|0111|1000|
//  ----------------

#define but1 8
#define but2 9
#define but3 10
#define but4 11

#define joy_but 7
#define joy_x A0
#define joy_y A1

int val_joyx;
int val_joyy;

String received;
char sent[10];
char old_sent[10];

void setup() {
  sent[9] = '\0';

  Serial.begin(9600);
  BT.begin(9600);

  pinMode(but1, INPUT_PULLUP);
  pinMode(but2, INPUT_PULLUP);
  pinMode(but3, INPUT_PULLUP);
  pinMode(but4, INPUT_PULLUP);
  pinMode(joy_but, INPUT_PULLUP);
}

void loop() {
  sent[0] = digitalRead(but1) + 48;
  sent[1] = digitalRead(but2) + 48;
  sent[2] = digitalRead(but3) + 48;
  sent[3] = digitalRead(but4) + 48;
  sent[4] = digitalRead(joy_but) + 48;

  val_joyx = analogRead(joy_x);
  val_joyy = analogRead(joy_y);

  if (val_joyy <= 750 && val_joyy > 250) {
    if (val_joyx <= 600 && val_joyx > 400) {
      sent[5] = '0';
      sent[6] = '1';
      sent[7] = '0';
      sent[8] = '0';
    } else if (val_joyx <= 400) {
      sent[5] = '0';
      sent[6] = '0';
      sent[7] = '0';
      sent[8] = '1';
    } else {
      sent[5] = '0';
      sent[6] = '1';
      sent[7] = '1';
      sent[8] = '1';
    }
  } else if (val_joyy > 750) {
    if (val_joyx <= 900 && val_joyx > 350) {
      sent[5] = '0';
      sent[6] = '0';
      sent[7] = '1';
      sent[8] = '1';
    } else if (val_joyx <= 350) {
      sent[5] = '0';
      sent[6] = '0';
      sent[7] = '0';
      sent[8] = '0';
    } else {
      sent[5] = '0';
      sent[6] = '1';
      sent[7] = '1';
      sent[8] = '0';
    }
  } else {
    if (val_joyx <= 650 && val_joyx > 100) {
      sent[5] = '0';
      sent[6] = '1';
      sent[7] = '0';
      sent[8] = '1';
    } else if (val_joyx <= 100) {
      sent[5] = '0';
      sent[6] = '0';
      sent[7] = '1';
      sent[8] = '0';
    } else {
      sent[5] = '1';
      sent[6] = '0';
      sent[7] = '0';
      sent[8] = '0';
    }
  }




  for (int i = 0;  i < 9; i++){
    if ( old_sent[i] != sent[i] )
    {
      Serial.println(sent);
      BT.write(sent);
      break;
    }
  }




  for (int i = 0; i < 9; i++) {
    old_sent[i] = sent[i];
  }
  delay(50);
}
