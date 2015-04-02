
//antor table
#include <iostream>
#include <cmath>

using namespace std;

int gcd(int x, int y)  //calculate maxinum devisor
{
	int r = x % y;
	while (r)
	{
		x = y;
		y = r;
		r = x % y;
	}
	return y ;
}

//int d(int x, int y)  //calculate mininum multiple
//{
//	long temp = x * y;
//	return temp / gcd(x, y);
//}

int main()
{
	int max, min,num = 0;
	cin >> max >> min;
	long temp = max * min;
	int c = int(sqrt(temp));
	for (int i = max; i <= c; i++)
	{
		if (min%i == 0 && gcd((int)(temp / i), i) == max)
			num++;
	}
	num *= 2;
	cout << num<<endl;
	return 0;
}



