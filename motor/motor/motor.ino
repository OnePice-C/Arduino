// moto quay thuận 30s dừng 5s quay ngược 40s dừng 5s


void setup() {
  
  pinMode(10, OUTPUT); // 10 moto quay thuan
  pinMode(11, OUTPUT); // 11 moto quay nguoc
}

void thuan(void);
void nguoc(void);

void loop() {
  thuan();
  delay(5000);
  nguoc();
  delay(5000);

}

void thuan(void)
{
  analogWrite(10, 204); // duty 80%
  delay(30000);
  analogWrite(10, LOW);
}

void nguoc(void)
{
  analogWrite(11, 204);
  delay(40000);
  analogWrite(11, LOW);
}
