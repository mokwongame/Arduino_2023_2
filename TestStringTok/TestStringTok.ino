#include "StringTok.h"

StringTok stInput;  // StringTok 클래스의 인스턴스로 stInput 선언

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial로부터 문장 읽기
  stInput.appendSerial(); // append(추가하기)
  // 사용자 입력: stInput은 문장을 저장
  // 사용자 미입력: stInput은 empty
  if (!stInput.isEmpty())  // stInput이 empty인지 확인 -> NOT 연산(!)
  {                        // 사용자 입력 있음: stInput is not(!) empty
                           // StringTok을 String으로 바꾸어서 Serial에 출력
    Serial.println("input = [" + stInput.toString() + "]");
    delay(2000); // 2000ms 지연
  }
}
