#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	char a;
	while (a = _getch())
	{
		if (-32 == a)
		{
			a = _getch();
			switch ((int)a)
			{
			case 72:cout << "上键！" << endl;
				break;
			case 80:cout << "下键！" << endl;
				break;
			case 75:cout << "左键！" << endl;
				break;
			case 77:cout << "右键！" << endl;
		}
	}
	return 0;
}

//上下左右键是由两个字符组和形成的