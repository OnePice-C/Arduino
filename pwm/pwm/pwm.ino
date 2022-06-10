int led = 10;
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  
  digitalWrite(led, HIGH);
  delayMicroseconds(350);
  digitalWrite(led, LOW);
  delayMicroseconds(150);
}
