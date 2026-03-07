#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 11;

Servo myservo;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  myservo.attach(servoPin);
  myservo.write(0);
  Serial.begin(9600);
  Serial.println("Reincercam adaugarea senzorului de miscare");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); 
  int distance = duration * 0.034 / 2;

  Serial.print("Distanta detectata: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < 15) {
    Serial.println(">>> ACCES PERMIS: Deschidere...");
    myservo.write(90);  
    delay(3000);        
  } 
  else {
    myservo.write(0);  
  }

  delay(100);
}
