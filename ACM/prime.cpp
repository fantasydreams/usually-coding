#include <iostream>
#include <cmath>

using namespace std;


//Prime function declare(this function is judge whether a number is prime or not,if it is ,return true,else false)
bool Prime(int a);

int main()
{
	int a;
	cin>>a;
	if(Prime(a))
        cout<<"\\t";
    else
        cout<<"\\n";
	return 0;
}

//function define and actualize
bool Prime(int a)
{
    if(a > 1)
    {
        int num = sqrt(a) + 1;
        for(int i=2;i<num;i++)
        {
            if (0 == a % i)
                return false;
        }
    }
    else
        return false;
    return true;
}
