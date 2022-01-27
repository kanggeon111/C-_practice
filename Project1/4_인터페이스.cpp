//	4_�������̽�
#include <iostream>

// ���� ���� (tightly coupling)

// �ϳ��� Ŭ������ �ٸ� Ŭ���� ���� �̸��� ���� ����ϴ� ��

// ��ü �Ұ����� ������ ������

class Camera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "take HD picture" << std::endl; }
};

class People
{
public:
	void useCamera(Camera* p) { p->take(); }
	void useCamera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc);
}