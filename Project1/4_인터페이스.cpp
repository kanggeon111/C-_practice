//	4_인터페이스
#include <iostream>

// 강한 결함 (tightly coupling)

// 하나의 클래스가 다른 클래스 사용시 이름을 직접 사용하는 것

// 교체 불가능한 경직된 디자인

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