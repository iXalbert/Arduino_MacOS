const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // pulseIn cu timeout de 1 secundă
  long duration = pulseIn(echoPin, HIGH, 1000000); 
  int distance = duration * 0.034 / 2;

  Serial.print("Dinstanta curenta: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance == 0){
    Serial.println("Nu merge....");
  }
  else if(distance > 0 && distance < 10){
    digitalWrite(buzzerPin,HIGH);
  }
  else if(distance >= 10 && distance < 25){
    digitalWrite(buzzerPin,HIGH);
    delay(100);
    digitalWrite(buzzerPin,LOW);
    delay(100);
  }
  else if(distance >=25 && distance < 50){
    digitalWrite(buzzerPin,HIGH);
    delay(400);
    digitalWrite(buzzerPin,LOW);
    delay(400);
  }
  else{
    digitalWrite(buzzerPin,LOW);
  }

  delay(500);
}