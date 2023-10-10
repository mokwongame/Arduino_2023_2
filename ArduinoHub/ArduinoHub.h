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
		else if (sToken == "set") exeSet();
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
		LightState nLightState = m_lightSensor.getLightState();
		String sLightState = m_lightSensor.lightStateToStr(nLightState);
		Serial.println(sLightState);
	}

	void exeLightStep(void)
	{
		int nLightState = m_lightSensor.getLightStep();
		Serial.println(nLightState);
	}

	void exeSet(void) // set 명령어 실행
	{
		// 3-1. 서보 모터 구동: set servo #pos (#pos: 각도를 숫자(#)로 입력)
		// 3-2. DC 모터 구동 : set dcmotor #pos(#pos: 각도를 숫자(#)로 입력)
		// 4. 3색 LED 출력 : set led color(color : 색깔 문자열)
		// 5. 부저 출력 : set buzzer note #delay(note: 음정 문자열, #delay : 음 지속 시간을 msec)
		String sToken = m_stInput.cutToken().toString();
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