#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinJoyX = A0;
const int pinJoySw = 10;
const int pinBuzzer = 9;
//                      
const int segPin[] = {4,8,12,3,13,5,6};

Servo myServo;

byte men[8] = {

  0b00100, 
  0b01110, 
  0b10101, 
  0b00100, 
  0b01110, 
  0b01010, 
  0b01010,
  0b00000
};

byte harta[16];

int menPos = 0;
int scor = 0;
int vieti = 3;

unsigned long ultimaMiscare = 0;
int viteza = 300;
bool jocPlay = false;

byte cifre[4] = {

  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111  // 3

};

void setup() {
  // put your setup code here, to run once:

  lcd.init();
  lcd.backlight();
  lcd.createChar(0, men);

  for(int i = 0 ; i < 7; i++){
      pinMode(segPin[i], OUTPUT);
  }

  myServo.attach(2);
  myServo.write(90);

  pinMode(pinJoySw, INPUT_PULLUP);

  afiseazaVieti(vieti);
  resetHarta();
  ecranStart();
}

void loop() {
  // put your main code here, to run repeatedly:

  if(!jocPlay){
    if(digitalRead(pinJoySw) == LOW)
      startJoc();
    return;
  }

  int xVal = analogRead(pinJoyX);
  if(xVal < 400){
    menPos = 0;
  }
  if(xVal > 600){
    menPos = 1;
  }

  if (millis() - ultimaMiscare > viteza) {
    ultimaMiscare = millis();
    /*obstacolX--;

    if(obstacolX < 0){
      obstacolX = 15;
      obstacolY = random(0,2);
      scor++;
      if(viteza > 100){
        viteza -= 5;
      }
    }

    if(obstacolX == 0 && obstacolY == men){
      coliziune();
    }

    deseneazaEcran();
    */

    if(harta[0] == 1 && menPos == 0)
      coliziune();
    if(harta[0] == 2 && menPos == 1)
      coliziune();
    if(harta[0] == 3)
      coliziune();

    for(int i = 0 ; i < 15 ; i++){
      harta[i] = harta[i+1];
    }

    if(harta[14] != 0){
      harta[15] = 0;
    }
    else if(harta[13] != 0){
      harta[14] = 0;
      harta[15] = 0;
    }
    else if(random(0, 10) > 8){
        harta[15] = random(1 ,3);
    }else{
        harta[15] = 0;
    }

    scor++;

    if(scor % 10 == 0 && viteza > 150)
      viteza -= 10;

    deseneazaHarta();
  }
}

void afiseazaVieti(int v){

  for(int i = 0 ; i < 7; i++){
      digitalWrite(segPin[i], (cifre[v] >> i) & 0x01);
  }
}

void deseneazaHarta() {
  lcd.clear();
  
  lcd.setCursor(0, menPos);
  lcd.write(byte(0));


  for (int i = 1; i < 16; i++) {
    if (harta[i] == 1 || harta[i] == 3) {
      lcd.setCursor(i, 0); lcd.print("#");
    }
    if (harta[i] == 2 || harta[i] == 3) {
      lcd.setCursor(i, 1); lcd.print("#");
    }
  }
}

void deseneazaEcran(){

  lcd.clear();
  lcd.setCursor(0, men);
  lcd.write(byte(0));

  //lcd.setCursor(obstacolX, obstacolY);
  lcd.print("#");
}

void coliziune(){

    tone(pinBuzzer, 200, 300);
    vieti--;
    afiseazaVieti(vieti);
    //delay(500);

    myServo.write(45);
    delay(100);
    myServo.write(180);

    if(vieti <= 0){
      gameOver();
      delay(1000);
    }

    delay(300);

}

void startJoc(){

  vieti = 3;
  scor = 0;
  viteza = 400;
  jocPlay = true;
  myServo.write(180);
  afiseazaVieti(vieti);
  //lcd.clear();
}

void ecranStart(){

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("DODGE MAN");
  lcd.setCursor(2, 1);
  lcd.print("Press Stick !! ");
}

void resetHarta(){

  for(int i = 0 ; i < 16 ; i++){

      harta[i] = 0;
  }
}

void gameOver(){

  jocPlay = false;
  lcd.clear();
  myServo.write(0);
  lcd.setCursor(4, 0);
  lcd.print("GAME OVER");
  lcd.setCursor(3,1);
  lcd.print("Score : ");
  lcd.print(scor);  
  tone(pinBuzzer, 100, 1000);

  delay(1000);  

  lcd.setCursor(0, 1);

  while(digitalRead(pinJoySw) == HIGH){

  }

  while(digitalRead(pinJoySw) == LOW);
  delay(200);

  ecranStart();
}
