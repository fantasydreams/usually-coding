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
			case 72:cout << "�ϼ���" << endl;
				break;
			case 80:cout << "�¼���" << endl;
				break;
			case 75:cout << "�����" << endl;
				break;
			case 77:cout << "�Ҽ���" << endl;
		}
	}
	return 0;
}

//�������Ҽ����������ַ�����γɵ�