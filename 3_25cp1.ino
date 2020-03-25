#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment object
int Hour=0,Min=0;
void setup() {
byte numDigits = 4;
byte digitPins[] = {1, 4, 5, 13};
byte segmentPins[] = {2,14,11,9,8,3,12,10};
sevseg.begin(COMMON_CATHODE,numDigits,digitPins,segmentPins);
sevseg.setBrightness(90);
}

void loop() {
static unsigned long timer = millis();
if(millis()>=timer){
  timer+=300;
  Min = Min + 1;
  if (Min == 60 )
  {
    Min = 0;
    if (Hour == 23)
      Hour=0;
    else
      Hour++;
  };
  sevseg.setNumber(Hour*100 + Min, 0);
  }
sevseg.refreshDisplay();
}
