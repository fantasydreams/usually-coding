// vecters.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

typedef vector<vector <int> >Mat;
Mat Input();
void Sort(Mat &a);
void Print(Mat &a);

int _tmain(int argc, _TCHAR* argv[])
{
	//vector<int> a(10);     //������������10������Ԫ�أ�û�и���ֵ���еı��������ܻ�ʹ��ֵΪ����ģ����еĻ��Զ���ֵΪ�㡣
	//vector<int> b(10,2);   //������������10��int���͵�����Ԫ�أ���ÿ������Ԫ�ظ���ֵΪ2��
	//vector<int> a(3,2+3);  //����int��������3��Ԫ�أ���������ֵΪ5��
	//vector<int> a(b);      //����������Ϊvector<int> a(10,2);

	/*
	�������Դ��������ó�ʼֵ��
	int b[6]={1,2,3,4,5,6};
	vector <int>a(b,b+6);      ��ʾ��ȡ�������һ��Ԫ��b[]��ʼ�ĺ�6��Ԫ��
	*/  

	/*
	vector <int>b(10,1);
	vector <int>a(b.begin(),b.begin()+3);  ָ
	*/
	
	/*   �鿴����Ԫ�صĵ�һ�ַ�����
	for(vector<int>::iterator it=a.begin();it!=a.end();it++)
	{
		cout<<*it<<"  ";
	}
	*/


	/*  // �鿴����Ԫ�صĵڶ��ַ�����
	vector <int>a(10,1);
	for(int i=0;i<a.size();i++)
	{
	cout<<"vector <int>a "<<i<<"= "<<a[i]<<endl;
	}
	
	cout<<endl;
	*/
	/*
	vector <int>a(8,6);
	vector <int>b;    //��ʾ������ռ䣻
	b.assign(a.begin(),a.begin()+6);  //��a������0~5��Ԫ�ظ�ֵ��b���˾䲻��ֱ��д��b(a.begin(),a.begin()+6)��
	int y=b.front();  //��ʾ��b�����ĵ�һ��Ԫ�ظ�ֵ��y;
	int x=b.back();   //��ʾ��b���������һ��Ԫ�ظ�ֵ��x;
	cout<<"y="<<y<<" "<<"x="<<x<<endl;
	b.clear();        //��ʾ�������b������Ԫ�أ�������Ԫ�أ��� 
	if(b.empty())     //b.empty()��ʾ�ж�b�����Ƿ�Ϊ�գ�
	{
		cout<<"vector <int>b is empty!"<<endl;
	}
	a.pop_back();     //ɾ��a���������һ��Ԫ�أ�
	a.push_back(8);   //��a��������һ��Ԫ�ز���ֵΪ8��
	a.resize(10);     //��a��Ԫ�����ӵ�ʮ������ɾ�ٲ���������Ԫ��û�и�ֵ��ϵͳ�Զ���ֵΪ�㣩��
	a.resize(12,8);   //���ӵ�12��Ԫ�أ�����ֵΪ8�����ӵ�Ԫ�زŸ�ֵ����
	for(int i=0;i<a.size();i++)
	{
	cout<<"vector <int>a "<<i<<"= "<<a[i]<<endl;
	}
	if(a==b)          //����������ʽ�ж����������Ƿ���ȣ�
	{
		cout<<"equal"<<endl;
	}
	else
	{
		cout<<"not equal"<<endl;
	}
	b=a;
	for(int i=0;i<a.size();i++)
	{
	cout<<"vector <int>a "<<i<<"= "<<a[i]<<endl;
	}
	if(a==b)          //����������ʽ�ж����������Ƿ���ȣ�
	{
		cout<<"equal"<<endl;
	}
	else
	{
		cout<<"not equal"<<endl;
	}
	b.pop_back();
	b.push_back(6);
	if(a==b)          //����������ʽ�ж����������Ƿ����,���������������ͣ�Ԫ�ظ�������ӦԪ����ͬʱ������������ȣ�
	{
		cout<<"equal"<<endl;
	}
	else
	{
		cout<<"not equal"<<endl;
	}
	cout<<endl;
	*/

	/*
	ifstream in("aaa.txt");
	vector <int> s;
	vector <int> m(10,2);
	for(int a;in>>a;)
		s.push_back(a);
	//swap(s,m);     //���ڽ�����������Ԫ�أ��˾�Ҳ��д����s.swap(m);
	for(int i=0;i<s.size();i++)
	{
	cout<<"vector <int>s "<<i<<"= "<<s[i]<<endl;
	}
	for(int i=0;i<m.size();i++)
	{
	cout<<"vector <int>m "<<i<<"= "<<m[i]<<endl;
	}
	*/
	

	//��ά����(����c�еĶ�ά����);

	Mat a;
	a=Input();
	Sort(a);
	Print(a);


	system("pause");
	return 0;
}


Mat Input()
{
	Mat a;
	ifstream in("aaa.txt");  //in���Զ����ʶ��������д�������ģ������������б�ʶ����ͬ��
	for(string s;getline(in,s);)
	{
		vector <int>b;
		istringstream xin(s);  //xin Ҳ���Զ����ʶ����ͬ��in��
		for(int ia;xin>>ia;)
		{
			b.push_back(ia);
		}
		a.push_back(b);
	}
	return a;
}


void Sort(Mat &a)
{
	for(int pass=1;pass<a.size();pass++)
	{
		for(int i=0;i<a.size()-pass;i++)
		{
			if(a[i+1].size()<a[i].size())
			{
				swap(a[i],a[i+1]);
			}
		}
	}
}


void Print(Mat &a)
{
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<a[i].size();j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}