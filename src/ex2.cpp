#include <Arduino.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  int minVal = 4095;
  int maxVal = 0;
  int sum = 0;

  for (int i = 0; i < 10; i++) {
    int v = analogRead(33);
    if (v < minVal) minVal = v;
    if (v > maxVal) maxVal = v;
    sum += v;
  }

  Serial.println("min=" + String(minVal) + " max=" + String(maxVal) + " avg=" + String(sum / 10));
  delay(1000);
}
