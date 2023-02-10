#ifndef GET_ANGLE_H
#define GET_ANGLE_H

#include <Adafruit_MPU6050.h>

#ifdef __cplusplus
extern "C"{
#endif

float getAngle(float axy,float az);

#ifdef __cplusplus  
}
#endif

#endif