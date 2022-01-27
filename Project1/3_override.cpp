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
	// 1. 가상함수 재정의시 "virtual"은 붙여도 되고 안붙여도 됩니다
	//  => 가독성 측면에서는 붙이세요
	//virtual void draw() { std::cout << "Rect draw" << std::endl; }

	// 2. 가상함수 재정의시 오타 발생!
	//		=> 에러나지 않습니다. 컴파일러는 새로운 함수라고 생각하게 됩니다.
	//virtual void Draw() { std::cout << "Rect draw" << std::endl; }

	// 3. 2번 문제가 너무 심각해서 C++11 에서 "override" 키워드 도입
	virtual void Draw() override // 컴파일러에게 새로운 함수가 아니라 기반 클래스 함수를 재정의한다고 알려주는것
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