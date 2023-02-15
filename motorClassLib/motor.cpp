#include "motor.h"

/*
 * 构造函数:将输入的两个引脚参数传递给类内部的引脚变量。方便其他函数调用
 */
Motor::Motor(byte pin1,byte pin2){
    pin_1=pin1;
    pin_2=pin2;
}

Motor::~Motor(){

}

/*
 * run的重载函数,不过依赖speed调速函数和run运行函数(无参):先调用speed配置速度,再调用无参run转动电机
 */
void Motor::run(int en){
    this->speed(en);
    this->run();
}

/*
 * 配置速度用:将传入的参数赋值给类内部的使能参数。方便其他函数调用
 */
void Motor::speed(int en){
    _en=constrain(en,-255,255);//constrain:设置该参数的上界和下界
}

/*
 * 无参run函数:使构造时配置的引脚输出对应的pwm信号, 从而实现控制转速和方向
 */
void Motor::run(){
    if(_en>0){
        analogWrite(pin_1,_en);
        analogWrite(pin_2,0);
    }
    else{
        _en=abs(_en);
        analogWrite(pin_1,0);
        analogWrite(pin_2,_en);
    }
}

/*
 * _en取相反数, 调用无参run函数使电机运行
 */
void Motor::reverse(){
    _en=-_en;
    this->run();
}

/*
 * 停转函数:电机停转函数
 */
void Motor::stop{
    this->run(0);
}

void Motor::run(int min,int max,int en){
    en = map(en,-255,255,min,max);
    this->run(en);
}
    
