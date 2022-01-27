//	1_virtual1

#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal cry" << std::endl; }
	virtual void cry2() { std::cout << "Animal cry2" << std::endl; }

};

class Dog : public Animal
{
public:
	// override : 기반 클래스 멤버 함수를 파생 클래스가 다시 만드는것.
	// overloading과는 다릅니다 (square(int), square(double))
	void cry() { std::cout << "Dog cry" << std::endl; }	// 2
	virtual       void cry2() { std::cout << "Dog cry2" << std::endl; }	// 2
};

int main()
{
	Animal a; a.cry();
	Dog d; d.cry();
	Animal* p = &d;

	//if (사용자가 입력한 값 == 1) p = &a;

	// 컴파일러는 p가 가리키는 곳의 객체가 무엇인지 알 수 없다.
	p->cry();		 // 논리적으로는 Dog cry가 맞다 그런데, C++에서는 Animal Cry

	p->cry2();

}

// p-> cry()를 어떤 함수와 연결할 것인가?
//	함수 바인딩 문제 (교재 161 page)

// 1. static binding : 컴파일러가 컴파일 시간에 함수 호출을 결정
						//컴파일러는 p의 타입이 "animal*"라는 것만 알고 실제 p가 가리키는 객체가 무엇인지 알 수없다. 
//						Animal cry 호출 - 빠르다 논리적이지 않다. C++ 기본 정책, C#

// 2. dynamic binding : 컴파일 시에 p가 가리키는 메모리를 조사하는 기계어 코드 생성
//						실행시 p가 가리키는 곳의 객체를 조사한 후 함수 호출 결정
//						Dog가 객체있었다면 Dog cry() 호출 - 느리다 논리적이다
//						java, python, swift 등 대부분의 객체지향 언어