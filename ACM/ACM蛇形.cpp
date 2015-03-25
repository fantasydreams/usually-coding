#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int array[100][100] = {0};
	int n,num,num1,flag,number = 1;
	int line = 1;
	bool flag1 = true;
	cin >> n;
	if (n % 2 == 0)
		exit(0);
	else
		flag = num1 =  num = n / 2 ;
	array[num][num1] = number;
	for (int i = 0; i <= 2 * flag; i++)
		for (int j = 0; j <= 1; j++)
		{
			if (!j)
				for (int m = 0; m < line; m++)
					if (flag1)
						array[num][++num1] = ++number;
					else
						array[num][--num1] = ++number;
			else
			{
				for (int n = 0; n < line;n++)
					if (!flag1)
						array[++num][num1] = ++number;
					else
						array[--num][num1] = ++number;
				flag1 = !flag1;
				line++;
			}
		}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j] << " ";
			if (i == j)
				sum += array[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		sum += array[i][n - i - 1];
	}
	sum -= array[n / 2][n / 2];
	cout <<sum<< endl;
	return 0;
}