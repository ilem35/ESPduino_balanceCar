#include "getAngle.h"

float getAngle(float axy,float az){
    return atan2(axy,az)*(180/PI);
}

