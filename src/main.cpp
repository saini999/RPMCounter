#include <main.h>

#define refRPM 200

BlockNot refreshRPM(refRPM);


void setup() {
  initDisplay();
  initRPMCounter();
}

void loop() {
  displayTask();
  if(refreshRPM.triggered(true)){
    convertRPM();
  }
}
