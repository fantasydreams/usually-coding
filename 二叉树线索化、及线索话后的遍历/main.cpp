#include <iostream>
#include "head.h"

using namespace std;

int main()
{

	//注意：此代码没有进行异常处理，也就是不能一次性加进行多次的二叉树的线索化，会导致遍历的时候死循环
	Tree tree;
	tree.Pre();
	tree.ergodicP();

	//tree.In();
	//tree.ergodicP();

//	tree.Post();
	//tree.ergodicP();

	system("pause");
	return 0;
}
