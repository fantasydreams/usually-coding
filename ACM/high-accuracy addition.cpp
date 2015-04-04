#include <cstring>
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
		strcpy(str + 1, str1.c_str());
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
		for(int i=ca;i>=0;i--)
            if(str[i] >=  '9' +1)
            {
                str[i-1] +=1;
                str[i] -= 10;
            }
	}
	else
	{
		ca = -ca;
		strcpy(str + 1,str2.c_str());
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
		for(int i=ca;i>=0;i--)
            if(str[i] >=  '9' +1)
            {
                str[i-1] +=1;
                str[i] -= 10;
            }
	}

	if (str[0] == '0')
		cout << str + 1;
	else
		cout << str;

	return 0;
}
