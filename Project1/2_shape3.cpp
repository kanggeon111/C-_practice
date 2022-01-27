//	2_shape3
#include <iostream>
#include <vector>


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
			std::cout << "���° ������� ������ �����ұ��";

			int k;
			std::cin >> k;

			// k��° ������� ������ �������� ���� v�� �߰��Ϸ��� �մϴ�.
			// �׷��� k ��° ������ �����?
			// ��� �ؾ� �ұ��?
			decltype(v[k - 1]); // s�� ���� Ÿ���ϱ��? 1. Rect �Ǵ� Circle 2. Shape*
		}


	}
}