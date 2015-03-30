#include <iostream>

/*
decimal integer number convert to m Hex
*/

using namespace std;

int main()
{
	char letter[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };  //can expression 0-16
	int Dec, ex;  //Dec save Decimal integer number,ex save m hex
	char str[30] = { '0' };  //this str be used for number after conversion
	cin >> Dec >> ex;
	while (ex >= 17 || ex <= -1)  //sure hex between 0-16
		cin >> ex;
	int i = 0;
	while (Dec)
	{
		str[i++] = letter[Dec%ex];
		Dec /= ex;
	}
	--i;
	while (i >= 0)
		cout << str[i--];
	cout << endl;
	return 0;
}
