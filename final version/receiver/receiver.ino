#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3);

String received;
char sent[20];

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
}

void loop() {
  // Receives string data from another bluetooth module with chars
  while (BT.available()) {
    delay(10);
    if (BT.available() > 0) {
      char c = BT.read();  //gets one byte from serial buffer
      received += c; //makes the string readString
    }
  }

  
  if (received != "" && (received[0] == '1' || received[0] == '0')&& (received[1] == '1' || received[1] == '0')&& (received[2] == '1' || received[2] == '0')&& (received[3] == '1' || received[3] == '0')&& (received[4] == '1' || received[4] == '0')&& (received[5] == '1' || received[5] == '0')&& (received[6] == '1' || received[6] == '0')&& (received[7] == '1' || received[7] == '0')&& (received[8] == '1' || received[8] == '0')) {
    Serial.println(received);
    received = "";
  }
}
