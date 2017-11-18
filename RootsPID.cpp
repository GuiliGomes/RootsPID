/* ----------------------------------------------------------------------------

File:	RootsPID.cpp
Author:	Guiilherme Gomes & Lorenzo Giordano
Date:	07/Oct/2016

Description:
  An API to drive a two-wheel differential mobile robot.


Commands:


---------------------------------------------------------------------------- */

#include <RootsPID.h>
//#include <Arduino.h>


RootsPID::RootsPID(float T, float Kp, float Ki, float Kd) {

    this->h1 = T/2;
    this->h2 = 1/T;
    this->b0 = Kp + Ki*h1 + Kd*h2;
    this->b1 = -Kp + Ki*h1 - (2*Kd*h2);
    this->b2 = Kd*h2;
    this->a1 = -1;
    this->a2 = 0;
    
    this->reset();
}


void RootsPID::setLimit(int value) {
    this->limit = value;
}


float RootsPID::getU(float errork) {
    
    ek[2] = ek[1];
    ek[1] = ek[0];
    ek[0] = errork;
    uk[2] = uk[1];
    uk[1] = uk[0];
    uk[0] = ek[0]*b0 + ek[1]*b1 + ek[2]*b2 - uk[1]*a1;
    u = uk[0];
    
    if(u > limit) {
        u = limit;
    }
    else if(u < -limit) {
        u = -limit;
    }
    
    return u;
}

void RootsPID::reset() {
    
    int i;
    
    for(i=0;i<3;i++) {
        ek[i] = 0;
        uk[i] = 0;
        u = 0;
    }    
}
