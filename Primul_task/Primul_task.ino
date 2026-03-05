void setup() {
  // Setăm pinul 13 (unde e conectat ledul portocaliu de pe placă) ca ieșire
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH); // Aprinde ledul
  delay(100);             // Așteaptă 100 milisecunde 
  digitalWrite(13, LOW);  // Stinge ledul
  delay(100);             // Așteaptă 100 milisecunde
}