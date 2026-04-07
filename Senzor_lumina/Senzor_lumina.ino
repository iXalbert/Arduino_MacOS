#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinLDR = A2;
const int ledRed = 13;
const int ledGreen = 11;
//const int ledYellow = 12;

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();

  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  //pinMode(ledYellow, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("LIGHT MONITOR");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lumina = analogRead(pinLDR);
  lcd.setCursor(0, 1);
  lcd.print("Nivel : ");
  lcd.print(lumina);
  lcd.print("   ");

  if(lumina > 700){
    
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);

    lcd.setCursor(11, 0);
    lcd.print("SUN");
  }else{

    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);

    lcd.setCursor(11, 0);
    lcd.print("DARK");
  }

  delay(200);
}
/*
void loop() {
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledYellow, HIGH);
  delay(1000);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
  delay(1000);
}*/
