#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;  // create servo object to control a servo
Servo myservo4;
Servo myservo5;  // create servo object to control a servo
Servo myservo6;
Servo myservo7;  // create servo object to control a servo
Servo myservo8;
bool monte = true;//false //  BLEUTOOTH
int i = 0 ;    // i est l'étape actuel, pour savoir de combien changer !
int MAXORMIN = 100;
int MINORMAX = 0;

void setup() {
  myservo.attach(3);
  myservo2.attach(6);
  myservo3.attach(9);
  myservo4.attach(10);
  myservo5.attach(3);  // Définir PIN
  myservo6.attach(3);  // Définir PIN
  myservo7.attach(3);  // Définir PIN
  myservo8.attach(3);  // Définir PIN
  Serial.begin(9600);
}

void loop() {
  while (monte) {
    e1();
    affichestat();
    e2();
    affichestat();
    e3();
    affichestat();
    e4();
    affichestat();
  }
}

void affichestat() {
  Serial.print("Bras Gauche : 1="); Serial.print(i * 40 + 64); Serial.print(" et 2="); Serial.println(180 - i * 40 * 1.4);
  Serial.print("Bras Droit : 1="); Serial.print(i * 40 + 64); Serial.print(" et 2="); Serial.println(180 - i * 40 * 1.4);
  Serial.print("Jambe Gauche : 1="); Serial.print(i * 40 + 20); Serial.print(" et 2="); Serial.println(180 - i * 40 * 1.5);
  Serial.print("Jambe Droite : 1="); Serial.print(i * 40 + 20); Serial.print(" et 2="); Serial.println(180 - i * 40 * 1.5);
}


void e1() { // Peut-être i=4 et i-- ?!
  monterb1();
  baisserb2();
  baisserJ1();
  baisserJ2();
  i++;
}

void e2() {
  monterJ1();
  baisserb2();
  baisserb1();
  baisserJ2();
  i++;
}

void e3() {
  monterb2();
  baisserb1();
  baisserJ1();
  baisserJ2();
  i++;
}

void e4() {
  monterJ2();
  baisserb2();
  baisserJ1();
  baisserb1();
  i = 0;
}

void monterb1() {
  myservo.write(MAXORMIN); // Vers arrière
  myservo2.write(MAXORMIN); // Vers arrière
  myservo.write(MINORMAX);
} 

void monterb2() {
  myservo3.write(MAXORMIN); // Vers arrière
  myservo4.write(MAXORMIN) ;// Vers arrière
  myservo3.write(MINORMAX);
} 

void monterJ1() {
  myservo5.write(MAXORMIN) ;// Vers arrière
  myservo6.write(MAXORMIN) ;// Vers arrière
  myservo5.write(MINORMAX);
} 

void monterJ2() {
  myservo7.write(MAXORMIN); // Vers arrière
  myservo8.write(MAXORMIN) ;// Vers arrière
  myservo7.write(MINORMAX);
} 


void baisserb1() {         // pas forcement b1 (EXEMPLE)
  myservo.write(i * 50 + 64); // le 50 est arbitraire !
  myservo2.write(180 - i * 40 * 1.4); // le 50 est arbitraire !
}

void baisserb2() {         // pas forcement b2 (EXEMPLE)
  myservo5.write(i * 50 + 64); // le 50 est arbitraire !
  myservo6.write(180 - i * 40 * 1.4); // le 50 est arbitraire !
}

void baisserJ1() {         // pas forcement J1 (EXEMPLE)
  myservo3.write(i * 50 + 20); // le 50 est arbitraire !
  myservo4.write(180 - i * 40 * 1.5); // le 50 est arbitraire !
}

void baisserJ2() {         // pas forcement J2 (EXEMPLE)
  myservo7.write(i * 50 + 20); // le 50 est arbitraire !
  myservo8.write(180 - i * 40 * 1.5); // le 50 est arbitraire !
}
