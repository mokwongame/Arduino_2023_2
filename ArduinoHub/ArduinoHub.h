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
		//Serial.println("input = [" + m_stInput.toString() + "]");
		String sToken = m_stInput.cutToken().toString();
		//Serial.println("token #1 = [" + sToken + "]");
		if (sToken == "get") exeGet();
		else m_stInput.cutLine(); // 잘못된 명령 -> 현재 줄을 삭제
	}

	void exeGet(void) // get 명령어 실행
	{
		// 1. 전압 읽기: get(#1) volt(#2)
		// 2-1. 조도 상태 읽기 : get(#1) light(#2)
		// 2-2. 조도 스텝 읽기 : get(#1) lightstep(#2)
		String sToken = m_stInput.cutToken().toString();
		//Serial.println("token #2 = [" + sToken + "]");
		if (sToken == "volt") exeVolt();
		else if (sToken == "light") exeLight();
		else if (sToken == "lightstep") exeLightStep();
		else m_stInput.cutLine();
	}

	void exeVolt(void)
	{
		double volt = m_voltmeter.getVolt();
		Serial.println(String(volt, 10)); // Serial에 출력
	}

	void exeLight(void)
	{
		int nLightState = m_lightSensor.getLightState();
		String sLightState = m_lightSensor.lightStateToStr(nLightState);
		Serial.println(sLightState);
	}

	void exeLightStep(void)
	{
		int nLightState = m_lightSensor.getLightStep();
		Serial.println(nLightState);
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