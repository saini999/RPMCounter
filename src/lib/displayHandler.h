#include "include/index.h"

SevSeg d1;

BlockNot tim1(1, SECONDS);

bool systemMode; // 0-> Normal Mode 1->Parameter/Diagnostics Mode.

uint8_t menu, counter;
//int32_t enc;

extern float rpmA, rpmB;

void initDisplay() {

    #define NUM_DIGIT 8
    #define DTYPE COMMON_ANODE
    #define DIG1 PIN_PA4
    #define DIG2 PIN_PA5
    #define DIG3 PIN_PA6
    #define DIG4 PIN_PC7
    #define DIG5 PIN_PD6
    #define DIG6 PIN_PD7
    #define DIG7 PIN_PC0
    #define DIG8 PIN_PC1
    #define SEGA PIN_PD5
    #define SEGB PIN_PA7
    #define SEGC PIN_PC5
    #define SEGD PIN_PC3
    #define SEGE PIN_PC2
    #define SEGF PIN_PD4
    #define SEGG PIN_PC6
    #define SEGDP PIN_PC4

    d1.Begin(DTYPE, NUM_DIGIT, DIG1, DIG2, DIG3, DIG4, DIG5, DIG6, DIG7, DIG8, SEGA, SEGB, SEGC, SEGD, SEGE, SEGF, SEGG, SEGDP, false);
}

void menu0() {
    if(tim1.triggered(true)){
        counter++;
    }
    switch (counter)
    {
    case 0:
        d1.display(F("noorAuto"));
        break;
    case 1:
        d1.display(F("GILLAGro"));
        break;
    case 2:
        d1.display(F("GILL   2"));
        break;
    case 3:
        d1.display(F("GILL   1"));
        break;
    case 4:
        d1.display(F("GILL   0"));
        break;
    default:
        menu = 1;
        counter = 0;
        break;
    }
}

void menu1() {
    String rpm;
    char buffer[5];
    sprintf(buffer, "%4d", (int)rpmA);
    rpm = buffer;
    sprintf(buffer, "%4d", (int)rpmB);
    rpm += buffer;
    d1.display(rpm);
}

void displayTask() {
    if(menu == 0){
        menu0();
    }
    if(menu == 1){
        menu1();
    }
    
}