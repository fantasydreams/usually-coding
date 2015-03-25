#include <iostream>
using namespace std;
// 自己实现strcmp函数

char * Strchr(char to[], char Ch);
int main()
{
	char to[30], ch, *p;
	cout << "请输入字符串：";
	cin >> to;
	cout << "请输入一个字符：";
	cin >> ch;
	p = Strchr(to, ch);
	if (p != NULL)
		cout << "第一个开始匹配后的字符串是：" << p << endl << "在数组的第【" << p - to + 1 << "】个位置" << endl;
	else
		cout << "没有匹配的字符！" << endl;
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