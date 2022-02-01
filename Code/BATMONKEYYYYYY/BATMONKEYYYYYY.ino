/*
   MotorKnob

   A stepper motor follows the turns of a potentiometer
   (or other sensor) on analog input 0.

   http://www.arduino.cc/en/Reference/Stepper
   This example code is in the public domain.
*/

#include <Stepper.h>

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

// change this to the number of steps on your motor
#define STEPS 32

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int previous = 0;

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(60);
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
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

  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
  Serial.println(val);
}
