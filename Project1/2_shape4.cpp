//	2_shape3
#include <iostream>
#include <vector>

// 1994년 4명의 개발자가 "당시 유행하던 유명한 코딩 스타일에 이름을 부여"
// "디자인 패턴책" - 23개의 이름
//	"GOF's Design Pattern" 책

// prototype pattern : clone() 가상함수를 만드는 기법에 붙인 이름.

class Shape
{
	int color;
public:
	void setColor(int c) { color = c; }

	virtual double getArea() const { return 0; }
	virtual void draw() { std::cout << "Draw Shape" << std::endl; }

	// 자신의 복사본을 만드는 가상함수는 아주 유용하게 활용됩니다.
	virtual Shape* Clone() const
	{
		Shape* p = new Shape;
		p->color = color; // 모든 멤버를 자신과 동일하게 설정한 후 
		return p;
	}

};

class Rect : public Shape
{
public:
	virtual void draw() { std::cout << "Draw Rect" << std::endl; }

	virtual Shape* Clone() const
	{
		Rect* p = new Rect;
		// 내 멤버와 동일하게 p 객체 설정
		return p;
	}
};

class Circle : public Shape
{
public:
	virtual void draw() { std::cout << "Draw Circle" << std::endl; }

	virtual Shape* Clone() const
	{
		Circle* p = new Circle;
		// 내 멤버와 동일하게 p 객체 설정
		return p;
	}
};
// Circle* p = new Circle;
// Shape* p2 = p->Clone();

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

		// 1. 객체의 생성과정을 OCP를 만족하게 할 수 없을까?
		//	=> "추상 팩토리"패턴을 알면 할 수 있습니다.
		// 2. Undo/Redo 를 하려면 어떻게 해야할까요?
		//	=> Command 패턴을 알면 할 수 있습니다
		//	2_shape3
#include <iostream>
#include <vector>

// 1994년 4명의 개발자가 "당시 유행하던 유명한 코딩 스타일에 이름을 부여"
// "디자인 패턴책" - 23개의 이름
//	"GOF's Design Pattern" 책

// prototype pattern : clone() 가상함수를 만드는 기법에 붙인 이름.

class Shape
{
	int color;
public:
	void setColor(int c) { color = c; }

	virtual double getArea() const { return 0; }
	virtual void draw() { std::cout << "Draw Shape" << std::endl; }

	// 자신의 복사본을 만드는 가상함수는 아주 유용하게 활용됩니다.
	virtual Shape* Clone() const
	{
		Shape* p = new Shape;
		p->color = color; // 모든 멤버를 자신과 동일하게 설정한 후 
		return p;
	}

};

class Rect : public Shape
{
public:
	virtual void draw() { std::cout << "Draw Rect" << std::endl; }

	virtual Shape* Clone() const
	{
		Rect* p = new Rect;
		// 내 멤버와 동일하게 p 객체 설정
		return p;
	}
};

class Circle : public Shape
{
public:
	virtual void draw() { std::cout << "Draw Circle" << std::endl; }

	virtual Shape* Clone() const
	{
		Circle* p = new Circle;
		// 내 멤버와 동일하게 p 객체 설정
		return p;
	}
};
// Circle* p = new Circle;
// Shape* p2 = p->Clone();

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

		// 1. 객체의 생성과정을 OCP를 만족하게 할 수 없을까?
		//	=> "추상 팩토리"패턴을 알면 할 수 있습니다.
		// 2. Undo/Redo 를 하려면 어떻게 해야할까요?
		//	=> Command 패턴을 알면 할 수 있습니다

		// 즉, 전형적인 어떤일을 하고 싶다. => 그 작업을 수행하는 전형적인 코드가 존재합니다. 이름도 부여되어 있습니다.  "디자인 패턴"을 학습하면 됩니다.
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

			Shape* p = v[k - 1]->Clone(); // 어떤 도형인지 알 필요 없다. 그냥, 복제본 만들어달라 다형성!!..OCP를 만족합니다.  다형성 시험에 나온다?!

			v.push_back(p);
		}


	}
}


		// 즉, 전형적인 어떤일을 하고 싶다. => 그 작업을 수행하는 전형적인 코드가 존재합니다. 이름도 부여되어 있습니다.  "디자인 패턴"을 학습하면 됩니다.
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

			Shape* p = v[k - 1]->Clone(); // 어떤 도형인지 알 필요 없다. 그냥, 복제본 만들어달라 다형성!!..OCP를 만족합니다.  다형성 시험에 나온다?!

			v.push_back(p);
		}


	}
}

