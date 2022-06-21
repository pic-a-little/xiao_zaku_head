#include "myLED.h"


int nextMonoEyePower = 0;
int currentMonoEyeBrightness = 0; // 255＝最大輝度、0＝最小輝度

void setupLED(){
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
}

void turnONmonoEye(){
    //一度最大輝度まで光らせてから、少し輝度を落とす。
    nextMonoEyePower = 255;
    for (currentMonoEyeBrightness = 0; currentMonoEyeBrightness <= nextMonoEyePower; currentMonoEyeBrightness += 1)
    {
        analogWrite(ledPin, currentMonoEyeBrightness);
        delay(2);
    }
    delay(1000);
    nextMonoEyePower = normalMonoEyeBrightness;
    for (currentMonoEyeBrightness = 255; currentMonoEyeBrightness >= nextMonoEyePower; currentMonoEyeBrightness -= 1)
    {
        analogWrite(ledPin, currentMonoEyeBrightness);
        delay(2);
    }
}

void turnOFFmonoEye(){
    // LEDを最小輝度まで落とす
    nextMonoEyePower = 0;
    for (currentMonoEyeBrightness = normalMonoEyeBrightness; currentMonoEyeBrightness >= nextMonoEyePower; currentMonoEyeBrightness -= 1)
    {
        analogWrite(ledPin, currentMonoEyeBrightness);
        delay(4);
    }
    delay(50);
 }