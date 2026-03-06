const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
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
  }
  else if(distance > 0 && distance < 10){
    digitalWrite(buzzerPin,HIGH);
    setColor(25, 0, 0);
    delay(100);
  }
  else if(distance >= 10 && distance < 25){
    digitalWrite(buzzerPin,HIGH);
    delay(100);
    setColor(0, 0, 25);
    delay(100);
    digitalWrite(buzzerPin,LOW);
    delay(100);
  }
  else if(distance >=25 && distance < 50){
    digitalWrite(buzzerPin,HIGH);
    delay(100);
    setColor(0, 25, 0);
    delay(400);
    digitalWrite(buzzerPin,LOW);
    delay(400);
  }
  else if(distance >=50 && distance < 100){
    digitalWrite(buzzerPin,HIGH);
    delay(100);
    setColor(0, 0, 25);
    delay(400);
    digitalWrite(buzzerPin,LOW);
    delay(400);
  }
  else{
    digitalWrite(buzzerPin,LOW);
    delay(100);
    setColor(0, 0, 0);
  }

  delay(500);
}
