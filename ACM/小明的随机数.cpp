#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int num,Data;
	vector<int>number;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> Data;
		number.push_back(Data);
	}
	sort(number.begin(), number.end());
	number.erase(unique(number.begin(), number.end()), number.end());
	cout << number.size() << endl;
	for (vector<int>::iterator iter = number.begin(); iter != number.end(); iter++)
		cout << *iter<<" ";
	return 0;
}