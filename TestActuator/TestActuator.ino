/* [Actuator(구동기) 구현]
1. 모터: servo motor, DC motor
 - 0도 -> 180도 -> 0도
2. 3색 LED
 - 7개 색깔을 1초씩 출력
3. 부저(buzzer)
 - 도레미파솔라시도를 1초씩 생성
4. 모든 actuator를 클래스로 구현되어야 함
*/
#include "DcMotor.h"

DcMotor dcMotor;

void setup() {
  // put your setup code here, to run once:
  dcMotor.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  dcMotor.move(180);
  dcMotor.move(-180);
}
