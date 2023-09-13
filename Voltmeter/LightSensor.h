#pragma once

#include "Voltmeter.h"

#define DEF_LIGHT_PORT	(A1) // default값 정의

class LightSensor : public Voltmeter // Voltmeter 클래스를 public으로 상속받아(:) LightSensor 클래스 구현
{
public:
	LightSensor(void) { setPort(DEF_LIGHT_PORT); } // setPort()는 LightSensor에 정의되지 않음; setPort()는 부모 클래스인 Voltmeter에 정의
	~LightSensor() {}

	int getLightStep(void) const { return getVoltStep(); }

private:
};
