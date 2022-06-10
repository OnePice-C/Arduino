// Thiết kế mạch và viết chương trình đếm số lần nhấn công tắc trên chân 13 hiển thị trên 1 LED 7 thanh.   
/* 
 A = 2; 
 B = 3; 
 C = 4;
 D = 5; 
 E = 6; 
 F = 7; 
 G = 8; 
 dp = 9; 
*/

int button =13;

const int number = 10; // số hiển thị từ 0 - 9
const int ledseg = 7; // 7 thanh led 

byte arrayled7[number][ledseg] = 
{
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

void setup() 
{
  for(int i = 2; i<10; i++)
  {
    pinMode(i, OUTPUT);
  }
  digitalWrite(9, HIGH);
}

volatile int dem = 0; // biến có thể thay đổi bất cứ khi nào

void Seg7write(byte number)
{
  byte pin = 2; 
  for (int i = 0; i < 7; i++)
    {
      digitalWrite(pin, arrayled7[number][i]);
      pin++;
    }
}

void loop()
{
  Seg7write(dem);
  int Read7 = digitalRead(button);
    if ( Read7 == HIGH)
    {
      delay(350); // mọi tác động vào sw trong 0.35s đều không được chấp thuận.
      if ( Read7 == HIGH)
      {
        dem += 1;
        if(dem == 10)
        {
          dem = 0;
        }
      }
    } 
}
