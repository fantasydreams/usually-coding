#include <iostream>
#include <string>
using namespace std;
// 自己实现atoi函数的过程

int My_atoi(const char *  p);

int main()
{
	string s;
	cout << "请输入一个字符串：";
	cin >> s;
	cout<<"经过转换为整形为:"<<My_atoi(s.c_str())<<endl;
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