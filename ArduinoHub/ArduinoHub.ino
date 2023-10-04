#include "ArduinoHub.h"
#define SERIAL_RATE (9600)

ArduinoHub arduinoHub;

void setup() {
  // put your setup code here, to run once:
  arduinoHub.setup();
  Serial.begin(SERIAL_RATE);
}

void loop() {
  // put your main code here, to run repeatedly:
  arduinoHub.start();
}