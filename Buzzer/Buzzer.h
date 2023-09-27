#pragma once

#define DEF_BUZZER_PORT	(8)

class Buzzer
{
public:
	Buzzer(void) { setPort(DEF_BUZZER_PORT); }
	~Buzzer() {}

	void setPort(int nPort) { m_nPort = nPort; }
	void setup(void) { initBuzzer(); }

private:
	int m_nPort;

	void initBuzzer(void)
	{
		pinMode(m_nPort, OUTPUT);
	}
};