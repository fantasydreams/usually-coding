#include <cstdio>
//���ʺ�һ������һ���ַ�����һ���������ַ��ǻ���ִ���
int main()
{
	char c;
	while (EOF != scanf("%c", &c))  //������crtl + cʱ��������������������ֹ
	{
		printf("���������%c", c);
		getchar();  //������뻺�����е�enter
	}
	return 0;
}