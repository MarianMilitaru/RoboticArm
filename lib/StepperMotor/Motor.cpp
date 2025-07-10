#include <Arduino.h>
#include "Motor.h"

/*!
*   @brief Defines the motor object
*   @param directionPin Physical pin used for setting the direction of rotation (USE PORTD!)
*   @param stepPin Physical pin used for making each step of the motor (USE PORTD!)
*/
Motor::Motor(uint8_t directionPin, uint8_t stepPin) {
    _dirPin = directionPin;
    _stepPin = stepPin;
    DDRB |= (1 << 0);   //Sets the enable pin as OUTPUT
    PORTB &= ~(1 << 0); //Sets the enable pin as LOW
}

/*!
*   @brief Initializes the motor
*   @param steps Number of steps for a full rotation
*/
void Motor::init(uint16_t steps) {
    DDRD |= (1 << _stepPin); // Output
    DDRD |= (1 << _dirPin); // Output
    PORTD &= ~(1 << _stepPin); // Low
    PORTD &= ~(1 << _dirPin); // Low
    _steps = steps;
}

/*!
*   @brief Starts the motor
*   @param delayTime Time between each step in us
*   @param rotations Number of rotations
*/
void Motor::start(uint32_t delayTime, uint8_t rotations) {
    if(delayTime < 500)
        delayTime = 500;

    PORTD = (_dir << _dirPin); // Rotation direction
    for (uint16_t i = 0; i < _steps * rotations; i++) {
    PORTD |= (1 << _stepPin); // High
    delayMicroseconds(delayTime);
    PORTD &= ~(1 << _stepPin); // Low
    delayMicroseconds(delayTime);
  }
}

String Motor::getDirection() {
    if(_dir)
        return "CLOCKWISE";
    return "COUNTERCLOCKWISE";
}

void Motor::setDirection(bool direction) {
    _dir = direction;
}