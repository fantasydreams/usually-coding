#include <iostream>
using namespace std;
// �Լ�ʵ��strcat����

void Strcat(char to[], char from[]);
int main()
{
	char to[30], from[30];
	cout << "�������һ���ַ�����";
	cin >> to;
	cout << "������ڶ����ַ�����";
	cin >> from;
	Strcat(to, from);
	system("pause");
	return 0;
}

void Strcat(char to[], char from[])
{
	if (30 < strlen(from) + strlen(to) + 1)   //�ж��Ƿ����㽫from�е�ȫ���ַ����ӵ�to�ַ������棻
		cout << "����ʧ�ܣ����������ӵ�Ҫ��" << endl;
	else
	{
		int i = 0;
		for (; to[i] != '\0'; i++);
		for (int j = 0; from[j] != '\0'; j++, i++)
			to[i] = from[j];
		to[i] = '\0';   //���ַ��������'\0'�γ��ַ�����
		cout << "��һ����ڶ����ַ������Ӻ�Ľ����" << to << endl;
	}
}