byte ledPin[] = {0,1,2,3,4,5,6,7}; 
byte kichthuoc;
void setup()
{
  kichthuoc = sizeof(ledPin);  
  for (int i=0;i<kichthuoc;i++)
    {
    pinMode(ledPin[i],OUTPUT);  //Các chân LED là OUTPUT
    digitalWrite(ledPin[i],LOW); //Mặc định các đèn LED sẽ tắt
    }
}
void traiphai();
void ngoaivao();
void forlong();
void sangtat();


void loop() 
{
  
  
  sangtat();
  traiphai();
  ngoaivao();
  forlong();
  
}

void traiphai()
{
    
    // Bật tuần tự các đèn LED
    
  for (int i=0; i <= kichthuoc; i++) 
  {
    digitalWrite(ledPin[i],HIGH); //Bật led
    delay(1000); 
  }
  

   // Tắt tuần tự các đèn LED
  for (int i =0; i <= kichthuoc; i++) 
  {
    digitalWrite(ledPin[i],LOW); // Tắt led
    delay(1000); 
  }
}

void ngoaivao()
{

   digitalWrite(ledPin[0], HIGH); // 2 led ngoài cùng sáng
   digitalWrite(ledPin[7], HIGH);
       delay(1000);
   digitalWrite(ledPin[1], HIGH); // 2 led tiếp theo sáng
   digitalWrite(ledPin[6], HIGH);
       delay(1000);
   digitalWrite(ledPin[2], HIGH); 
   digitalWrite(ledPin[5], HIGH);
       delay(1000);
   digitalWrite(ledPin[3], HIGH); // 2 led trong cùng sáng
   digitalWrite(ledPin[4], HIGH);
        delay(1000);
   digitalWrite(ledPin[3], LOW); // 2 led trong cùng tắt
   digitalWrite(ledPin[4], LOW);
       delay(1000);
   digitalWrite(ledPin[2], LOW);
   digitalWrite(ledPin[5], LOW);
       delay(1000);
   digitalWrite(ledPin[1], LOW);
   digitalWrite(ledPin[6], LOW);
       delay(1000);
   digitalWrite(ledPin[0], LOW); // 2 led ngoài cùng tắt
   digitalWrite(ledPin[7], LOW);
        delay(1000);
   
}
void forlong()
{
  for(int i=0; i<=3; i++)
  {
   digitalWrite(ledPin[i], HIGH); // led 0 sáng dần đến led 4 sau mỗi lần 4 led từ 4 -> 8 sáng 
   
    for(int a=4; a<=8; a++)
    {
       digitalWrite(ledPin[a], HIGH); // led 4- 8 sáng
       delay(1000);
    }

    for(int b=4; b<=8; b++)
    {
       digitalWrite(ledPin[b], LOW); // led 4 -8 off

    }
  }
}
void sangtat()
{
 for ( int i= 0; i<kichthuoc; i++)
 {
    digitalWrite(ledPin[i],HIGH); //Bật led
    delay(1000);
     digitalWrite(ledPin[i],LOW); // Tắt led
    delay(1000); 
 }
 
}
