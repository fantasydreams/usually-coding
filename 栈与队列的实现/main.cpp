#include <iostream>
#include "head.h"

using namespace std;

int main()
{
	stack<int> s;
	s.InStack(200);
	s.InStack(123);
	s.InStack(200);
	s.InStack(500);
	s.InStack(600);

	cout << "栈：" << endl;

	cout << s.OutStack() << "	";
	cout << s.OutStack() << "	";
	cout << s.OutStack() << "	";
	//cout << s.OutStack() << "	";
	cout << s.OutStack() << endl;

	//为什么用下面这种书写方式输出的顺序却是相反的？
	/*
	cout << s.OutStack() << "	"
	<< s.OutStack() << "	"
	<< s.OutStack() << "	"
	<< s.OutStack() << "	"
	<< s.OutStack() << endl;
	*/

	cout << "======================================================" << endl
		<< "队列:"
		<< endl;

	Queue<int> Q;
	Q.InQueue(200);
	Q.InQueue(123);
	Q.InQueue(200);
	Q.InQueue(500);
	Q.InQueue(600);

	cout << Q.OutQueue() << "	";
	cout << Q.OutQueue() << "	";
	cout << Q.OutQueue() << "	";
	//cout << Q.OutQueue() << "	";
	cout << Q.OutQueue() << endl;

	//下面输出也是与理想顺序相反
	/*
	cout << Q.OutQueue() << "	"
	<< Q.OutQueue() << "	"
	<< Q.OutQueue() << "	"
	<< Q.OutQueue() << "	"
	<< Q.OutQueue() << endl;
	*/
	getchar();
	return 0;
}