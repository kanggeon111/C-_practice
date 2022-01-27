// 3_override

#include <iostream>

class Shape
{
public:
	virtual void draw() { std::cout << "Shape draw" << std::endl; }
};

class Rect : public Shape
{
public:
	// 1. �����Լ� �����ǽ� "virtual"�� �ٿ��� �ǰ� �Ⱥٿ��� �˴ϴ�
	//  => ������ ���鿡���� ���̼���
	//virtual void draw() { std::cout << "Rect draw" << std::endl; }

	// 2. �����Լ� �����ǽ� ��Ÿ �߻�!
	//		=> �������� �ʽ��ϴ�. �����Ϸ��� ���ο� �Լ���� �����ϰ� �˴ϴ�.
	//virtual void Draw() { std::cout << "Rect draw" << std::endl; }

	// 3. 2�� ������ �ʹ� �ɰ��ؼ� C++11 ���� "override" Ű���� ����
	virtual void Draw() override // �����Ϸ����� ���ο� �Լ��� �ƴ϶� ��� Ŭ���� �Լ��� �������Ѵٰ� �˷��ִ°�
	{
		std::cout << "Rect draw" << std::endl;
	}
};

int main()
{
	Shape* p = new Rect;
	p->draw();
	delete p;
}