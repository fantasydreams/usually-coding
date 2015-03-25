//讲中缀表达式转换为后缀表达式并输出

#include <iostream>
#include <string>

using namespace std;

int KMP(const string Str, const string NStr);

int main()
{
	string Str; //存储串
	string NeedStr;//需要匹配的串
	cin >> Str >> NeedStr;
	cout << KMP(Str, NeedStr);
	system("pause");
	return 0;
}

//KMP匹配字符串，若找到匹配，返回首字母所在位置，没找到，则返回-1
int KMP(const string Str, const string NStr)
{
	int NstrLength = NStr.length();
	int Length = Str.length() - NstrLength;  //记录两个字符串大小的差值
	int Flag = 0, j;
	for (int i = 1; i < NstrLength; i++)
	{
		if (NStr[0] == NStr[i])
		{
			Flag = i;
			break;
		}
	}
	for (int i = 0; i <= Length; i++)
	{
		if (Str[i] == NStr[0])
		{
			for (j = 1; j < NstrLength; j++)
			{
				if (Str[i + j] != NStr[j])
					break;
			}

			if (j == NstrLength)
				return i+1;
			else
			{
				if (j > Flag)
					i+=Flag -1;
				else
					i += j - 1;
			}
				
		}
	}
	return -1;
}


