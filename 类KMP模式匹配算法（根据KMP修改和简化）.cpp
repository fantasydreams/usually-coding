//����׺���ʽת��Ϊ��׺���ʽ�����

#include <iostream>
#include <string>

using namespace std;

int KMP(const string Str, const string NStr);

int main()
{
	string Str; //�洢��
	string NeedStr;//��Ҫƥ��Ĵ�
	cin >> Str >> NeedStr;
	cout << KMP(Str, NeedStr);
	system("pause");
	return 0;
}

//KMPƥ���ַ��������ҵ�ƥ�䣬��������ĸ����λ�ã�û�ҵ����򷵻�-1
int KMP(const string Str, const string NStr)
{
	int NstrLength = NStr.length();
	int Length = Str.length() - NstrLength;  //��¼�����ַ�����С�Ĳ�ֵ
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


