/*
ѡ������Ļ�����ʾ
powered by Carol (luoshengwen)
2014-12-02
�˴���������vs2010�������ϵı���������ʹ�ã���vc6.0�轫��ʾ����ĺ�����_sȥ������
*/

//ͷ�ļ���
#include <stdio.h>
#include <stdlib.h>

//������������

void ReadData(int *p, int num);
void Print(int *p, int num);
void SortBySelectionMethods(int *p, int num);
void notice(int *p, int i, int temp);

int main()
{
	int *p = NULL, n;    //����ָ������ָ�������ϵͳ��������飻
	system("color F1");
	printf("�����մ�С�����˳������...\n");
	printf("��������Ҫ�������ֵĸ�����");
	while (scanf_s("%d", &n) && n <= 0)
		printf("��������������");
	p = (int *)malloc(sizeof(int) * n);
	ReadData(p, n);		//�������ݺ������ã�
	SortBySelectionMethods(p, n);
	free(p); //�ͷ�������ڴ�
	system("pause");
}

//�Ӽ����������ݺ���
void ReadData(int *p, int num)
{
	int i = 0;
	printf("������%d���������ÿո���߻س�������", num);
	for (; i < num; i++)
		scanf_s("%d", p + i);
}

//��ӡ�����е����ݵ���ʾ��
void Print(int *p, int num)
{
	int i = 0;
	while (num > i && printf("%6d", *(p + i++)));
	printf("\n==================================================================\n");
}

//ѡ��������
void SortBySelectionMethods(int *p, int num)
{
	Print(p, num);
	int i = 0, j, temp, TempN;//temp �����洢��Сֵ���±�
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
		printf("ȷ���˵�%d��Ԫ�أ�\n",i+1);
		printf("\n==================================================================\n");
	}
	printf("������ɣ�\n");
}
//����������������
void notice(int *p, int i, int temp)
{
	printf("��%d������", i + 1);
	if (i != temp)
		printf("������%d��%d��Ԫ��%d��%d\n", i + 1, temp + 1, p[i], p[temp]);
	else
		printf("��%d��Ԫ���ڵ�%d�����һ��Ԫ���б�����С�����ؽ���\n", i + 1, i + 1);
}
