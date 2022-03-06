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
int code_erreur = 0;
char message_bt = ' ';
int i = 0;
int t1 = 20;
int t2 = 52;
int t3 = 84;
int t4 = 126;
int tp1 = 1;
int tp2 = 1;
int tp3 = 1;
int tp4 = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
  digitalWrite(20, LOW);  // alimentation du capteur bluetooth sans fil supplémentaire
  digitalWrite(21, HIGH); // (RX,TX,GND,VCC)->(TX:18,RX:19,GND:20,VCC:21)
  Serial1.begin(9600);    // pin 18(tx) et 19(rx) pour la liaison bluetooth
  myservo1.attach(2);     // bras 1
  myservo2.attach(3);
  myservo3.attach(4); // bras2
  myservo4.attach(5);
  myservo5.attach(6); // jambe 1
  myservo6.attach(7);
  myservo7.attach(8); // jambe 2
  myservo8.attach(10);
}

void loop()
{
  go1(t1);      //J1 complete
  go2(t2);     //J2 complete
  go3(t3); // B2 complet
  go4(t4); //  B1 complet
  if (t1 >= 150)
  {
    tp1 = -4;
  }
  if (t2 >= 150)
  {
    tp2 = -4;
  }
  if (t3 >= 150)
  {
    tp3 = -4;
  }
  if (t4 == 150)
  {
    tp4 = -4;
  }
  if (t1 <= 20)
  {
    tp1 = 1;
  }
  if (t2 <= 20)
  {
    tp2 = 1;
  }
  if (t3 <= 20)
  {
    tp3 = 1;
  }
  if (t4 <= 20)
  {
    tp4 = 1;
  }
  t1 += tp1;
  t2 += tp2;
  t3 += tp3;
  t4 += tp4;
  delay(15 - speed_exec);
  Serial1.println("[" + String(myservo1.read()) + "," + String(myservo2.read()) + "," + String(myservo3.read()) + "," + String(myservo4.read()) + "," + String(myservo5.read()) + "," + String(myservo6.read()) + "," + String(myservo7.read()) + "," + String(myservo8.read()) + "," + String(t1) + "," + String(speed_exec) + "," + String(code_erreur) + "]");
  Serial.println("[" + String(myservo1.read()) + "," + String(myservo2.read()) + "," + String(myservo3.read()) + "," + String(myservo4.read()) + "," + String(myservo5.read()) + "," + String(myservo6.read()) + "," + String(myservo7.read()) + "," + String(myservo8.read()) + "," + String(t1) + "," + String(speed_exec) + "," + String(code_erreur) + "]");
  code_erreur = 0;
  while (Serial1.available() >= 1)
  {
    message_bt = Serial1.read();
    switch (message_bt)
    {
    case 'P':
      monte = false;
      break;
    case 'S':
      monte = true;
      break;
    case '0':
      speed_exec = 0;
      Serial.println("Vitesse 0");
      break;
    case '1':
      speed_exec = 1;
      break;
    case '2':
      speed_exec = 2;
      break;
    case '3':
      speed_exec = 3;
      break;
    case '4':
      speed_exec = 4;
      break;
    case '5':
      speed_exec = 5;
      break;
    case '6':
      speed_exec = 6;
      break;
    case '7':
      speed_exec = 7;
      break;
    case '8':
      speed_exec = 8;
      break;
    case '9':
      speed_exec = 9;
      break;
    case 'T':
      while (Serial1.available())
      {
        Serial.println(Serial1.read()); // completement inutile
      }
      break;
    default:
      break;
    }
  }
}

void go1(int t)
{  myservo3.write(t);

  myservo2.write(t);
}
void go2(int t)
{  myservo7.write(180 - t);

  myservo4.write(180 - t);
}
void go3(int t)
{
  myservo5.write(180 - t);
  myservo6.write(180 - t);
}
void go4(int t)
{
  myservo1.write(t);

  myservo8.write(t);
}
