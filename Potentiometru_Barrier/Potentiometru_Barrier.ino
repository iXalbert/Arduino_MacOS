#include <Servo.h>

Servo myServo;

const int ServoPin = 9;
const int potPin = A0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(ServoPin);

  Serial.begin(9600);
  myServo.write(0);
  Serial.println("barrier + potentiometru");
}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal = analogRead(potPin);

  int angle = map(potVal, 0, 1023, 0 ,180);
  myServo.write(angle);

  Serial.print("Pot : ");
  Serial.println(potVal);

  Serial.print("Angle : ");
  Serial.println(angle);

  delay(1000);
}
