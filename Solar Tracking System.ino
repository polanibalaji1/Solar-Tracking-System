
#include<Servo.h>0
int i=0;
#define servo_pin 5
Servo servo;
void setup() 
{
  pinMode(4,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  Serial.begin(9600);
  servo.attach(servo_pin);
  servo.write(0);
}

void loop() 
{
 
  if(digitalRead(4)==0 && digitalRead(7)==1 && digitalRead(8)==1 &&(i==0 || i==3))
  {
    i=1;
    Serial.print("LDR-1 Value :");
    Serial.println(i);
    servo.write(15);
    delay(1000);
  }

  else if(digitalRead(7)==0 && digitalRead(4)==1 && digitalRead(8)==1 && i==1)
  {
    i=2;
    Serial.print("LDR-2 Value :");
    Serial.println(i);
    servo.write(60);
    delay(1000);
  }
  
  else if(digitalRead(8)==0 && digitalRead(4)==1 && digitalRead(7)==1 && i==2)
  {
    i=3;
    Serial.print("LDR-3 Value :");
    Serial.println(i);
    servo.write(110);
    delay(1000);
  }
  else if(digitalRead(8)==1 && digitalRead(4)==1 && digitalRead(7)==1 && i==3)
  {
    i=0;
    Serial.print("All LDRs Closed :");
    Serial.println(i);
    servo.write(0);
    delay(1000);
  }
  else
  {
       delay(5);
  }
}
