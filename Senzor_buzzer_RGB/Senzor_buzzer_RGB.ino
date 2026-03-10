const int echoPin = 10;
const int trigPin = 9;
const int redPin = 5;
const int bluePin = 11;
const int greenPin = 6;
const int buzzerPin = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  while (!Serial) {
    ; 
  }

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Serial.println("ABCDE");

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  //digitalWrite(redPin, HIGH);

  //Serial.println("ABCDEF3");

  Serial.println(distance);

  if(distance > 1 && distance < 50){

    //Serial.println("ABCDEF2");

    int pitch = map(distance, 5, 50, 200, 1000);//transformamm distanta in Mhz pentru buzzer 

    int brightness = map(distance, 5, 50, 255, 0);//transformam distanta in val pt led

    Serial.print("Brightness_test : ");
    Serial.println(brightness);

    tone(buzzerPin, pitch);

    analogWrite(redPin, brightness);
    //digitalWrite(redPin, HIGH);

    Serial.print("Tone ");
    Serial.print(pitch);
    Serial.println("Mhz");
  }else{

    noTone(buzzerPin);
    analogWrite(redPin, LOW);
  }

  delay(200);

}
