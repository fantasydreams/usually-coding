#include <iostream>
#include "head.h"

using namespace std;

int main()
{
	Tree a;
	a.PreOrderTraverse();
	a.InorderTraverse();
	a.PostOrderTraverse();
	a.Gradation();
	a.Treedegree();
	cout << endl;
	system("pause");
	return 0;
}
