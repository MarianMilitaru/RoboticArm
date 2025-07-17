#include <Arduino.h>
#include <Motor.h>

/*
      1.8 degrees/step
*/

#define stepPinX 2
#define dirPinX 5
#define stepPinY 3
#define dirPinY 6
#define stepPinZ 4
#define dirPinZ 8
#define stepPinA 12
#define dirPinA 13

Motor motorX(dirPinX, stepPinX);

void setup() {
  motorX.init(200);
}

void loop() {
  motorX.setDirection(COUNTERCLOCKWISE);
  motorX.start(850, 6);
  delay(200);

  motorX.setDirection(CLOCKWISE);
  motorX.start(800, 6);
  delay(200);
}