#include <iostream>

/*
recursion

f(x) = fx(x+1) + f(x+2) + 1 (x<0)
fx(x) = 5 (x>=0)
*/

using namespace std;

int recursion(int n);

int main()
{
	int n;
	cin >> n;
	cout << recursion(n);
	system("pause");
	return 0;
}

int recursion(int n)
{
	if (n >= 0)
		return 5;
	else
		return recursion(n + 1) + recursion(n + 2) + 1;
}
