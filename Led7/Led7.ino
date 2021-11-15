
#include <TimerOne.h>

int nguoc = 11;
int thuan = 12;
int moto1 = 9;
int led =13;  

const int G = 8; // G= Arduino chân 8
const int F = 7; // F= Arduino chân 7
const int A = 2; // A = Arduino chân 2
const int B = 3; // B = Arduino chân 3
const int E = 6; // E = Arduino chân 6
const int D = 5; // D = Arduino chân 5
const int C = 4; // C = Arduino chân 4
const int dp = 9; // dp = Arduino chân 9
const int second = 1; 
const int digit = 10; // Số hiển thị

const int segment = 7; // 7 thanh led

byte digseg[digit][segment] = {
{ 1,1,1,1,1,1,0 }, // = 0
{ 0,1,1,0,0,0,0 }, // = 1
{ 1,1,0,1,1,0,1 }, // = 2
{ 1,1,1,1,0,0,1 }, // = 3
{ 0,1,1,0,0,1,1 }, // = 4
{ 1,0,1,1,0,1,1 }, // = 5
{ 1,0,1,1,1,1,1 }, // = 6
{ 1,1,1,0,0,0,0 }, // = 7
{ 1,1,1,1,1,1,1 }, // = 8
{ 1,1,1,1,0,1,1 } // = 9
};
void blinkLED(void); // hàm nguyên mẫu

void setup() {
  
pinMode(A, OUTPUT);
pinMode(B, OUTPUT);
pinMode(C, OUTPUT);
pinMode(D, OUTPUT);
pinMode(E, OUTPUT);
pinMode(F, OUTPUT);
pinMode(G, OUTPUT);
pinMode(dp, OUTPUT);

digitalWrite(dp, LOW); // tắt dấu chấm


  pinMode(led, OUTPUT);
  Timer1.initialize(500000); //Khởi động ngắt Timer1 (1tr = 1s)
  Timer1.attachInterrupt(blinkLED);
  
  

  
}

  int ledState = LOW; // khai báo biến lưu mức logic 0 để điều khiển led sáng tắt
  volatile unsigned long blinkCount = 0; // khai báo biến lưu giá trị đếm ban đầu = 0


void writeDigit(byte digit)
{
byte pin = 2; 
byte seg;
for (seg = 0; seg < 7; seg++)
{
digitalWrite(pin, digseg[digit][seg]);
pin++;
}
}
void loop()
{

unsigned long blinkCopy; // đếm số lần led sáng
  noInterrupts();
  blinkCopy = blinkCount;
  interrupts();

  writeDigit(blinkCopy); //ghi vào led 7 thanh số lầm led sáng
  delay(second);

  Timer1.pwm(moto1, 600); 
  
  /*******************************************************************************************/
  
  int a = analogRead(A4);           // đọc giá trị analog từ chân A4
  int b = map(a, 0, 1023, 0, 255);  // chuyển đổi thang đo
  analogWrite(thuan, a/5);             // ghi giá trị chuyển đổi vào quay thuận
  analogWrite(nguoc, b);
 
}

void blinkLED(void)
{
  if (ledState == LOW) {
    ledState = HIGH;
    blinkCount = blinkCount + 1;  // Tăng biến đếm mỗi khi LED sáng
    if(blinkCount == 10)
     {
      blinkCount = 0;
      //Timer1.stop();
     }
   } 
  else {
    ledState = LOW;
  }
  
    digitalWrite(led, ledState);
}
