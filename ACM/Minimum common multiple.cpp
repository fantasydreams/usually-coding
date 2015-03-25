#include <iostream>

using namespace std;

#define error 0

//MCM function declare(this function to calculate two interger's Minimum commom multiple)
int MCM(int a,int b);

int main()
{
	int a,b;
	cin >>a>>b;
	if(a>0 && b>0)   //sure two integer greater than 0
        cout << MCM(a,b);   //output Minimum commom multiple(function call)
	return 0;
}

//function define and actualize
int MCM(int a,int b)
{
    if(a>0 && b >0)
    {
        long count = a * b;
        int temp = a % b;
        while(temp)
        {
            a = b;
            b = temp;
            temp = a%b;
        }
        return count/b;  //return Minimum common multiple
        //return b;  // Maximum common devisor
    }else
    return error;
}
