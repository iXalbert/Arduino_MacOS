const int segA = 2;
const int segB = 3;
const int segC = 4;
const int segD = 5;
const int segE = 6;
const int segF = 7;
const int segG = 8;
const int segDP = 11; 

const int StickX = A0;
const int StickY = A1;
const int StickButton = 10;

byte cifre[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

int nr_actual = 0;

void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i <= 8; i++) 
    pinMode(i, OUTPUT);
  pinMode(segDP, OUTPUT);
  
  pinMode(StickButton, INPUT_PULLUP);
  Serial.begin(9600);
  
  afisare(0); 
}

void afisare(int n) {
  digitalWrite(segA, cifre[n] & 0b00000001);
  digitalWrite(segB, cifre[n] & 0b00000010);
  digitalWrite(segC, cifre[n] & 0b00000100);
  digitalWrite(segD, cifre[n] & 0b00001000);
  digitalWrite(segE, cifre[n] & 0b00010000);
  digitalWrite(segF, cifre[n] & 0b00100000);
  digitalWrite(segG, cifre[n] & 0b01000000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xVal = analogRead(StickX);
  
  // Calculam deviatia fata de centru (512)
  int deviatie = abs(xVal - 512);

  if(deviatie > 150) {
    // Mapam deviatia la viteza (0-512 deviatie -> 600-70ms delay)
    int viteza = map(deviatie, 0, 512, 600, 70);
    
    nr_actual = (nr_actual + 1) % 10;
    afisare(nr_actual);
    delay(viteza);
  }

  if(digitalRead(StickButton) == LOW) {
    for(int i = 0; i < 4; i++) {
      afisare(nr_actual);
      digitalWrite(segDP, HIGH); 
      delay(80);
      
      for(int j = 2; j <= 8; j++) digitalWrite(j, LOW);
      digitalWrite(segDP, LOW);
      delay(80);
    }

    afisare(nr_actual); 
    while(digitalRead(StickButton) == LOW);
    delay(200); 
  }
}