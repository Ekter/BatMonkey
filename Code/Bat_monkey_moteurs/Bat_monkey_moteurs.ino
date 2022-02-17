#include <Servo.h>

Servo myservo1; // create servo object to control a servo
Servo myservo2;
Servo myservo3; // create servo object to control a servo
Servo myservo4;
Servo myservo5; // create servo object to control a servo
Servo myservo6;
Servo myservo7; // create servo object to control a servo
Servo myservo8;
bool monte = true; // false //  BLEUTOOTH
int i = 0;         // i est l'étape actuel, pour savoir de combien changer !
int MAXORMIN = 100;
int MINORMAX = 0;
int minj1 = 50;
int minj2 = 210;

void setup()
{
  myservo1.attach(8);
  myservo2.attach(9);
  myservo3.attach(3);
  myservo4.attach(3);
  myservo5.attach(10);
  myservo6.attach(11);
  myservo7.attach(14);
  myservo8.attach(13);
  Serial.begin(9600);
}

void loop()
{
  while (monte)
  {
    monterJ1();
    monterJ2();
    monterb1();
    for (i = 0; i <= 100; i++)
    {
      baisserJ1(i);
      baisserJ2(i);
      baisserb1(i);
      delay(50);
    }
    /*e1();
      affichestat();
      delay(1000);

      e2();
      affichestat();
      delay(1000);

      e3();
      affichestat();
      delay(1000);

      e4();
      affichestat();
      delay(1000);*/
  }
}

void affichestat()
{
  Serial.print("Bras Gauche : 1=");
  Serial.print(i * 40 + 64);
  Serial.print(" et 2=");
  Serial.println(180 - i * 40 * 1.4);
  Serial.print("Bras Droit : 1=");
  Serial.print(i * 40 + 64);
  Serial.print(" et 2=");
  Serial.println(180 - i * 40 * 1.4);
  Serial.print("Jambe Gauche : 1=");
  Serial.print(i * 40 + 20);
  Serial.print(" et 2=");
  Serial.println(180 - i * 40 * 1.5);
  Serial.print("Jambe Droite : 1=");
  Serial.print(i * 40 + 20);
  Serial.print(" et 2=");
  Serial.println(180 - i * 40 * 1.5);
}

void e1()
{
  monterb1();
  baisserb2(i);
  baisserJ1(i);
  baisserJ2(i);
  i++;
}

void e2()
{
  monterJ1();
  baisserb2(i);
  baisserb1(i);
  baisserJ2(i);
  i++;
}

void e3()
{
  monterb2();
  baisserb1(i);
  baisserJ1(i);
  baisserJ2(i);
  i++;
}

void e4()
{
  monterJ2();
  baisserb2(i);
  baisserJ1(i);
  baisserb1(i);
  i = 0;
}

void monterb1()
{
  myservo2.write(150);
  delay(250);
  myservo1.write(90);

  delay(250);
  myservo1.write(110);
  delay(2050);
}

void monterb2()
{
  delay(250);
  myservo3.write(100); // Vers arrière
  delay(250);
  myservo4.write(100); // Vers arrière
  delay(250);
  myservo3.write(0);
}

void monterJ1()
{
  delay(250);
  myservo5.write(30);
  delay(250);
  myservo6.write(minj1);
  delay(250);
  myservo5.write(60);
  delay(250);
}

void monterJ2()
{
  delay(250);
  myservo7.write(100); // Vers arrière
  delay(250);
  myservo8.write(100); // Vers arrière
  delay(250);
  myservo7.write(0);
}

void baisserb1(int t)
{
  myservo1.write(110 - t / 1.4);
  myservo2.write(150 - t * 1.2);
}

void baisserb2(int t)
{
  myservo3.write(180 - t / 1.4);
  myservo4.write(minj2 - t);
}

void baisserJ1(int t)
{
  myservo5.write(100 + t / 1.4);
  myservo6.write(minj1 + t);
}

void baisserJ2(int t)
{
  myservo7.write(180 - t / 1.4);
  myservo8.write(minj2 - t);
}
