#include <string>
#include <iostream>

using namespace std;



int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int len1 = str1.length(), len2 = str2.length();
	if (len1 > len2)
	{
		int ca = len1 - len2;
		for (int i = len2 - 1; i >= 0; i--)
		{
			if (str1[i + ca] < str2[i])
			{
				str1[i - 1 + ca] -= 1;
				str1[i + ca] -=( str2[i] - '0' - 10);
			}
			else
				str1[i + ca] -= (str2[i]-'0');
		}
		cout << str1;
	}
	else if (len1 == len2)
	{
		if (str1>str2)
		{
			for (int i = len1 - 1; i >= 0; i--)
			{
				if (str1[i] < str2[i])
				{
					str1[i - 1] -= 1;
					str1[i] -= (str2[i] - '0' - 10);
				}
				else
					str1[i] -= (str2[i] - '0');
			}
			cout << str1;
		}
		else
		{
			for (int i = len1 - 1; i >= 0; i--)
			{
				if (str2[i] < str1[i])
				{
					if (i< len1)
						str2[i - 1] -= 1;
					str2[i] -= (str1[i] -'0' - 10);
				}
				else
					str2[i] -= str1[i]-'0';
			}
			cout << '-'<<str2;

		}
	}
	else
	{
		int ca = len2 - len1;
		for (int i = len1 - 1; i >= 0; i--)
		{
			if (str2[i + ca] < str1[i])
			{
				if (i< len1)
					str2[i - 1 + ca] -= 1;
				str2[i + ca] -= str1[i] - 10 - '0';
			}
			else
				str2[i + ca] -= str1[i] - '0';
		}
		cout << '-' << str2;
	}


	system("pause");
	return 0;
}