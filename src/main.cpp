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
Motor motorY(dirPinY, stepPinY);

void setup() {
  motorX.init(200);
  motorY.init(200);
}

void loop() {
  motorX.setParams(COUNTERCLOCKWISE, 800, 6);
  motorX.start();
  motorY.setParams(COUNTERCLOCKWISE, 800, 6);
  motorY.start();
  delay(200);

  motorX.setParams(CLOCKWISE, 800, 6);
  motorX.start();
  motorY.setParams(CLOCKWISE, 800, 6);
  motorY.start();
  delay(200);
}