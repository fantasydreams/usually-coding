/*
冒泡排序的基本演示
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
void SortByBubbleMethods(int *p, int num);

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
	SortByBubbleMethods(p, n);
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

//冒泡排序函数
void SortByBubbleMethods(int *p, int num)
{
	Print(p, num);
	int i = 0, j, temp;
	bool flag;
	for (; i < num - 1; i++)
	{
		printf("第%d趟排序：\n", i + 1);
		flag = false;
		for (j = 0; j < num - i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				printf("第%d个元素%d大于第%d个元素%d，进行交换\n", j + 1, j + 2, p[j], p[j + 1]);
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				flag = true;
				Print(p, num);
			}
			else
			{
				printf("第%d个元素%d不大于第%d个元素%d，不进行交换\n", j + 1, j + 2, p[j], p[j + 1]);
				Print(p, num);
			}
		}
		if (false == flag)
		{
			printf("此序列已经不再需要排序，排序完成！\n");
			break;
		}
		printf("确定了第%d个元素！\n", num - i);
		printf("\n==================================================================\n");
	}
	printf("排序完成！\n");
}

