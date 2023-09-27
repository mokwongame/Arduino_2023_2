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

private:
	int m_nPortR, m_nPortG, m_nPortB; // RGB 포트
};