#include <iostream>
#include <cmath>

using namespace std;


void _move(int n,char one, char two, char three)
{
	if (n == 1)
		cout << n << " from " << one << " to " << three << endl;
	else
	{
		_move(n - 1, one, three, two);
		cout << n << " from " << one << " to " << three << endl;
		_move(n - 1, two, one, three);
	}
}

int main()
{
	int num;
	cin >> num;
	cout << (pow(2, num) - 1)<<endl;
	_move(num,'A', 'B', 'C');
	system("pause");
	return 0;
}