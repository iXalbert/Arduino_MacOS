#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 11;
const int RedPin = 5;
const int GreenPin = 3;

Servo myservo;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  //pinMode(RedPin, OUTPUT);
  //pinMode(GreenPin, OUTPUT);
  myservo.attach(servoPin);
  myservo.write(0);
  Serial.begin(9600);
  Serial.println("Servo + RGB_led");
}

void set_led(int red, int green, int blue){
  analogWrite(RedPin, red);
  analogWrite(GreenPin, green);
  //analogWrite(BluePin, blue);
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
    Serial.println("Bariera se deschide");
    //set_led(0,50,0);
    myservo.write(90);  
    delay(3000);        
  } 
  else {
    Serial.println("Bariera se inchide");
    //set_led(50,0,0);
    myservo.write(0);
    delay(3000);
  }

  delay(100);
}
