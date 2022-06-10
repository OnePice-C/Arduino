#include <TimerOne.h>

int led[] = {0,1,2,3,4,5,6,7};  

void setup(void)
{
  for(int i=0; i<=8; i++)
  {
    pinMode(led[i], OUTPUT);
  }
  pinMode(led, OUTPUT);
  Timer1.initialize(300000); //Khởi động ngắt Timer1 tràn mỗi 0.30s
  Timer1.attachInterrupt(blinkLED); // blinkLED to run every 0.15 seconds
}



int ledState = LOW;
volatile unsigned long blinkCount = 0; //biến đếm số lần Led sáng

void blinkLED(void)
{
  if (ledState == LOW) {
    ledState = HIGH;
    blinkCount = blinkCount + 1;  // Tăng biến đếm mỗi khi LED sáng
  } else {
    ledState = LOW;
  }
  for(int i=0; i<=8; i++)
  {
    digitalWrite(led[i], ledState);
  }
}

void loop(void)
{
  unsigned long blinkCopy;  // biến linkCopy được dùng để copy số lần LED từ biến blinkCount
  //tắt ngắt nhằm tránh trường hợp biến blinkCount thay đổi (do ngắt timer xảy ra) trong quá trình copy.
  noInterrupts();
  blinkCopy = blinkCount;
  interrupts();

}
