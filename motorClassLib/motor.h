#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor{
public:
    Motor(byte pin1,byte pin2);//构造函数:构造电机对象,附带两个参数设置控制引脚
    ~Motor();                  //析构函数无内容
    void speed(int en);        //配置速度用的函数,_en的范围为8位（为了对接analogWrite函数）,即0-255
    void run();                //无参数的电机运行函数。本函数需要配合speed函数使用:需要先使用speed配置速度,然后调用本函数运行
    void run(int en);          //运行的重载函数。无需调用speed配置速度、直接赋值参数即可转动电机
    void reverse();            //反转函数:可使电机反向旋转

private:
    byte pin_1,pin_2;
    int _en;
};

#endif