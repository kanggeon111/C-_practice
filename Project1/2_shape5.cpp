//	2_shape3
#include <iostream>
#include <vector>


class Shape
{
	int color;
public:
	void setColor(int c) { color = c; }

	// 가상함수로 만드는 것 : 파생클래스가 만들지 않으면 구현을 물려주겟다는것
	// 순수 가상함수로 만드는것 : 파생클래스 꼭 만들라고 시키는것.

	// 아래 의미는 "getArea()"를 제공하지 않은 도형의 경우는 -1이 반환된다" 정도의 도움말 필요!
	virtual double getArea() const { return 0; }
	

	virtual void draw() = 0;

	virtual Shape* Clone() const = 0;

};

class Rect : public Shape
{
public:
	virtual void draw() override { std::cout << "Draw Rect" << std::endl; }

	// 가상함수 재정의시 "반환 타입"을 상속관계 타입끼리는 변경 가능합니다.
	// 아래 코드에서 "int*"로 변경은 안됩니다.
	virtual Rect* Clone() const override
	{
		Rect* p = new Rect;
		return p;
	}
};

class Circle : public Shape
{
public:
	virtual void draw() { std::cout << "Draw Circle" << std::endl; }

	virtual Circle* Clone() const override
	{
		Circle* p = new Circle;
		return p;
	}
};

class Triangle : public Shape
{
public:
	virtual void draw() { std::cout << "Draw Triangle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

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
				p->draw();
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 만들었던 도형을 복제할까요";

			int k;
			std::cin >> k;

			Shape* p = v[k - 1]->Clone();
			v.push_back(p);
		}

		else if (cmd == -1)
			break;
	}

	for (auto p : v)
		delete p;
}

