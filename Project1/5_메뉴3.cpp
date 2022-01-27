// 5_�޴�3

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string getTitle() const { return title; }

	void command()
	{
		std::cout << getTitle() << "�޴��� ���õ�" << std::endl;
		_getch();
	}
};
// PopupMenu : �����ϸ� �ٸ� �޴� (���� �޴�) �� ������ �޴�

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& s) : title(s) {}
	void addMenu(MenuItem* p) { v.push_back(p); }

	// �˾� �޴��� �����Ҷ�.. - �� ������ �ٽ�
	void command()
	{
		while (1)
		{
			system("cls"); // ȭ�� �����

			int sz = v.size(); // ���� �޴� ����

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << "." << v[i]->getTitle() << std::endl;
			}
			std::cout << sz + 1 << ".����" << std::endl;
			std::cout << "�޴��� ������ �ּ��� >>";
			int cmd;
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1) // �߸��� �Է�
				continue;

			if (cmd == sz + 1) // ���� �޴� ���ý�
				break; // �Ǵ� return



			// ���õ� �޴��� �����Ϸ���?
			v[cmd - 1]->command();
		}
	}
};

int main()
{
	// ���� 
	// 1. �޴�������ŭ�� ��ü�� ���弼��
	MenuItem m1("���󺯰�", 11);
	MenuItem m2("�ɼ�", 12);

	// 2. �˾� �޴��� �޴� ��ü�� ��������.
	PopupMenu pm("ī�޶� �޴�");
	pm.addMenu(&m1);
	pm.addMenu(&m2);

	// 3. �˾� �޴��� ���� (command ȣ��) �ϼ���
	pm.command(); // �˾��޴� ����

}
