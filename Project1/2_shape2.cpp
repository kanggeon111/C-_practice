//	2_shape2

#include <iostream>
#include <vector>

// 5. OCP
//		기능확장에는 열려 있고 (Open, 미래에 클래스등이 추가 되어도)
//		코드수정에는 닫혀 있어야 (Close)
//		한다는 이론 (Principle)

//		개방 폐쇄의 법칙 (OCP) 이라고 번역되어 있습니다

//		다형성은 OCP를 만족하는 아주 좋은 코딩 스타일 입니다.
//		객체 지향 디자인시 지켜야 하는 5개의 원칙 : SRP, OCP, LSP, ISP, DIP (SOLID)

class Shape
{
	int color;
public:
	void setColor(int c) { color = c; }

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

class Triangle : public Shape
{
public:
	virtual void draw() { std::cout << "Draw Triangle" << std::endl; }
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
			Shape* p = new Rect;	
			v.push_back(p);
		}

		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}

		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();	// 다형성 (Polymorphism)
							// 동일한 표현식 (함수호출)이 상황 (객체)에 따라 다르게 동작하는것

							// 객체지향 프로그래밍의 3대 특징 : 캡슐화, 상속, 다형성
		}

	}
}