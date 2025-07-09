#include <Arduino.h>

#define stepPin 2
#define dirPin 5

void setup() {
  DDRB |= (1 << stepPin); // Output
  DDRB |= (1 << dirPin); // Output
  PORTB &= ~(1 << stepPin); // Low
  PORTB &= ~(1 << dirPin); // Low
}
void loop() {
  PORTB |= (1 << dirPin); // High
  for (int i = 0; i < 800; i++) {
    PORTB |= (1 << stepPin); // High
    delayMicroseconds(700);
    PORTB &= ~(1 << stepPin); // Low
    delayMicroseconds(700);
  }
  delay(1000);

  PORTB &= ~(1 << dirPin); // Low
  for (int i = 0; i < 1600; i++) {
    PINB |= (1 << stepPin); // High
    delayMicroseconds(500);
    PINB &= ~(1 << stepPin); // Low
    delayMicroseconds(500);
  }
  delay(1000);
}