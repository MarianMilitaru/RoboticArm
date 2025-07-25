/*
    Library for defining a motor and helping with the overall comunication with it
    using the Arduino Uno Stepper Motor Shield V3
*/

#ifndef MOTOR_H
#define MOTOR_H

#define CLOCKWISE 1
#define COUNTERCLOCKWISE 0

class Motor {
    private:
        uint8_t _dirPin;
        uint8_t _stepPin;
        bool _dir;
        uint16_t _delayTime;
        uint8_t _rotations;
        uint16_t _steps;

        void pickPort(uint8_t pin);

    public:
        Motor(uint8_t directionPin, uint8_t stepPin);
        void init (uint16_t steps);

        bool getDirection();
        uint8_t getDirectionPin();
        uint8_t getStepPin();
        uint16_t getDelayTime();
        uint16_t getSteps();
        uint8_t getRotations();
        void setParams(bool direction, uint16_t delayTime, uint8_t rotations);

};

void start(Motor motor);
void start(Motor motor1, Motor motor2);
void start(Motor motor1, Motor motor2, Motor motor3);
void start(Motor motor1, Motor motor2, Motor motor3, Motor motor4);

#endif