
//antor table
#include <iostream>

using namespace std;



int main()
{
	int numerator = 1, denominator = 1, n,max =1,temp = -1;
	bool broadwise = false;
	cin >> n;
	while (n <= 0)  //sure n is a positive integer
		cin >> n;
	for (int i = 1; i < n; i++)
	{
		if ((numerator == 1 || denominator == 1) && (temp!=i-1))
		{
			temp = i;
			if (broadwise)
				broadwise = false;
			else
				broadwise = true;
			if (broadwise == true)
				denominator++;
			else
				numerator++;
		}
		else
		if (broadwise)
		{
			numerator++;
			denominator--;
		}
		else
		{
			numerator--;
			denominator++;
		}
	}
	cout << numerator << "/" << denominator;
	return 0;
}
