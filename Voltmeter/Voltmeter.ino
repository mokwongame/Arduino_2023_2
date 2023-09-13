#include "Voltmeter.h"  // 현재 폴더에서 헤더 파일 검색

Voltmeter voltmeter;  // Voltmeter란 클래스를 voltmeter란 인스턴스로 생성

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nVolt = voltmeter.getVoltStep();
  Serial.println("step = " + String(nVolt));
  double volt = voltmeter.getVolt();
  Serial.println("volt = " + String(volt));
  delay(1000);
}
