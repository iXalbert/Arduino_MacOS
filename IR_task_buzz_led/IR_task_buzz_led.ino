#include <IRremote.h>
//#include <IRremote.hpp>
#include <Servo.h>
#define IR_USE_AVR_TIMER2

const int IRPin = 2;
const int ledPin = 3;
const int buzzerPin = 9;

bool ledStatus = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  delay(1000);

  IrReceiver.begin(IRPin, ENABLE_LED_FEEDBACK);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  //myServo.attach(servoPin);

  //myServo.write(0);
  //Serial.println("1 - deschide , 2 - inchide, 3 - blocheaza ");
  Serial.println("1 - buzz , 2 - led on/off, 3 - both, 4 - turn off all");
}

void beepManual(int durataMs) { //fct pentru buzzer pentru ca nu merge cu tone
  unsigned long start = millis();
  while (millis() - start < durataMs) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(500); // Frecventa sunetului
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(500);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(IrReceiver.decode()){
    unsigned int command = IrReceiver.decodedIRData.command;
    Serial.print("Comanda este: ");
    Serial.println(command, HEX);

    if(command == 0){
      IrReceiver.resume();
      return;
    }

    if(command == 0x45){
      //digitalWrite(ledPin, HIGH);
      //tone(buzzerPin, 100, 100);
      //delay(200);       
      //noTone(buzzerPin);              
      beepManual(100);
    }

    if(command == 0x46){
      ledStatus = !ledStatus;
      digitalWrite(ledPin, ledStatus);
      //delay(200);
    }

    if(command == 0x47){
      //tone(buzzerPin, 100, 100);
      //delay(200);
      beepManual(100);
      for(int i = 0 ; i < 3 ; i++){
        digitalWrite(ledPin, HIGH);
        delay(500); 
        digitalWrite(ledPin, LOW);
        delay(500); 
      }
    }

    if(command == 0x44){
        digitalWrite(ledPin, LOW);
    }


    delay(200);
    IrReceiver.resume(); 
  }
}


/*
Motivul pentru care avem beepManual si nu tone e pentru ca
bibloteca IR foloseste unul din Timere (1 sau 2)
iar tone foloseste unul dintre ele si el 
astfel Timerul de la tone fura si schimba setarile
si folosind o functie fiecare e cu "Timerul" lui
*/