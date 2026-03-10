#include <Servo.h>

Servo barrier;
const int redPin = 3;
const int greenPin = 5;
const int buzzerPin = 8;

void setup() {
  Serial.begin(9600);
  barrier.attach(11);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Starea initiala: Inchis
  barrier.write(0);
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  
  Serial.println("Servo + RGB + Buzzer");
  Serial.println();
  Serial.println("O - Deschide, C - Inchide, T - Terminate, B - Block");
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    if (cmd == 'O' || cmd == 'o') {
      Serial.println("Deschide bariera");
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      
      digitalWrite(buzzerPin, HIGH);
      delay(100);
      digitalWrite(buzzerPin, LOW);
      
      barrier.write(90);
    } 
    else if (cmd == 'B' || cmd == 'b') {
      Serial.println("Blocheaza bariera");
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, HIGH);
      
      barrier.write(45);
      
      // Beep de confirmare
      digitalWrite(buzzerPin, HIGH);
      delay(50);
      digitalWrite(buzzerPin, LOW);
    }
    else if (cmd == 'T' || cmd == 't') {
      Serial.println("Terminate bariera");
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      
      barrier.write(0);
      
      // Beep de confirmare
      digitalWrite(buzzerPin, HIGH);
      delay(50);
      digitalWrite(buzzerPin, LOW);
    }
    else if (cmd == 'C' || cmd == 'c') {
      Serial.println("Inchide bariera");
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      
      barrier.write(0);
      
      // Beep de confirmare
      digitalWrite(buzzerPin, HIGH);
      delay(50);
      digitalWrite(buzzerPin, LOW);
    }
  }
}