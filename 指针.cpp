// ָ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	/*
	float f=34.5;
	int *ip=reinterpret_cast<int *>(&f);   //�ؽ���ת��������c�е�ǿ��ת������װ����ԭ����û�в����仯��
	int *ip1=static_cast<int *>(ip);       //��̬ת����
	//int *ip2=dynamic_cast<void *>(ip);
	int *cp=reinterpret_cast<int *>(123456);
	cout<<"float address:"<<&f<<"=>"<<f<<endl;
	cout<<"int address:"<<ip<<"=>"<<*ip<<endl;
	cout<<"ip1:"<<ip1<<"=>"<<*ip1<<endl;
	cout<<"cp address:"<<cp<<"=>"<<*cp<<endl;
	*/
	
	/*
	const int a=56;   //�����һ������a����ֵ����ֵ�ڳ������ǰ���ܱ��ı䣻
	int b=78;         //b��һ��������֮����Ըı�b��ֵ��
	int c=58;
	const int * ip=&a;//const����ָ���ʵ�����͡�������ָ�루ָ������ָ�룩��
	int const * ip1=&b;//const����ָ��*ip1����ָ�볣�������ָ��������ԣ�����ָ��ֵ�����޸ĵ�ָ�룩��
	int * const ip2=&b;//�ȼ�����һ�䣬ָ�볣�������䣺ָ���ǳ�������
	const int * const ip3=&c;//����ָ�볣����
	*/  

	/*
	int a=56;
	int *ip=&a;
	*ip=58;
	cout<<*ip<<endl;
	*/

	/*
	ע��
	����ָ�룺ָ��ֵ�����޸ģ����ǲ���ͨ��ָ��������ָ��ָ���ֵ��
	ָ�볣����ָ��ֵ�����޸ģ�������ͨ��ָ���޸�ָ��ָ���ֵ��
	����ָ�볣����ָ��ֵ�����޸ģ�Ҳ����ͨ��ָ���޸�ָ��ָ���ֵ��
	*/
	system("pause");
	return 0;
}

