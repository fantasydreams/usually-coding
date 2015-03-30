#include <iostream>

/*
3n+1 problem
*/

using namespace std;

void calculate(int * a, const int number, int num);

int main()
{
	int size;
	cin >> size;
	int * p = new int[size];
	for (int i = 0,temp; i < size; i++)
	{
		cin >> temp;
		calculate(p, temp, i);
	}
	for (int i = 0; i < size; i++)
	{
		cout << p[i]<<endl;
	}
	delete[] p;  //free memory
	system("pause");
	return 0;
}

void calculate(int * p, int number,int i)
{
	int n = 0;
	while (number != 1)
	{
		if (number % 2)
			number = 3 * number + 1;
		else
			number /= 2;
		if (n > 1000)
		{
			p[i] = -1;
			break;
		}
		n++;
	}
	p[i] = n;
}