#include <Servo.h>

Servo myservo;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  Serial.begin(9600);
  Serial.println("Test pentru motoras deoarece daca il adaugam. in traffic lighter nu mergea");
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int pos=0;pos<=180;pos++){
    myservo.write(pos);
    Serial.println(pos);
    delay(30);
  }

  Serial.println("Am ajuns la 180. Reveniim la 0 ....");

  for(int pos=180;pos>=0;pos--){
    myservo.write(pos);
    Serial.println(pos);
    delay(30);
  }

  delay(500);
}
