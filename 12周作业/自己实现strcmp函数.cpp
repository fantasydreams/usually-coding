#include <iostream>
using namespace std;
// 自己实现strcmp函数

int Strcmp(char to[], char from[]);
int main()
{
	char to[30], from[30];
	int flag;
	cout << "请输入第一个字符串：";
	cin >> to;
	cout << "请输入第二个字符串：";
	cin >> from;
	flag = Strcmp(to, from);
	if (1 == flag)
		cout << to << "大于" << from << endl;
	else if (0 == flag)
		cout << to << "等于" << from << endl;
	else
		cout << to << "小于" << from << endl;
	system("pause");
	return 0;
}

int Strcmp(char to[], char from[])
{
	int i = 0;
	for (; '\0' != to[i]  && '\0' != from[i]; i++)
		if (to[i] > from[i])
			return 1;
		else if (to[i] < from[i])
			return -1;
	if ('\0' == to[i])
		return -1;
	else if ('\0' == from[i])
		return 1;
	else
		return 0;
}