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

	cout << "ջ��" << endl;

	cout << s.OutStack() << "	";
	cout << s.OutStack() << "	";
	cout << s.OutStack() << "	";
	//cout << s.OutStack() << "	";
	cout << s.OutStack() << endl;

	//Ϊʲô������������д��ʽ�����˳��ȴ���෴�ģ�
	/*
	cout << s.OutStack() << "	"
	<< s.OutStack() << "	"
	<< s.OutStack() << "	"
	<< s.OutStack() << "	"
	<< s.OutStack() << endl;
	*/

	cout << "======================================================" << endl
		<< "����:"
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

	//�������Ҳ��������˳���෴
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