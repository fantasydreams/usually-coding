#include <iostream>
#include <string>
using namespace std;
// 判断回文数

bool isPalidrome(string  p);

int main()
{
	string s;
	cout << "请输入字符串：";
	cin >> s;
	if (isPalidrome(s))
		cout << s << "是回文数" << endl;
	else
		cout << s << "不是回文数！" << endl;
	system("pause");
	return 0;
}

bool isPalidrome(string  p)
{
	int start = 0, end = p.length() - 1;
	while (start != end && start <= end)
		if (p[start++] != p[end--])
			return false;
	return true;
}