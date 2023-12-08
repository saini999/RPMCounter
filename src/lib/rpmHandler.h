#ifndef RPM_HANDLER_H

#define RPM_HANDLER_H
#include "include/pinDef.h"
#include "include/BlockNot.h"

BlockNot timA(2, SECONDS);
BlockNot timB(2, SECONDS);

float rpmA, rpmB;

int64_t t1A,t1B, diffA, diffB;


void INT_A(){
    noInterrupts();
    diffA = millis() - t1A;
    t1A = millis();
    timA.reset();
    interrupts();
}

void INT_B(){
    noInterrupts();
    diffB = millis() - t1B;
    t1B = millis();
    timB.reset();
    interrupts();
}

void initRPMCounter(){
    pinMode(pinSensorA, INPUT);
    pinMode(pinSensorB, INPUT);

    attachInterrupt(digitalPinToInterrupt(pinSensorA), INT_A, RISING);
    attachInterrupt(digitalPinToInterrupt(pinSensorB), INT_B, RISING);
}

float getRPM(int64_t diff){
        return (60000.0 / diff);
}

void convertRPM(){
    if(timA.triggered(false)){
        rpmA = 0;
    } else {
        rpmA = getRPM(diffA);
    }
    if(timB.triggered(false)){
        rpmB = 0;
    } else {
        rpmB = getRPM(diffB);
    }
}


#endif