//	4_�������̽�2
#include <iostream>

// ���� ���� (loosely coupling)

// �ϳ��� Ŭ������ �ٸ� Ŭ���� ���� ���Ŭ������ �߻� Ŭ������ ���ؼ� ����ϴ� ��

// ��ü ������ ������ ������

// ��� ����
// �������̽� : ���Ѿ��ϴ� ��Ģ�� ����		(���� �����Լ��� ����ִ� ��)
// �߻�Ŭ���� : ���Ѿ��ϴ� ��Ģ + �����ֱ����� �����

// �ٸ� ��ü ���� ���� "interface"��� Ű���尡 ������ C++�� �߻� Ŭ���� �������� �������̽��� ����ϴ�.


// ----------------------------
// ī�޶� ���� �������� ����, ��Ģ�� ��������
// ��Ģ : ��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�.
//		 ��� ī�޶�� ICamera �������̽��� �����ؾ� �Ѵ�. ��� ǥ���մϴ�

class ICamera
{
public:
	virtual void take() = 0;
};

// ���� ī�޶�� ������, ��Ģ�� �ִ�.. ��Ģ��θ� ����ϸ� �ȴ�.
class People
{
public:
	void useCamera(ICamera* p) { p->take(); }
};


class Camera : public ICamera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "take HD picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "take UHD picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc);

	UHDCamera uhc;
	p.useCamera(&uhc);
}