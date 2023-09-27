#pragma once

#define DEF_PORT_R	(5)
#define DEF_PORT_G	(6)
#define DEF_PORT_B	(7)

class RgbLed
{
public:
	RgbLed(void) { setPort(DEF_PORT_R, DEF_PORT_G, DEF_PORT_B); } // 생성자
	~RgbLed() {}	// 소멸자, 파괴자

	void setPort(int nPortR, int nPortG, int nPortB)
	{
		m_nPortR = nPortR, m_nPortG = nPortG, m_nPortB = nPortB;
	}
	void setup(void) { initLed(); }
	void turnRed(bool bOn)
	{
		if (bOn) digitalWrite(m_nPortR, HIGH);
		else digitalWrite(m_nPortR, LOW);
	}
	void turnGreen(bool bOn)
	{
		if (bOn) digitalWrite(m_nPortG, HIGH);
		else digitalWrite(m_nPortG, LOW);
	}
	void turnBlue(bool bOn)
	{
		if (bOn) digitalWrite(m_nPortB, HIGH);
		else digitalWrite(m_nPortB, LOW);
	}

private:
	int m_nPortR, m_nPortG, m_nPortB; // RGB 포트

	void initLed(void)
	{
		pinMode(m_nPortR, OUTPUT);
		pinMode(m_nPortG, OUTPUT);
		pinMode(m_nPortB, OUTPUT);
	}
};