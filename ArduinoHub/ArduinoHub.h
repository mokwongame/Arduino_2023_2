#pragma once

#include "StringTok.h"
#include "Voltmeter.h"
#include "LightSensor.h"
#include "MyServo.h"
#include "DcMotor.h"
#include "RgbLed.h"
#include "Buzzer.h"

class ArduinoHub
{
public:
	ArduinoHub(void) {}
	~ArduinoHub() {}

	void setup(void) // actuator �ʱ�ȭ
	{
		m_myServo.setup();
		m_dcMotor.setup();
		m_rgbLed.setup();
		m_buzzer.setup();
	}

	void start(void)
	{
		while (1) // 무한 반복
		{

		}
	}

private:
	StringTok m_stInput;
	Voltmeter m_voltmeter;
	LightSensor m_lightSensor;
	MyServo m_myServo;
	DcMotor m_dcMotor;
	RgbLed m_rgbLed;
	Buzzer m_buzzer;
};