#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int IRPin = 2;
const int buzzerPin = 8; // Folosim Pin 8 pentru a evita conflictele de Timer

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  
  // Initializam LCD-ul inainte de orice altceva
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Pian Digital");
  lcd.setCursor(0, 1);
  lcd.print("Gata de test!");

  // Pornim IR-ul la final
  IrReceiver.begin(IRPin, ENABLE_LED_FEEDBACK);
  Serial.println("Sistem pornit pe Pin 8");
}

// Functia manuala care nu foloseste Timerele interne
void buzzManual(int frecventa, int durataMs) {
  if (frecventa <= 0) return; 
  long pauza = 1000000L / frecventa / 2;
  unsigned long start = millis();
  
  while (millis() - start < (unsigned long)durataMs) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(pauza);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(pauza);
  }
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned int command = IrReceiver.decodedIRData.command;
    
    if (command != 0) {
      Serial.print("Comanda: "); Serial.println(command, HEX);
      
      lcd.setCursor(0, 1);
      lcd.print("Nota: ");

      if (command == 0x45) { // Tasta 1
        lcd.print("DO ");
        buzzManual(262, 200);
      } 
      else if (command == 0x46) { // Tasta 2
        lcd.print("RE ");
        buzzManual(294, 200);
      }
      else {
        lcd.print(command, HEX);
        lcd.print(" ???   ");
      }
    }
    IrReceiver.resume();
  }
}