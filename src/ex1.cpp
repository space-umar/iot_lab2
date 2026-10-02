#include <Arduino.h>

int leds[] = {26, 27, 12, 14, 12, 27};
String names[] = {"RED", "GREEN", "YELLOW", "BLUE", "YELLOW", "GREEN"};
int step = 0;

void setup() {
  Serial.begin(115200);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
}

void loop() {
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
  digitalWrite(12, LOW);
  digitalWrite(14, LOW);

  digitalWrite(leds[step], HIGH);
  Serial.println("chase=" + names[step]);

  step++;
  if (step >= 6) step = 0;

  delay(150);
}