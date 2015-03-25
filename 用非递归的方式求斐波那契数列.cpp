#include <iostream>

using namespace std;
void Feibo(int n);

int main()
{
	Feibo(10);
	system("pause");
	return 0;
}


//求斐波那契数列
void Feibo(int n)
{
	long f1 , f2;
	f1 = f2 = 1;
	for (int i = 1; i <= n; i++)
	{
		cout << f1 << "	" << f2 << "	";
		f1 += f2;
		f2 += f1;
	}
}
