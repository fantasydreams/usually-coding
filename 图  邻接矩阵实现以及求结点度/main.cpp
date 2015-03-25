#include <iostream>
#include "head.h"

using namespace std;

int main()
{
	Graph<int> G;
	if (G.CreateVectorGraph())
	{
		G.CalDegree();
		G.print();
		G.DFSTraverse();
		cout << endl;
		G.BFSTraverse();
		cout << endl;
	}
	system("pause");
	return 0;
}