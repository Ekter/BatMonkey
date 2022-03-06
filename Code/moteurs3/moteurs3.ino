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
  attachbetter(myservo1, 2); // bras 1
  attachbetter(myservo2, 10);
  attachbetter(myservo3, 4); // bras2
  attachbetter(myservo4, 5);
  attachbetter(myservo5, 7); // jambe 1
  attachbetter(myservo6, 6);
  attachbetter(myservo7, 8); // jambe 2
  attachbetter(myservo8, 3);
}

void loop()
{
  if (monte)
  {
    t++;
    if (t >= 256)
    {
      t = 0;
    }
    positionservos(t);
    Serial.println(t);
  }
  else
  {
    if (total_t > 100 + t2) // pour n'afficher qu'une fois toutes les 100 ms
    {                       // pas nécessaire, juste pour les tests
      Serial.println("EN PAUSE");
      t2 = total_t;
    }
  }
  total_t += 15 - speed_exec; // vitesse min=0  -> boucle en 3840 ms   ~ 2.5 fois plus lent
  Serial1.println("[" + String(myservo1.read()) + "," + String(myservo2.read()) + "," + String(myservo3.read()) + "," + String(myservo4.read()) + "," + String(myservo5.read()) + "," + String(myservo6.read()) + "," + String(myservo7.read()) + "," + String(myservo8.read()) + "," + String(t) + "," + String(speed_exec) + "," + String(code_erreur) + "]");
  Serial.println("[" + String(myservo1.read()) + "," + String(myservo2.read()) + "," + String(myservo3.read()) + "," + String(myservo4.read()) + "," + String(myservo5.read()) + "," + String(myservo6.read()) + "," + String(myservo7.read()) + "," + String(myservo8.read()) + "," + String(t) + "," + String(speed_exec) + "," + String(code_erreur) + "]");
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

void attachbetter(Servo servo, int pin)
{
  if (servo.attach(pin, 0, 180) == 0)
  {                                                      // ,0,180 sert à rien mais renforce la sécurité
    Serial.print("PROBLEME AVEC LE MOTEUR SUR LE PIN "); // renvoie 0 si le pin n'est pas valide (et connecté)
    Serial.println(pin);
    code_erreur = 20 + pin;
  }
}

void writebetter(Servo servo, int angle)
{
  int diff_angle = servo.read() - angle;
  if (diff_angle < -(15 - speed_exec) || diff_angle > 15 - speed_exec) // impossible avec les fonctions actuelles sans problème de moteurs, le max est 2.6 et la borne est 5 à vitesse max
  {
    Serial.println("ATTENTION! ANGLE DEMANDE IMPORTANT, LE MOTEUR PEUT ETRE DECALE");
    code_erreur = 1;
  }
  servo.write(angle);
}

void positionservos(int t)
{
  writebetter(myservo1, f1(t));
  writebetter(myservo2, toN(getPhi(myservo1, f2(t))));
  writebetter(myservo3, f1(t+64%255));
  writebetter(myservo4, 180 - toN(getPhi(myservo3, f2(t + 64 % 255))));
  writebetter(myservo5, 180 - f1(t+128%255));
  writebetter(myservo6, 180 - toN(getPhi(myservo5, f2(t + 128 % 255))));
  writebetter(myservo7, 180 - f1(t+192%255));
  writebetter(myservo8, toN(getPhi(myservo7, f2(t + 192 % 255))));
}

float f1(float x)
{
  if (x > 250)
  {
    return 30;
  }
  else if (x > 205)
  {
    return 807.5 - 3.11 * x;
  }
  else if (x > 200)
  {
    return 170;
  }
  else
  {
    return 30 + x * 0.7;
  }
}

float f2(float t)
{
  if (t > 200)
  {
    return 0;
  }
  else
  {
    return -1; // gros décalage mais tant pis
  }
}

float getPhi(Servo servo, float i)
// i position de l'arbre par rapport au bras. ex: -1 indique 1 centimètre d'écart, 2 indique que le robot est enfoncé de 2 centimètres dans l'arbre, utile pour enlever les clous de l'arbre
{
  return acos(((i - 8.5 * cos(toTheta(servo.read()))) / 16));
}

float toPhi(float a)
{
  return -map(a, 1.5, -3.14, 3.14, -1.5);
}

float toTheta(float n)
{
  return -map(n, 0, 180, -2.35, 2.35);
}

float toN(float a)
{
  return map(a, -2.35, 2.35, 0, 180);
}

// float ftout(t){
//   return map(t,0,255,1,180);
// }
