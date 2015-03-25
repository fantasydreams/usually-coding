#include <iostream>

#define Max_Len 100
int Flag = -1;

using namespace std;

//������������
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

//��ȫA���������뺯��
void InputEleme(char Tree[])
{
	cout << "���Դΰ��ն�����һ��������....��Ԫ�ؽ�������(��*�Ž���)��" << endl;
	int i = 0;
	char elem;
	while (i < Max_Len && cin >> elem && elem != '*')
		Tree[i++] = elem;
	Flag = i - 1;
}

/*
//�������Ԫ�أ�����ʱʹ�ã�
void Print(char * Tree)
{
	int i = 0;
	while (i < Max_Len && Tree[i])
		cout << Tree[i++];
}
*/


//����������������
void PreOrderTraverse(char * Tree)
{
	cout << "�������" << endl;
	if (Flag >= 0)
		cout<< Tree[0];
	PrePrintLefTree(Tree,1);  //����������
	PrePrintLefTree(Tree, 2);  //����������
	
}


//�������������
void PrePrintLefTree(char * Tree,int i)
{
	if (i <= Flag)
	{
		cout << Tree[i];
		PrePrintLefTree(Tree, 2 * (i + 1) - 1);  //��������
		PrePrintLefTree(Tree, 2 * (i + 1));   //�����Һ���
	}
}


//����������������
void InOrderTraverse(char * Tree)
{
	cout << "�������" << endl;
	InPrintLefTree(Tree, 1);  //����������
	if (Flag >= 0)
		cout << Tree[0];  //��������
	InPrintLefTree(Tree, 2);  //����������
}


//�������������
void InPrintLefTree(char * Tree, int i)
{
	if (i <= Flag)
	{
		InPrintLefTree(Tree, 2 * (i + 1) - 1);  //��������
		cout << Tree[i];
		InPrintLefTree(Tree, 2 * (i + 1));   //�����Һ���
	}
}

//����������������
void PostOrderTraverse(char * Tree)
{
	cout << "�������" << endl;
	PostPrintLefTree(Tree, 1);  //����������
	PostPrintLefTree(Tree, 2);  //����������
	if (Flag >= 0)
		cout << Tree[0];  //��������
}


//�������������
void PostPrintLefTree(char * Tree, int i)
{
	if (i <= Flag)
	{
		PostPrintLefTree(Tree, 2 * (i + 1) - 1);  //��������
		PostPrintLefTree(Tree, 2 * (i + 1));   //�����Һ���
		cout << Tree[i];
	}
}