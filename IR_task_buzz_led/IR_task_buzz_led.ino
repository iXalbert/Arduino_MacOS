#include <IRremote.h>
//#include <IRremote.hpp>
#include <Servo.h>
#define IR_USE_AVR_TIMER2

const int IRPin = 2;
const int ledPin = 3;
const int buzzerPin = 9;
//const int servoPin = 8;

//Servo myServo;
bool ledStatus = false;
//bool barieraStatus = false;

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

void loop() {
  // put your main code here, to run repeatedly:
  if(IrReceiver.decode()){
    unsigned int command = IrReceiver.decodedIRData.command;
    Serial.print("Comanda este: ");
    Serial.println(command, HEX);

    if(command == 0x45){
      //myServo.attach(servoPin); 
      //myServo.write(90);
      //digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 100, 100);
      delay(200);       
      noTone(buzzerPin);       
      //myServo.detach();        
    }

    if(command == 0x46){
      //myServo.attach(servoPin);
      //myServo.write(0);
      ledStatus = !ledStatus;
      digitalWrite(ledPin, ledStatus);
      //tone(buzzerPin, 100, 500);
      //delay(200);
      //myServo.detach();
    }

    if(command == 0x47){
      //myServo.attach(servoPin);
      //myServo.write(45);
      tone(buzzerPin, 100, 100);
      //delay(200);
      //myServo.detach();
      
      
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
