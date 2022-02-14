#include <Servo.h>

Servo myservo; // create servo object to control a servo
Servo myservo2;
Servo myservo3; // create servo object to control a servo
Servo myservo4;
Servo myservo5; // create servo object to control a servo
Servo myservo6;
Servo myservo7; // create servo object to control a servo
Servo myservo8;
bool monte = true; // false //  BLEUTOOTH
float speed = 5;
float t; // i est l'étape actuel, pour savoir de combien changer !

void setup()
{
    myservo.attach(8);
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
        Serial.println(t);
    }
    Serial.println("En pause")
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
