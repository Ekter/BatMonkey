/*
   MotorKnob

   A stepper motor follows the turns of a potentiometer
   (or other sensor) on analog input 0.

   http://www.arduino.cc/en/Reference/Stepper
   This example code is in the public domain.
*/


#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;  // create servo object to control a servo
Servo myservo4;

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to

// the previous reading from the analog input
int previous = 0;

void setup() {
  // set the speed of the motor to 30 RPMs
  myservo1.attach(3);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(6);
  myservo3.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo4.attach(10);
  Serial.begin(9600);

}

void loop() {
  // get the sensor value
  int val = analogRead(0);

  // move a number of steps equal to the change in the
  // sensor reading
  //stepper.step(100);

  // remember the previous value of the sensor
  previous = val;

  val = val / 5;   // scale it to use it with the servo (value between 0 and 180)
  myservo3.write(val + 20);                // sets the servo position according to the scaled value
  myservo4.write(180 - val * 1.5);
  myservo1.write(val + 64);                // sets the servo position according to the scaled value
  myservo2.write(180 - val * 1.4);
  delay(15);                           // waits for the servo to get there
  Serial.println(val);
}
