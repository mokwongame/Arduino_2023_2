#pragma once

#define DEF_DC_MOTOR_PORT1	(2)
#define DEF_DC_MOTOR_PORT2	(3)

class DcMotor
{
public:
	DcMotor(void) { setPort(DEF_DC_MOTOR_PORT1, DEF_DC_MOTOR_PORT2); }
	~DcMotor() {}

	void setPort(int nPort1, int nPort2)
	{
		m_nPort1 = nPort1;
		m_nPort2 = nPort2;
	}

private:
	int m_nPort1, m_nPort2;
};