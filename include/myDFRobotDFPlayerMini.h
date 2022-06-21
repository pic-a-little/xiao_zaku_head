#pragma once

#include <Arduino.h>
#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"
#include "myIO.h"

extern DFRobotDFPlayerMini myDFPlayer;

extern void setupDFPlayer();
extern void printDetail(uint8_t type, int value);