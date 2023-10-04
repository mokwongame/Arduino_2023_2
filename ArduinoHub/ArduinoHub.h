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
			m_stInput.appendSerial();
			if (m_stInput.hasLine()) // 명령어 정상 입력
				exeCmd(); // 명령어 실행
		}
	}

	void exeCmd(void)
	{
		Serial.println("input = [" + m_stInput.toString() + "]");
		String sToken = m_stInput.cutToken().toString();
		Serial.println("token #1 = [" + sToken + "]");
		if (sToken == "get") exeGet();
		else m_stInput.cutLine(); // 잘못된 명령 -> 현재 줄을 삭제
	}

	void exeGet(void) // get 명령어 실행
	{

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