#include <iostream>
#include "head.h"

using namespace std;

int main()
{
	List<int> L;
	L.createList();
	L.Print();
	L.insertNode();
	L.Print();
	L.deleteNode();
	L.Print();
	L.free();
	getchar();
	getchar();
	return 0;
}