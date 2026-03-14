#include "DHT.h"
#include "dht.h"

#define DHTPIN 2     
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);
const int ledPin = 6;

void setup() {
  Serial.begin(9600);
  Serial.println("Temp + Umiditate");
  dht.begin();
  pinMode(ledPin, OUTPUT);
}

void loop() {

  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Eroare la citirea senzorului!");
    return;
  }

  Serial.print("Umiditate: ");
  Serial.print(h);
  Serial.print("%  |  ");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println("C");

  // Daca temperatura trece de 25 de grade, aprindem LED-ul
  if (t > 25) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}