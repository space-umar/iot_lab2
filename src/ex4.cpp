
#include <Arduino.h>

int leds[] = {26, 27, 12, 14};
int count = 0;
bool lastButton = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(25, INPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  bool button = digitalRead(25);

  if (button == HIGH && lastButton == LOW) {
    count++;
    if (count > 4) count = 0;

    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], i < count);
    }

    Serial.println("count=" + String(count));
  }

  lastButton = button;
  delay(20);
}