#include <iostream>
using namespace std;

union
{
	int i;
	char x[2];
}a;

int main()
{
	a.x[0] = 1;
	a.x[1] = 0;
	if (a.i == a.x[0])
		cout << "litter" << endl;
	else
		cout << "big" << endl;
	return 0;
}