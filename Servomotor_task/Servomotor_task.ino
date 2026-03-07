#include <Servo.h>
Servo test;

void setup() {
  test.attach(11);
}

void loop() {
  test.write(10);  // Aproape de un capăt
  delay(1000);
  test.write(170); // Aproape de celălalt capăt
  delay(1000);
}