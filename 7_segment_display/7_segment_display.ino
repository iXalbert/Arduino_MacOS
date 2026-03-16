#include <IRremote.hpp>

const int segA = 4;
const int segB = 5;
const int segC = 6;
const int segD = 7;
const int segE = 8;
const int segF = 9;
const int segG = 10;
const int segDP = 11;

const int dig1 = 12; //pt mii
const int dig2 = 13; //pt sute
const int dig3 = A2; //pt zeci
const int dig4 = A3; //pt unitate

const int IRPin = 2;

//merge asa avem catod comun
byte cifre[10] =
{
  0b00111111, //0
  0b00000110, //1
  0b01011011, //2
  0b01001111, //3
  0b01100110, //4
  0b01101101, //5
  0b01111101, //6
  0b00000111, //7
  0b01111111, //8
  0b01100111, //9
};

int nr = 0;
unsigned long lastUp = 0;
bool numar = false;

bool timer = false;
unsigned long lastBlink = 0;
bool Blinky = true;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0 ; i < 13; i++)
  pinMode(i, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);

  IrReceiver.begin(IRPin);
  Serial.begin(9600);
}

//facem vizibile segmentele in functie de ce ne cere
void seven_segment(int n){
  digitalWrite(segA, cifre[n] & 0b00000001);
  digitalWrite(segB, cifre[n] & 0b00000010);
  digitalWrite(segC, cifre[n] & 0b00000100);
  digitalWrite(segD, cifre[n] & 0b00001000);
  digitalWrite(segE, cifre[n] & 0b00010000);
  digitalWrite(segF, cifre[n] & 0b00100000);
  digitalWrite(segG, cifre[n] & 0b01000000);
}

void lights_out(){
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(IrReceiver.decode()){
    unsigned int command = IrReceiver.decodedIRData.command;

    Serial.print("Comanda : ");
    Serial.println(command);
    Serial.println(command, HEX);

    if(command == 0x45)
      nr += 1; //o secunda;
    if(command == 0x46)
      nr += 10;//10 sec;
    if(command == 0x47)
      nr += 100;//100 secunde;
    if(command == 0x44)
      nr = 0; //reset
    if(command == 0x1C)
      numar = !numar; // start stop
    if(command == 0x19)
      timer = false;
    IrReceiver.resume();
  }

  if(numar && nr > 0){
    if(millis() - lastUp >= 1000){
      lastUp = millis();
      nr--;
      if(nr == 0){
        timer = true;
        numar = false;
      }
    }
  }

/*
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, LOW);
*/

  if(timer){
    if(millis() - lastBlink >= 300){
      lastBlink = millis();
      Blinky = !Blinky;
    }
  }else{
    Blinky = true;
  }

  if(Blinky){

  lights_out();
  seven_segment((nr / 1000) % 10);
  digitalWrite(dig1, LOW);
  delay(2);

  lights_out();
  seven_segment((nr / 100) % 10);
  digitalWrite(dig2, LOW);
  delay(2);

  lights_out();
  seven_segment((nr / 10) % 10);
  digitalWrite(dig3, LOW);
  delay(2);

  lights_out();
  seven_segment((nr / 1) % 10);
  digitalWrite(dig4, LOW);
  delay(2);

  //seven_segment(nr % 10);

  lights_out();

  delay(5);
  
  }else{
    lights_out();
    delay(5);
  }

}
