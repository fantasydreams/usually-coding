//讲中缀表达式转换为后缀表达式并输出

#include <iostream>
#include <string>
#define Max 512

using namespace std;

inline void InputExpression(char *EP);
void Exchange(const char * , char * ,int & );

int main()
{
	char Stack[Max] = {'\0'};
	char EP[Max] = { '\0' };
	int location = -1;  //指向栈顶的位置的下标
	InputExpression(EP);
	Exchange(EP, Stack,location);
	return 0;
}



inline void InputExpression(char *EP)
{
	cout << "请输入中缀表达式：";
	cin >> EP;
}

void Exchange(const char * EP, char *Stack,int & Location)
{
	for (int i = 0; '\0' != EP[i]; i++)
	{
		if (EP[i] >= '0' && EP[i] <= '9')
			cout << EP[i];
		else
		{
			if ('(' == EP[i] || '（' == EP[i])
				Stack[++Location] = EP[i];
			else if (')' ==EP[i] || '）' == EP[i])
			{
				while ((Stack[Location] != '(' && Stack[Location] != '（')&&Location !=-1)
					cout << Stack[Location--];
				--Location;
			}
			else if ('*' == EP[i] || '/' == EP[i])
			{
				if ('-' == Stack[Location] || '+' == Stack[Location])
					Stack[++Location] = EP[i];
				else
				{
					while (('(' != Stack[Location] || '（' != Stack[Location]) && Location != -1)
					{
						if ('-' != Stack[Location] || '+' != Stack[Location])
							break;
							cout << Stack[Location--];
					}
					Stack[++Location] = EP[i];
				}
			}
			else if ('-' == EP[i] || '+' == EP[i])
			{
				while ((Stack[Location] != '(' || Stack[Location] != '（'))
				{
					if (-1 == Location)
						break;
					cout << Stack[--Location];
				}
				if ('（' == Stack[Location] || '(' == Stack[Location])
					++Location;
				Stack[++Location] = EP[i];
			}
		}
	}
	while (Location != -1)
		cout << Stack[Location--];

	cout << endl;
}

