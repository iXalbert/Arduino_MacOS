#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;
const int servoPin = 11;

Servo barrier;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  barrier.attach(servoPin);
  barrier.write(0);

  Serial.begin(9600);
}

void setColor(int red, int green, int blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // pulseIn cu timeout de 1 secundă
  long duration = pulseIn(echoPin, HIGH, 30000); 
  int distance = duration * 0.034 / 2;

  Serial.print("Dinstanta curenta: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance == 0){
    Serial.println("Nu merge....");
    setColor(0, 0, 0);
    barrier.write(0);
  }
  else if(distance > 0 && distance < 10){
    setColor(25, 0, 0);
    barrier.write(90);
    digitalWrite(buzzerPin,HIGH);
    delay(200);
    digitalWrite(buzzerPin,HIGH);
    delay(3000);
  }
  else if(distance >= 10 && distance < 25){
    setColor(0, 0, 25);
    barrier.write(90);
    delay(100);
    digitalWrite(buzzerPin,HIGH);
    delay(3000);
    digitalWrite(buzzerPin,LOW);
  }
  else if(distance >=25 && distance < 50){
    setColor(0, 25, 0);
    barrier.write(90);
    delay(100);
    digitalWrite(buzzerPin,HIGH);
    delay(3000);
    digitalWrite(buzzerPin,LOW);
  }
  else if(distance >=50 && distance < 100){
    setColor(0, 0, 25);
    barrier.write(90);
    delay(100);
    digitalWrite(buzzerPin,HIGH);
    delay(3000);
    digitalWrite(buzzerPin,LOW);
  }
  else{
    digitalWrite(buzzerPin,LOW);
    setColor(0, 0, 0);
    barrier.write(0);
    delay(3000);
  }

  delay(500);
}
