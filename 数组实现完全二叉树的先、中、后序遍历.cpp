#include <iostream>

#define Max_Len 100
int Flag = -1;

using namespace std;

//函数声明区：
void InputEleme(char Tree[]);
void PreOrderTraverse(char *);
void PrePrintLefTree(char * Tree, int i);
void InOrderTraverse(char * Tree);
void InPrintLefTree(char * Tree, int i);
void PostOrderTraverse(char * Tree);
void PostPrintLefTree(char * Tree, int i);
//void Print(char * Tree);

int main()
{
	char Tree[Max_Len] = {0};
	InputEleme(Tree);
	PreOrderTraverse(Tree);
	cout << endl;
	InOrderTraverse(Tree);
	cout << endl;
	PostOrderTraverse(Tree);
	cout<<endl;
	//Print(Tree);
	system("pause");
	return 0;
}

//完全A二叉树输入函数
void InputEleme(char Tree[])
{
	cout << "请以次按照二叉树一、二、三....层元素进行输入(按*号结束)：" << endl;
	int i = 0;
	char elem;
	while (i < Max_Len && cin >> elem && elem != '*')
		Tree[i++] = elem;
	Flag = i - 1;
}

/*
//输出数组元素（调试时使用）
void Print(char * Tree)
{
	int i = 0;
	while (i < Max_Len && Tree[i])
		cout << Tree[i++];
}
*/


//先序遍历输出二叉树
void PreOrderTraverse(char * Tree)
{
	cout << "先序遍历" << endl;
	if (Flag >= 0)
		cout<< Tree[0];
	PrePrintLefTree(Tree,1);  //遍历左子树
	PrePrintLefTree(Tree, 2);  //遍历右子树
	
}


//先序输出左子树
void PrePrintLefTree(char * Tree,int i)
{
	if (i <= Flag)
	{
		cout << Tree[i];
		PrePrintLefTree(Tree, 2 * (i + 1) - 1);  //遍历左孩子
		PrePrintLefTree(Tree, 2 * (i + 1));   //遍历右孩子
	}
}


//中序遍历输出二叉树
void InOrderTraverse(char * Tree)
{
	cout << "中序遍历" << endl;
	InPrintLefTree(Tree, 1);  //遍历左子树
	if (Flag >= 0)
		cout << Tree[0];  //输出根结点
	InPrintLefTree(Tree, 2);  //遍历右子树
}


//中序输出左子树
void InPrintLefTree(char * Tree, int i)
{
	if (i <= Flag)
	{
		InPrintLefTree(Tree, 2 * (i + 1) - 1);  //遍历左孩子
		cout << Tree[i];
		InPrintLefTree(Tree, 2 * (i + 1));   //遍历右孩子
	}
}

//后序遍历输出二叉树
void PostOrderTraverse(char * Tree)
{
	cout << "后序遍历" << endl;
	PostPrintLefTree(Tree, 1);  //遍历左子树
	PostPrintLefTree(Tree, 2);  //遍历右子树
	if (Flag >= 0)
		cout << Tree[0];  //输出根结点
}


//后序输出左子树
void PostPrintLefTree(char * Tree, int i)
{
	if (i <= Flag)
	{
		PostPrintLefTree(Tree, 2 * (i + 1) - 1);  //遍历左孩子
		PostPrintLefTree(Tree, 2 * (i + 1));   //遍历右孩子
		cout << Tree[i];
	}
}