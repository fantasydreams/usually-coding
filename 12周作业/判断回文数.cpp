#include <iostream>
#include <string>
using namespace std;
// �жϻ�����

bool isPalidrome(string  p);

int main()
{
	string s;
	cout << "�������ַ�����";
	cin >> s;
	if (isPalidrome(s))
		cout << s << "�ǻ�����" << endl;
	else
		cout << s << "���ǻ�������" << endl;
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