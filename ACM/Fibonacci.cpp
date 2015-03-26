#include <iostream>
#include <cmath>

using namespace std;


//Prime function declare
int Fibonacci(int a);

int main()
{
	int a;
	cin>>a;
	cout<<Fibonacci(a);
	return 0;
}

//function define and actualize
int Fibonacci(int a)
{
    if(a>=1)
    {
        int f1= 1,f2=1;
        if (1==a || 2==a)
            return f1;
        int num ;
        if(a%2)
            num = a/2;
        else
            num = a/2 -1;
        for(int i=0;i<num;i++)
        {
            f1+=f2;
            f2+=f1;
        }
        if(a%2)
            return f1;
        else
            return f2;
    }
}
