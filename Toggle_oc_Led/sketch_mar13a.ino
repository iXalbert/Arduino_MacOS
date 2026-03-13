const int ledPin = 13;
const int buttonPin = 2;

int starePin = LOW;
int stareButton;
int ultimaStareButton = HIGH;

unsigned long ultimulTimp = 0;
unsigned long timpBounce = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(ledPin, starePin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int citire = digitalRead(buttonPin);

  if(citire != ultimaStareButton){
    ultimulTimp = millis();
  }

  if((millis() - ultimulTimp) > timpBounce){

    if(citire != stareButton){

      if(stareButton == LOW){
        starePin = !starePin;
        Serial.println(starePin == HIGH ? "Led pornit" : "Led oprit");
      }
    }
  }

  digitalWrite(ledPin, starePin);
  ultimaStareButton = citire;
}
