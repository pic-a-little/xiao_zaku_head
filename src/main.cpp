#include "Arduino.h"
#include "SoftwareSerial.h"
#include "myDFRobotDFPlayerMini.h"
#include "myServo.h"
#include "myIO.h"
#include "myLED.h"

#define intervalMillis (60 * 1000)

unsigned long nextTiming;

void monoEyeAction();

void setup()
{
  Serial.begin(115200);
  delay(500);
  setupServo();
#ifdef playerEnabled
  setupDFPlayer();
#endif
  setupLED();

  nextTiming = millis();
}

void loop()
{
  if (millis() >= nextTiming)
  {
    nextTiming = nextTiming + intervalMillis;
    monoEyeAction();
    delay(3000);
    monoEyeAction();
    delay(3000);
    monoEyeAction();
  }
}

void monoEyeAction(){
#ifdef playerEnabled
  myDFPlayer.play(1); // Play the first mp3
#endif
  turnONmonoEye();
  monoEyeMove();
  turnOFFmonoEye();
}
