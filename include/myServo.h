#pragma once

#include <Arduino.h>
#include <Servo.h>

#define centerPosition ((544 + 2400) / 2 - 50)
#define maxRightPosition (centerPosition - 700)
#define maxLeftPosition (centerPosition + 700)


// writeMicroseconds()     default min is 544, max is 2400

extern Servo myServo;
// extern int pos;
// extern int newAngle;

extern void setupServo();
extern void monoEyeMove();

void move();
void moveLeft();
void moveRight();