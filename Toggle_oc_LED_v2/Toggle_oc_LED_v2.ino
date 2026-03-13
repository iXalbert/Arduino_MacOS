const int ledPin = 3;
const int buttonPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Rezistenta interna ON
  Serial.begin(9600);
}

void loop() {
  int citire = digitalRead(buttonPin);

  if (citire == LOW) { // Buton apasat
    digitalWrite(ledPin, HIGH);
    Serial.println("Apasat - LED ON");
  } else { // Buton eliberat
    digitalWrite(ledPin, LOW);
  }
}