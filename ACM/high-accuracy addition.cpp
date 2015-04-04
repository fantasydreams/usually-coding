#include <string>
#include <iostream>

using namespace std;



int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	char str[501];
	str[0] = '0';
	int len1 = str1.length(), len2 = str2.length();
	int ca = len1 - len2;
	if (ca >= 0)
	{
		strcpy_s(str + 1, 500, str1.c_str());
		for (int i = len2 - 1; i >= 0; i--)
		{
			if ('0' <= (str[i + ca + 1] + str2[i] - '0') && (str[i + ca + 1] + str2[i] - '0') <= '9')
				str[i + ca + 1] += (str2[i] - '0');
			else
			{
				str[i + ca + 1] += (str2[i] - '0' - 10);
				str[i + ca] += 1;
			}
		}
	}
	else
	{
		ca = -ca;
		strcpy_s(str + 1, 500, str2.c_str());
		for (int i = len1 - 1; i >= 0; i--)
		{
			if ('0' <= (str[i + ca + 1] + str1[i] - '0') && (str[i + ca + 1] + str1[i] - '0') <= '9')
			{
				//cout << str[i + ca + 1] << endl;
				str[i + ca + 1] += (str1[i] - '0');
			}
			else
			{
				str[i + ca + 1] += (str1[i] - '0' - 10);
				str[i + ca ] += 1;
			}
		}
	}

	if (str[0] == '0')
		cout << str + 1;
	else
		cout << str;

	return 0;
}