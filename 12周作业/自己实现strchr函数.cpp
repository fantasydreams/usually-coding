#include <iostream>
using namespace std;
// �Լ�ʵ��strcmp����

char * Strchr(char to[], char Ch);
int main()
{
	char to[30], ch, *p;
	cout << "�������ַ�����";
	cin >> to;
	cout << "������һ���ַ���";
	cin >> ch;
	p = Strchr(to, ch);
	if (p != NULL)
		cout << "��һ����ʼƥ�����ַ����ǣ�" << p << endl << "������ĵڡ�" << p - to + 1 << "����λ��" << endl;
	else
		cout << "û��ƥ����ַ���" << endl;
	system("pause");
	return 0;
}

char * Strchr(char to[], char Ch)
{
	int i = 0;
	while (to[i] != Ch && to[i] != '\0')
		i++;
	return to[i] != '\0' ? to + i : NULL;
}