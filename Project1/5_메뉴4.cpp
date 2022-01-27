// 5_�޴�3

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

// ��� �޴��� ������ ��� Ŭ����
class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s) {}
	std::string getTitle() const { return title; }
	virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		std::cout << getTitle() << "�޴��� ���õ�" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}
	void addMenu(BaseMenu* p) { v.push_back(p); }

	void command()
	{
		while (1)
		{
			system("cls"); 

			int sz = v.size(); 

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << "." << v[i]->getTitle() << std::endl;
			}
			std::cout << sz + 1 << ".����" << std::endl;
			std::cout << "�޴��� ������ �ּ��� >>";
			int cmd;
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1) 
				break;

			v[cmd - 1]->command();
		}
	}
};

int main()
{
	PopupMenu* menuBar = new PopupMenu("MENUBAR");
	PopupMenu* p1 = new PopupMenu("���� ����");
	PopupMenu* p2 = new PopupMenu("�ػ� ����");

	menuBar->addMenu(p1);
	//menuBar->addMenu(p2);
	p1->addMenu(p2);

	p1->addMenu(new MenuItem("Red", 11));
	p1->addMenu(new MenuItem("Green", 12));
	p1->addMenu(new MenuItem("Blue", 13));

	p2->addMenu(new MenuItem("HD", 21));
	p2->addMenu(new MenuItem("FHD", 22));
	p2->addMenu(new MenuItem("UHD", 23));

	// ���� �����Ϸ���?

	menuBar->command();

}
