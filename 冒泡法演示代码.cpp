/*
ð������Ļ�����ʾ
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
void SortByBubbleMethods(int *p, int num);

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
	SortByBubbleMethods(p, n);
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

//ð��������
void SortByBubbleMethods(int *p, int num)
{
	Print(p, num);
	int i = 0, j, temp;
	bool flag;
	for (; i < num - 1; i++)
	{
		printf("��%d������\n", i + 1);
		flag = false;
		for (j = 0; j < num - i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				printf("��%d��Ԫ��%d���ڵ�%d��Ԫ��%d�����н���\n", j + 1, j + 2, p[j], p[j + 1]);
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				flag = true;
				Print(p, num);
			}
			else
			{
				printf("��%d��Ԫ��%d�����ڵ�%d��Ԫ��%d�������н���\n", j + 1, j + 2, p[j], p[j + 1]);
				Print(p, num);
			}
		}
		if (false == flag)
		{
			printf("�������Ѿ�������Ҫ����������ɣ�\n");
			break;
		}
		printf("ȷ���˵�%d��Ԫ�أ�\n", num - i);
		printf("\n==================================================================\n");
	}
	printf("������ɣ�\n");
}

