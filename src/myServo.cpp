#include "myservo.h"
#include "myIO.h"
#include <stdlib.h>


Servo myServo;

int currentPosition = centerPosition;
int newPosition = centerPosition;
int delaySpeed = 1;
int stepSpeed = 2;
int intervalMillis = 1000;


void setupServo()
{
    myServo.attach(servoPin);
    myServo.writeMicroseconds(centerPosition);
    delay(100);
    Serial.println("Done setupServo");
    srand((unsigned int)millis());
}

void monoEyeMove(){
    //モノアイを3回動かす。スピード、向きはランダム
    delaySpeed = 1 + rand() % (5);
    stepSpeed = 2 + rand() % (2);
    intervalMillis = 100 + rand() % (900);

    newPosition = maxRightPosition + rand() % (maxLeftPosition - maxRightPosition + 1);
    move();
    delay(intervalMillis);

    newPosition = maxRightPosition + rand() % (maxLeftPosition - maxRightPosition + 1);
    move();
    delay(intervalMillis);

    newPosition = maxRightPosition + rand() % (maxLeftPosition - maxRightPosition + 1);
    move();
    delay(intervalMillis);

    // for (currentPosition = centerPosition; currentPosition <= maxLeftPosition; currentPosition += 2)
    // { 
    //     myServo.writeMicroseconds(currentPosition); 
    //     delay(1); 
    // }
    // for (currentPosition = maxLeftPosition; currentPosition >= maxRightPosition; currentPosition -= 2)
    // {
    //     myServo.writeMicroseconds(currentPosition);
    //     delay(1);
    // }

    // for (currentPosition = maxRightPosition; currentPosition <= centerPosition; currentPosition += 2)
    // { // goes from 0 degrees to 180 degrees
    //     // in steps of 1 degree
    //     myServo.writeMicroseconds(currentPosition); // tell servo to go to position in variable 'pos'
    //     delay(1);                       // waits 15ms for the servo to reach the position
    // }
}

void move(){
    if (currentPosition <= newPosition){
        moveLeft();
    }else{
        moveRight();
    }
}

void moveLeft()
{
    int pos = 0;
    for (pos = currentPosition; pos <= newPosition; pos += stepSpeed)
    {
        myServo.writeMicroseconds(pos);
        delay(delaySpeed);
    }
    currentPosition = newPosition;
}

void moveRight(){
    int pos = 0;
    for (pos = currentPosition; pos >= newPosition; pos -= stepSpeed)
    {
        myServo.writeMicroseconds(pos);
        delay(delaySpeed);
    }
    currentPosition = newPosition;
}