#include "motor.h"

Motor::Motor(byte pin1,byte pin2){
    pin_1=pin1;
    pin_2=pin2;
}

Motor::~Motor(){

}

void Motor::set_speed(int en){
    _en=constrain(en,-255,255);
}

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