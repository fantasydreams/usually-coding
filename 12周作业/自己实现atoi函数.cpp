#include <iostream>
#include <string>
using namespace std;
// �Լ�ʵ��atoi�����Ĺ���

int My_atoi(const char *  p);

int main()
{
	string s;
	cout << "������һ���ַ�����";
	cin >> s;
	cout<<"����ת��Ϊ����Ϊ:"<<My_atoi(s.c_str())<<endl;
	system("pause");
	return 0;
}

int My_atoi(const char *  p)
{
	int flag = 1 ,result = 0;
	if (*p >= '0' && *p <= '9' || '-' == *p || '+' == *p)
		if ('-' == p[0])
		{
			flag = -1;
			p++;
		}
		else if ('+' == p[0])
			p++;
	while (*p <= '9' && *p >= '0')
		result = 10 * result + (*p++ - '0');
	return flag * result;

}