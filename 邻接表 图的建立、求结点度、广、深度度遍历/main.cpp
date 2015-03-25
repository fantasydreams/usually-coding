#include <iostream>
#include "head.h"
#include "head.h"
#include <vector>


using namespace std;

int main()
{
	Graph<int> G;
	G.CreateGraph();
	G.PrintGraph();
	G.CalDegree();
	G.DFSTraverse();
	std::cout << std::endl;
	G.BFSTraverse();
	std::cout << std::endl;
	system("pause");
	return 0;
}