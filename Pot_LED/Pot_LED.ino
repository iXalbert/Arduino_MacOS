const int potPin = A0;
const int ledPin = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Potentiometru + LED");
}

void loop() {
  // put your main code here, to run repeatedly:
  int pot_val = analogRead(potPin);

  int intensitate = map(pot_val, 0, 1023, 0, 255);

  analogWrite(ledPin, intensitate);

  Serial.print("pot_val"); Serial.println(pot_val);
  Serial.print("intensitate"); Serial.println(intensitate); 

  delay(100);
}
