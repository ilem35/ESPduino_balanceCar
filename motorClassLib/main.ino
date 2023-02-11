#define leftMotorPin1  0
#define leftMotorPin2  4
#define rightMotorPin1 2
#define rightMotorPin2 15

#include "motor.h"
Motor motor1(leftMotorPin1,leftMotorPin2);
Motor motor2(rightMotorPin1,rightMotorPin1);

void setup() {
}

void loop() {
  motor1.run(255);
  motor2.run(255);
}

