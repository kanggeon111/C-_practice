//	2_shape1.cpp - 교재 152 page

#include <iostream>
#include <vector>

// 1. 모든 도형을 타입화 하면 편리하다
// 2. 모든 도형의 공통의 기반 클래스가 있다면 묶어 관리 할 수 있다.
// 3. 모든 도형의 공통의 특징 (draw) 는 반드시 기반 클래스에도 있어야 한다.
// 4. 기반 클래스 멤버 함수 중, 파생클래스가 재정의 (override)하게 되는 함수는
//	반드시 가상함수 (virtual) 가 되어야 한다.

class Shape
{
	int color;
public:
	// 아래 멤버 함수는 "virtual"이 될 필요가 있을까요?
	void setColor(int c) { color = c; }

	// 면적을 구하는 것은 도형 마다 다릅니다. 재정의 되어야 합니다. ( virtual이 되어야 합니다.)
	virtual double getArea() const { return 0; }
	virtual void draw() { std::cout << "Draw Shape" << std::endl; }
};

class Rect : public Shape
{
public:
	virtual void draw() { std::cout << "Draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	virtual void draw() { std::cout << "Draw Circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v; //?

	while (1)
	{
		int cmd;
		std::cin >> cmd;
		if (cmd == 1)
		{
			// Rect r;	이렇게 만들면 {} 벗어날 때 바로 파괴입니다.
			Shape* p = new Rect;	// 이렇게 해야 파괴되지 않습니다.
			v.push_back(p);
		}

		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}

		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}

	}
}