// vecters.cpp : 定义控制台应用程序的入口点。
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
	//vector<int> a(10);     //此向量定义了10个向量元素，没有付初值，有的编译器可能会使其值为随机的，但有的会自动赋值为零。
	//vector<int> b(10,2);   //此向量定义了10个int类型的向量元素，并每个向量元素赋初值为2；
	//vector<int> a(3,2+3);  //定义int类型向量3个元素，并都赋初值为5；
	//vector<int> a(b);      //此向量解释为vector<int> a(10,2);

	/*
	向量可以从数组里获得初始值：
	int b[6]={1,2,3,4,5,6};
	vector <int>a(b,b+6);      表示获取从数组第一个元素b[]开始的后6个元素
	*/  

	/*
	vector <int>b(10,1);
	vector <int>a(b.begin(),b.begin()+3);  指
	*/
	
	/*   查看向量元素的第一种方法；
	for(vector<int>::iterator it=a.begin();it!=a.end();it++)
	{
		cout<<*it<<"  ";
	}
	*/


	/*  // 查看向量元素的第二种方法；
	vector <int>a(10,1);
	for(int i=0;i<a.size();i++)
	{
	cout<<"vector <int>a "<<i<<"= "<<a[i]<<endl;
	}
	
	cout<<endl;
	*/
	/*
	vector <int>a(8,6);
	vector <int>b;    //表示不分配空间；
	b.assign(a.begin(),a.begin()+6);  //把a向量的0~5个元素赋值给b，此句不能直接写作b(a.begin(),a.begin()+6)；
	int y=b.front();  //表示将b向量的第一个元素赋值给y;
	int x=b.back();   //表示将b向量的最后一个元素赋值给x;
	cout<<"y="<<y<<" "<<"x="<<x<<endl;
	b.clear();        //表示清空向量b中所有元素（不在有元素）； 
	if(b.empty())     //b.empty()表示判断b向量是否为空；
	{
		cout<<"vector <int>b is empty!"<<endl;
	}
	a.pop_back();     //删除a向量的最后一个元素；
	a.push_back(8);   //在a向量最后加一个元素并赋值为8；
	a.resize(10);     //将a的元素增加到十个（多删少补）（增的元素没有赋值，系统自动赋值为零）；
	a.resize(12,8);   //增加到12个元素，并赋值为8（增加的元素才赋值）；
	for(int i=0;i<a.size();i++)
	{
	cout<<"vector <int>a "<<i<<"= "<<a[i]<<endl;
	}
	if(a==b)          //多用这种形式判断两个向量是否相等；
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
	if(a==b)          //多用这种形式判断两个向量是否相等；
	{
		cout<<"equal"<<endl;
	}
	else
	{
		cout<<"not equal"<<endl;
	}
	b.pop_back();
	b.push_back(6);
	if(a==b)          //多用这种形式判断两个向量是否相等,当两个向量的类型，元素个数及对应元素相同时，两项量才想等；
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
	//swap(s,m);     //用于交换两向量的元素，此句也可写作：s.swap(m);
	for(int i=0;i<s.size();i++)
	{
	cout<<"vector <int>s "<<i<<"= "<<s[i]<<endl;
	}
	for(int i=0;i<m.size();i++)
	{
	cout<<"vector <int>m "<<i<<"= "<<m[i]<<endl;
	}
	*/
	

	//二维向量(类似c中的二维数组);

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
	ifstream in("aaa.txt");  //in是自定义标识符，可以写作其他的，但不能与现有标识符相同；
	for(string s;getline(in,s);)
	{
		vector <int>b;
		istringstream xin(s);  //xin 也是自定义标识符，同上in；
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