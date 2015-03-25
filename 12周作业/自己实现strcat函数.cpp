#include <iostream>
using namespace std;
// 自己实现strcat函数

void Strcat(char to[], char from[]);
int main()
{
	char to[30], from[30];
	cout << "请输入第一个字符串：";
	cin >> to;
	cout << "请输入第二个字符串：";
	cin >> from;
	Strcat(to, from);
	system("pause");
	return 0;
}

void Strcat(char to[], char from[])
{
	if (30 < strlen(from) + strlen(to) + 1)   //判断是否满足将from中的全部字符连接到to字符串后面；
		cout << "连接失败！不满足连接的要求！" << endl;
	else
	{
		int i = 0;
		for (; to[i] != '\0'; i++);
		for (int j = 0; from[j] != '\0'; j++, i++)
			to[i] = from[j];
		to[i] = '\0';   //给字符数组加上'\0'形成字符串；
		cout << "第一个与第二个字符串连接后的结果：" << to << endl;
	}
}