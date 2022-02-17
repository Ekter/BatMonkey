#include <Servo.h>

Servo myservo;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
Servo myservo7;
Servo myservo8;
bool monte = true;
float speed = 5;
float t = 0;
int total_t = 0;
int t2 = 0;

void setup()
{
    Serial.begin(9600);
    attachbetter(myservo, 8);
    attachbetter(myservo2, 9);
    attachbetter(myservo3, 3);
    attachbetter(myservo4, 3);
    attachbetter(myservo5, 10);
    attachbetter(myservo6, 11);
    attachbetter(myservo7, 14);
    attachbetter(myservo8, 13);
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
        myservo.write(f1(t));
        myservo2.write(f2(t));
        myservo3.write(f1(t + 64));
        myservo4.write(f2(t + 64));
        myservo5.write(f1(t + 128));
        myservo6.write(f2(t + 128));
        myservo7.write(f1(t + 192));
        myservo8.write(f2(t + 192));
        Serial.print("ETAPE:");
        Serial.println(t);
    }
    else
    {
        if (total_t > 100 + t2)                             // pour n'afficher qu'une fois toutes les 100 ms
        {
            Serial.println("En pause");
            t2=total_t
        }
    }
    delay(15 - speed);                                      // vitesse max=10 -> boucle en 1280 ms
    total_t += 15 - speed;                                  // vitesse min=0  -> boucle en 3840 ms   ~ 3 fois plus lent
    
}

void attachbetter(Servo servo, int pin)
{
    if (servo.attach(pin, 0, 180) == 0)
    {                                                        // ,0,180 sert à rien mais renforce la sécurité
        Serial.print("PROBLEME AVEC LE MOTEUR SUR LE PIN "); // renvoie 0 si le pin est valide (et connecté)
        Serial.println(pin);
    }
}

void writebetter(Servo servo, int angle)
{
    int diff_angle = servo.read() - angle;
    if (diff_angle < -(15-speed) || diff_angle > 15-speed)  // impossible avec les fonctions actuelles sans problème de moteurs, le max est 2.6 et la borne est 5 à vitesse max
    {
        Serial.println("ATTENTION! ANGLE DEMANDE IMPORTANT, LE MOTEUR PEUT ETRE DECALE");
    }
    servo.write(angle);
}

float uh(float x)
{
    if (x < 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

float f1(float x)
{
    return descendre1(x) + monter1(x - 200) + descendre1(x - 255);
}

float f2(float x)
{
    return descendre2(x) + monter2(x - 200) + descendre2(x - 255);
}

float descendre1(float x)
{
    return (110 - x * 5 / 14) * uh(-(x - 199.75)) * uh(x + 0.25);
}

float monter1(float x)
{
    return monter1a(x) + monter1b(x - 5) + monter1c(x - 50);
}

float descendre2(float x)
{
    return (150 - x * 0.6) * uh(-(x - 199.75)) * uh(x + 0.25);
}

float monter2(float x)
{
    return monter2a(x) + monter2b(x - 5);
}

float monter1a(float x)
{
    return (38.75) * uh(-(x - 4.75)) * uh(x + 0.25);
}

float monter1b(float x)
{
    return (1.58 * x + 38.75) * uh(-(x - 44.75)) * uh(x + 0.25);
}

float monter1c(float x)
{
    return (110) * uh(-(x - 4.75)) * uh(x + 0.25);
}

float monter2a(float x)
{
    return (-2.12 * x + 30.6) * uh(-(x - 4.75)) * uh(x + 0.25);
}

float monter2b(float x)
{
    return (2.6 * x + 20) * uh(-(x - 49.75)) * uh(x + 0.25);
}
