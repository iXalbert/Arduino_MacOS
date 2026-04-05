#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;

const int pinJoyX = A1;
const int pinJoySw = 10;
const int pinBuzzer = 9;

const int COD_Corect[3] = {0, 0, 0};
int COD_Introdus[3] = {0, 0 ,0};
int poz_cifra = 0; //pentru codul nostru 0,1,2
int incercariRamase = 3;
bool seifDeschis = false; 

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  myServo.attach(11);
  myServo.write(0);

  pinMode(pinJoySw, INPUT_PULLUP);

  ecranInitial();
}

void loop() {
  // put your main code here, to run repeatedly:

  if(seifDeschis){
    if(digitalRead(pinJoySw) == LOW)
      blocheazaSeif();
    return;
  }

  if(incercariRamase <= 0){
    alarma();
    return;
  }

  int xVal = analogRead(pinJoyX);
  if(xVal < 300){
    COD_Introdus[poz_cifra++];
    if(COD_Introdus[poz_cifra] > 9)
      COD_Introdus[poz_cifra] = 0;
    tone(pinBuzzer, 1000, 50);
    actualizareLCD();
    delay(300);
  }

  if (xVal > 700) {
    COD_Introdus[poz_cifra]--;
    if (COD_Introdus[poz_cifra] < 0) COD_Introdus[poz_cifra] = 9;
    tone(pinBuzzer, 800, 50);
    actualizareLCD();
    delay(300);
  }

  if(digitalRead(pinJoySw) == LOW){
    delay(200);
    tone(pinBuzzer, 1500, 100);
    poz_cifra++;

    if(poz_cifra > 2){
      verificaCod();
    }else{
      actualizareLCD();
    }
    while(digitalRead(pinJoySw) == LOW);
  }
}

void actualizareLCD(){

  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Introdu  Codul");
  lcd.setCursor(3, 1);
  for(int i=0;i<3;i++){
    if(i == poz_cifra)
      lcd.print("> ");
    else
      lcd.print(" ");
    lcd.print(COD_Introdus[i]);
    lcd.print(" ");
  }
}

void verificaCod(){

  bool corect = true;
  for(int i=0;i<3;i++){
    if(COD_Introdus[i] != COD_Corect[i])
      corect = false;
  }

  if(corect){
    deschideSeif();
  }else{
    gresit();
  }
}

void deschideSeif(){

  seifDeschis = true;
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("ACCES OKEY");
  lcd.setCursor(2, 1);
  lcd.print("SEIF DESCHIS");
  myServo.write(90);
  tone(pinBuzzer, 2000, 500);
}

void gresit(){

  incercariRamase--;
  lcd.clear();
  lcd.setCursor(3, 0); lcd.print("COD GRESIT!");
  tone(pinBuzzer, 200, 500);
  delay(1500);
  poz_cifra = 0; 
  actualizareLCD();
}

void blocheazaSeif(){

  seifDeschis = false;
  poz_cifra = 0;
  for(int i=0;i<3;i++){
    COD_Introdus[i] = 0;
  }

  myServo.write(0);
  lcd.clear();
  lcd.print(" BLOCARE... ");
  delay(1000);
  actualizareLCD();
}

void alarma(){

  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("BLOCAT!! ");
  lcd.setCursor(2, 1);
  lcd.print("CALL  112...");
  tone(pinBuzzer, 1000);
  delay(200);
  tone(pinBuzzer, 500);
  delay(200);
}

void ecranInitial(){
  actualizareLCD();
}