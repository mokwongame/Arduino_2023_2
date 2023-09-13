#pragma once // �� ��� ������ �� ����(once) include; #pragma(pragmatic, �����ϴ�)

#define DEF_VOLT_PORT	(A0)

// ��� ���� �̸��� Ŭ���� �̸��� �����ϰ� ����(�ǰ�)
// ��ü(object): ������ Ǯ�� ���� �ڷ� ������ ���� �ڵ��� �⺻ ����
class Voltmeter // Ŭ����(��ü�� ���赵) ���� -> ��ü �����
{
public: // �Ʒ� �ڵ�� ��� public member
	// ������(constructor): Ŭ���� �̸��� ������ �̸� ���
	Voltmeter(void) { setPort(DEF_VOLT_PORT); }
	// �ı���(destructor): Ŭ���� �̸��� ������ �̸� ���; �Լ��� �տ� ~�� ���
	~Voltmeter() {}
	// �����ڴ� �ν��Ͻ��� ���� ��(new) ȣ��; �ı��� �Լ��� �ν��Ͻ��� �ı��� ��(delete) ȣ��
	// �ν��Ͻ�(instance): Ŭ������ ������ �����

	// public method(��� �Լ�): class �ܺο��� ȣ���� �� �ִ� �Լ�
	void setPort(int nPort) { m_nPort = nPort; }

private: // �Ʒ� �ڵ�� ��� private member(class �ܺο��� ���� �Ұ���, class ���ο����� ���� ����)
	// private property(��� ����)
	int m_nPort; // m_: member�� ��
};