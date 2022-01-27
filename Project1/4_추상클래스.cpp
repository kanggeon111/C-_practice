// 3_override

#include <iostream>

//�߻�Ŭ���� (abstract class) : ���� �����Լ��� �Ѱ� �̻��� Ŭ����
// Ư¡ : ��ü ������ �� ����.
// �ǵ� : Ư���� ��� �Լ��� �ݵ�� ������ �Ѵٰ� �����ϴ� ��
class Shape
{
public:
	virtual void draw() = 0; // ���� �����Լ� (pure virtual function)
							// �����ΰ� ����, "=0"���� ������.
};

class Rect : public Shape
{
public:
	// Shape�� ���� ��ӵ� "draw()" ���� �����Լ��� 
//		������ �������� ������ :Rect �� �߻�, 
	// �����ϸ� Rect�� �߻� �ƴ�
	virtual void draw() override {}
};

int main()
{
	//Shape s; // error �߻� Ŭ���� ��ü�� ���� �� ����.
	//Shape* p; // ok ��ü�� �ƴ� �����ʹ� ����
	Rect c;
}