#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinJoyY = A1;
const int pinJoySW = 10;
const int pinBuzzer = 9;
const int segPini[] = {2, 3, 4, 5, 6, 7, 8}; 


byte navaGrafic[8] = {
  0b00000,
  0b01100, 
  0b11110, 
  0b11111, 
  0b11111, 
  0b11110, 
  0b01100, 
  0b00000
};


int navaPos = 0; 
int scor = 0;
int vieți = 3;
int obstacolX = 15;
int obstacolY = 0;
unsigned long ultimaMiscare = 0;
int viteza = 300;
bool jocActiv = false;

byte cifre[4] = {
  0b00111111, 
  0b00000110, 
  0b01011011, 
  0b01001111  
};

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, navaGrafic);
  
  for(int i = 0; i < 7; i++) pinMode(segPini[i], OUTPUT);
  pinMode(pinJoySW, INPUT_PULLUP);
  
  afiseazaVieti(vieți);
  ecranStart();
}

void loop() {
  if (!jocActiv) {
    if (digitalRead(pinJoySW) == LOW) startJoc();
    return;
  }

  int yVal = analogRead(pinJoyY);
  if (yVal < 400) navaPos = 0;
  if (yVal > 600) navaPos = 1;


  if (millis() - ultimaMiscare > viteza) {
    ultimaMiscare = millis();
    obstacolX--;

    if (obstacolX < 0) {
      obstacolX = 15;
      obstacolY = random(0, 2);
      scor++;
      if (viteza > 100) viteza -= 5; 
    }


    if (obstacolX == 0 && obstacolY == navaPos) {
      coliziune();
    }

    deseneazaEcran();
  }
}

void afiseazaVieti(int v) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPini[i], (cifre[v] >> i) & 0x01);
  }
}

void deseneazaEcran() {
  lcd.clear();
  lcd.setCursor(0, navaPos);
  lcd.write(byte(0)); 
  
  
  lcd.setCursor(obstacolX, obstacolY);
  lcd.print("#"); 
}

void coliziune() {
  tone(pinBuzzer, 200, 300);
  vieți--;
  afiseazaVieti(vieți);
  delay(500);
  
  if (vieți <= 0) {
    gameOver();
  } else {
    obstacolX = 15; 
  }
}

void startJoc() {
  vieți = 3;
  scor = 0;
  viteza = 300;
  jocActiv = true;
  afiseazaVieti(vieți);
  lcd.clear();
}

void ecranStart() {
  lcd.clear();
  lcd.setCursor(3, 0); lcd.print("AVOID GAME");
  lcd.setCursor(2, 1); lcd.print("Press Stick!");
}

void gameOver() {
  jocActiv = false;
  lcd.clear();
  lcd.setCursor(4, 0); lcd.print("GAME OVER");
  lcd.setCursor(3, 1); lcd.print("Score: "); lcd.print(scor);
  tone(pinBuzzer, 100, 1000);
}