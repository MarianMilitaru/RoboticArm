#include <Arduino.h>

#define stepPin 2
#define dirPin 5
#define enPin 0

void setup() {
  DDRD |= (1 << stepPin); // Output
  DDRD |= (1 << dirPin); // Output
  DDRB |= (1 << enPin); // Output

  PORTD &= ~(1 << stepPin); // Low
  PORTD &= ~(1 << dirPin); // Low
  PORTB &= ~(1 << enPin); // Low
}
void loop() {
  PORTD |= (1 << dirPin); // High
  for (int i = 0; i < 800; i++) {
    PORTD |= (1 << stepPin); // High
    delayMicroseconds(700);
    PORTD &= ~(1 << stepPin); // Low
    delayMicroseconds(700);
  }
  delay(1000);

  PORTD &= ~(1 << dirPin); // Low
  for (int i = 0; i < 1600; i++) {
    PIND |= (1 << stepPin); // High
    delayMicroseconds(300);
    PIND &= ~(1 << stepPin); // Low
    delayMicroseconds(300);
  }
  delay(1000);
}