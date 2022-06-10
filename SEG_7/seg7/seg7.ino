// đếm từ 00 => 99 bằng led 7 thanh
/*
 A = 0;   A1 = 7
 B = 1;   B1 = 8
 C = 2;   C1 = 9
 D = 3;   D1 = 10
 F = 5;   F1 = 12
 G = 6;   G1 = 13
 */
const int number = 10;
const int ledseg= 7;

byte seg7[number][ledseg]=
{
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}, //9
};

void setup() {
  for( int i =0; i<14; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, HIGH);
}

void quetled1 (int a);
void quetled2 (int b);

void loop() {
  for(int i = 0; i< 10; i++)
  {
    quetled1(i);
    for (int j = 0; j<10; j++)
     {
        quetled2(j);
        delay(100);
        if(i == 1 && j == 9)
        {
          return 0;
        }
     }
  }
}

void quetled1(int a)
{
  for(int pinseg1 =0; pinseg1 < 7; pinseg1++)
  {
    digitalWrite(pinseg1, seg7[a][pinseg1]);
  }
}
void quetled2 (int b)
{
  int pinseg2 = 7;
  for ( int i = 0; i <7; i++)
  {
    digitalWrite( pinseg2, seg7[b][i]);
    pinseg2++;
  }
}
