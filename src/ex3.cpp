#include <Arduino.h>

bool alertActive = false;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int value = analogRead(33);

  if (value > 3000 && !alertActive) {
    alertActive = true;
    Serial.println("ALERT=1");
  }
  if (value < 2500 && alertActive) {
    alertActive = false;
    Serial.println("ALERT=0");
  }

  delay(300);
}