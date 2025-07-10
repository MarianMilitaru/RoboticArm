#include <Arduino.h>

#define stepPin 2
#define dirPin 5
#define enPin 0

/*
      1.8 degrees/step
*/

void moveMotor (bool, uint16_t, uint8_t);

void setup() {
  DDRD |= (1 << stepPin); // Output
  DDRD |= (1 << dirPin); // Output
  DDRB |= (1 << enPin); // Output

  PORTD &= ~(1 << stepPin); // Low
  PORTD &= ~(1 << dirPin); // Low
  PORTB &= ~(1 << enPin); // Low
}
void loop() {
  moveMotor(1, 500, 50);
  delay(200);

  moveMotor(0, 500, 50);
  delay(200);
}

void moveMotor (bool direction, uint16_t delayBetweenSteps, uint8_t times) {
  PORTD = (direction << dirPin);
  
  for (uint16_t i = 0; i < 200 * times; i++) {
    PORTD |= (1 << stepPin); // High
    delayMicroseconds(delayBetweenSteps);
    PORTD &= ~(1 << stepPin); // Low
    delayMicroseconds(delayBetweenSteps);
  }
}