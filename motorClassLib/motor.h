#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor{
public:
    Motor(byte pin1,byte pin2);
    ~Motor();
    void set_speed(int en);
    void run();

private:
    byte pin_1,pin_2;
    int _en;
};

#endif