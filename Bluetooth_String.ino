#include <SoftwareSerial.h>
SoftwareSerial bt (7, 8);
char c;
String data;

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  while (bt.available() > 0) {
    c = bt.read();
    delay(2);
    data += c;
    Serial.println(data);
  }
  if (data.length() > 0) {
    if (data == "ledon") {
      digitalWrite (13, HIGH);
    }
    if (data == "ledoff") {
      digitalWrite (13, LOW);
    }
    data = "";
  }
}
