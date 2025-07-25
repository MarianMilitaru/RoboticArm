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
*   @brief Chooses the right port for initialization
*/
void Motor::pickPort(uint8_t pin) {
    if ((pin >= 0) && (pin < 8)) {
        DDRD |= (1 << pin);     //OUTPUT
        PORTD &= ~(1 << pin);   //LOW
    } else if ((pin >= 8) && (pin <= 13)) {
        DDRB |= (1 << (pin - 8));
        PORTB &= ~(1 << (pin - 8));
    } else if (pin <= 19) {
        DDRC |= (1 << (pin - 14));
        PORTC &= ~(1 << (pin - 14));
    }
}

/*!
*   @brief Initializes the motor
*   @param steps Number of steps for a full rotation
*/
void Motor::init(uint16_t steps) {
    pickPort(_stepPin);
    pickPort(_dirPin);
    _steps = steps;
}

/*!
*   @brief Gets the current direction of rotation
*   @returns Direction of the motor
*/
bool Motor::getDirection() {
    return _dir;
}

/*!
*   @brief Gets the direction pin
*   @returns Direction pin of the motor
*/
uint8_t Motor::getDirectionPin() {
    return _dirPin;
}

/*!
*   @brief Gets the current step pin
*   @returns Step pin of the motor
*/
uint8_t Motor::getStepPin() {
    return _stepPin;
}

/*!
*   @brief Gets the current delay between each step
*   @returns Delay value
*/
uint16_t Motor::getDelayTime() {
    return _delayTime;
}

/*!
*   @brief Gets the number of steps for a full rotation
*   @returns Numebr of steps
*/
uint16_t Motor::getSteps() {
    return _steps;
}

/*!
*   @brief Gets the number of rotations given to the motor
*   @returns Number of rotations
*/
uint8_t Motor::getRotations() {
    return _rotations;
}

/*!
*   @brief Sets the current direction of rotation
*   @param direction Clockwise or counterclockwise
*   @param delayTime Time between each step in us
*   @param rotations Number of rotations
*/
void Motor::setParams(bool direction, uint16_t delayTime, uint8_t rotations) {
    _dir = direction;
    if(_delayTime < 800) {_delayTime = 800;}
    else _delayTime = delayTime;
    _rotations = rotations;
}

/*
    TODO: 
    - Add the rest of the implementation for the start() function
    - Modify the main() to utilise these functions
*/

void start(Motor motor) {
    PORTD = (motor.getDirection() << motor.getDirectionPin()); // Rotation direction
    for (uint16_t i = 0; i < motor.getSteps() * motor.getRotations(); i++) {
        PORTD |= (1 << motor.getStepPin()); // High
        delayMicroseconds(motor.getDelayTime());
        PORTD &= ~(1 << motor.getStepPin()); // Low
    }
}

void start(Motor motor1, Motor motor2) {
    PORTD = (motor1.getDirection() << motor1.getDirectionPin()); // Rotation direction
    PORTD = (motor2.getDirection() << motor2.getDirectionPin());
}

void start(Motor motor1, Motor motor2, Motor motor3) {

}

void start(Motor motor1, Motor motor2, Motor motor3, Motor motor4) {
    
}
