#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
Servo myservo7;
Servo myservo8;

bool monte = true;
int speed_exec = 10;
int t = 0;
int total_t = 0;
int t2 = 0;
int code_erreur = 0;
char message_bt = ' ';

void setup()
{
  Serial.begin(9600);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
  digitalWrite(20, LOW);     // alimentation du capteur bluetooth sans fil supplémentaire
  digitalWrite(21, HIGH);    // (RX,TX,GND,VCC)->(TX:18,RX:19,GND:20,VCC:21)
  Serial1.begin(9600);       // pin 18(tx) et 19(rx) pour la liaison bluetooth
  myservo1.attach(2); // bras 1
  myservo2.attach(3);
  myservo3.attach(4); // bras2
  myservo4.attach(5);
  myservo5.attach(6); // jambe 1
  myservo6.attach(7);
  myservo7.attach(14); // jambe 2
  myservo8.attach(13);
}

void loop(){
  for (int i=20; i<150;i++){
  go(i);
  delay(30);
  }
  delay(100);
  for (int i=20; i<150;i++){
  go2(i);
  delay(30);
  }
  delay(100);
  for (int i=150; i>20;i--){
  go(i);
  delay(30);
  }
  delay(100);
  for (int i=150; i>20;i--){
  go2(i);
  delay(30);
  }
  delay(100);
}


void go(int t)
{
  myservo1.write(t);
  myservo2.write(t);
  myservo3.write(t);
  myservo4.write(t);    
}
void go2(int){
  myservo5.write(t);
  myservo6.write(t);
  myservo7.write(t);
  myservo8.write(t);
  }
