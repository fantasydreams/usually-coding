// 指针.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	/*
	float f=34.5;
	int *ip=reinterpret_cast<int *>(&f);   //重解释转换（类似c中的强制转换）；装换后，原来的没有产生变化；
	int *ip1=static_cast<int *>(ip);       //静态转换；
	//int *ip2=dynamic_cast<void *>(ip);
	int *cp=reinterpret_cast<int *>(123456);
	cout<<"float address:"<<&f<<"=>"<<f<<endl;
	cout<<"int address:"<<ip<<"=>"<<*ip<<endl;
	cout<<"ip1:"<<ip1<<"=>"<<*ip1<<endl;
	cout<<"cp address:"<<cp<<"=>"<<*cp<<endl;
	*/
	
	/*
	const int a=56;   //定义的一个常量a，赋值过后值在程序结束前不能被改变；
	int b=78;         //b是一个变量，之后可以改变b的值；
	int c=58;
	const int * ip=&a;//const修饰指向的实体类型——常量指针（指向常量的指针）；
	int const * ip1=&b;//const修饰指针*ip1——指针常量（相对指针变量而言，就是指针值不能修改的指针）；
	int * const ip2=&b;//等价于上一句，指针常量（记忆：指针是常量）；
	const int * const ip3=&c;//常量指针常量；
	*/  

	/*
	int a=56;
	int *ip=&a;
	*ip=58;
	cout<<*ip<<endl;
	*/

	/*
	注：
	常量指针：指针值可以修改，但是不能通过指针来更改指针指向的值；
	指针常量：指针值不能修改，但可以通过指针修改指针指向的值；
	常量指针常量：指针值不能修改，也不能通过指针修改指针指向的值；
	*/
	system("pause");
	return 0;
}

