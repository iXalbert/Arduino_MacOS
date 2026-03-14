#include <IRremote.h>

const int IRPin = 11;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IRPin, ENABLE_LED_FEEDBACK);
  Serial.println("IR signal ");
}

void loop() {
  if (IrReceiver.decode()) {

    Serial.print("Codul este : ");
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    
    IrReceiver.resume(); 
  }
}