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
        uint16_t _steps;

    public:
        Motor(uint8_t directionPin, uint8_t stepPin);
        void init (uint16_t steps);
        void start(uint32_t delayTime, uint8_t rotations);

        String getDirection();
        void setDirection(bool direction);

};

#endif