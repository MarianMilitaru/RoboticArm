#include <Arduino.h>
#include <Motor.h>

/*
      1.8 degrees/step
*/

#define stepPin 2
#define dirPin 5

Motor motor1(dirPin, stepPin);

void setup() {
  motor1.init(200);
}

void loop() {
  motor1.setDirection(CLOCKWISE);
  motor1.start(800, 7);
  delay(200);

  motor1.setDirection(COUNTERCLOCKWISE);
  motor1.start(400, 15);
  delay(200);
}
// void moveMotor (bool direction, uint16_t delayBetweenSteps, uint8_t times) {
//   PORTD = (direction << dirPin);
  
//   for (uint16_t i = 0; i < 200 * times; i++) {
//     PORTD |= (1 << stepPin); // High
//     delayMicroseconds(delayBetweenSteps);
//     PORTD &= ~(1 << stepPin); // Low
//     delayMicroseconds(delayBetweenSteps);
//   }
// }