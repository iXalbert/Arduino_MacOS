#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int IRPin = 2;
const int ledPin = 3;
const int buzzerPin = 9;

LiquidCrystal_I2C lcd (0x27, 16, 2);

bool ledStatus = false;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  Wire.begin();
  Wire.setClock(100000);

  lcd.init();
  lcd.backlight(); //power on
  lcd.setCursor(0, 0); 
  lcd.print("POWERN ON");
  lcd.setCursor(0, 1);
  lcd.print("WAITING....");

  IrReceiver.begin(IRPin, ENABLE_LED_FEEDBACK);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

}

void beepManual(int durataMs){

  unsigned long start = millis();
  while(millis() - start < durataMs){
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(500);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(IrReceiver.decode()){
    unsigned int command = IrReceiver.decodedIRData.command;
    if(command == 0 ){
      IrReceiver.resume();
      return;
    }

    Serial.print("Comanda : ");
    Serial.println(command, HEX);

    lcd.setCursor(0, 1);
    lcd.print("               ");
    lcd.setCursor(0, 1);

    if(command == 0x45){
       beepManual(150);
       delay(200);
      lcd.print("Beep Beep ;)");
    }

    if(command == 0x46){
      ledStatus = !ledStatus;
      digitalWrite(ledPin, ledStatus);
      lcd.print(ledStatus ? "Blink Blink ;)" : "Not blink :(");
    }

    if(command == 0x47){
      beepManual(100);
      delay(200);
      lcd.print("Buzz Blink");
      for(int i = 0; i < 3; i++){
        digitalWrite(ledPin, HIGH);
        delay(200);
        digitalWrite(ledPin, LOW);
        delay(200);
      }

      digitalWrite(ledPin, ledStatus);
    }

    if(command == 0x44){
      lcd.print("OFF");
      digitalWrite(ledPin, LOW);
      ledStatus = false;
    }

    IrReceiver.resume();
  }
}
