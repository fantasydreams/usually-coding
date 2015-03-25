/*
选择排序的基本演示
powered by Carol (luoshengwen)
2014-12-02
此代码适用于vs2010及其以上的编译器编译使用，在vc6.0需将提示错误的函数的_s去掉即可
*/

//头文件区
#include <stdio.h>
#include <stdlib.h>

//函数声明区：

void ReadData(int *p, int num);
void Print(int *p, int num);
void SortBySelectionMethods(int *p, int num);
void notice(int *p, int i, int temp);

int main()
{
	int *p = NULL, n;    //定义指针用来指向向操作系统申请的数组；
	system("color F1");
	printf("程序按照从小到大的顺序排序...\n");
	printf("请输入需要排序数字的个数：");
	while (scanf_s("%d", &n) && n <= 0)
		printf("请输入正整数：");
	p = (int *)malloc(sizeof(int) * n);
	ReadData(p, n);		//输入数据函数调用；
	SortBySelectionMethods(p, n);
	free(p); //释放申请的内存
	system("pause");
}

//从键盘输入数据函数
void ReadData(int *p, int num)
{
	int i = 0;
	printf("请输入%d个整数，用空格或者回车隔开：", num);
	for (; i < num; i++)
		scanf_s("%d", p + i);
}

//打印数组中的数据到显示器
void Print(int *p, int num)
{
	int i = 0;
	while (num > i && printf("%6d", *(p + i++)));
	printf("\n==================================================================\n");
}

//选择排序函数
void SortBySelectionMethods(int *p, int num)
{
	Print(p, num);
	int i = 0, j, temp, TempN;//temp 变量存储较小值的下标
	for (; i < num - 1; i++)
	{
		temp = i;
		for (j = i + 1; j < num; j++)
		{
			if (p[temp] > p[j])
				temp = j;
		}
		if (temp != i)
		{
			TempN = p[i];
			p[i] = p[temp];
			p[temp] = TempN;
		}
		notice(p, i, temp);
		Print(p, num);
		printf("确定了第%d个元素！\n",i+1);
		printf("\n==================================================================\n");
	}
	printf("排序完成！\n");
}
//输出交换的情况函数
void notice(int *p, int i, int temp)
{
	printf("第%d趟排序：", i + 1);
	if (i != temp)
		printf("交换第%d与%d个元素%d与%d\n", i + 1, temp + 1, p[i], p[temp]);
	else
		printf("第%d个元素在第%d到最后一个元素中本身最小，不必交换\n", i + 1, i + 1);
}
