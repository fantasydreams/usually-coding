#include <cstdio>
//仅适合一次输入一个字符，当一次输入多个字符是会出现错误
int main()
{
	char c;
	while (EOF != scanf("%c", &c))  //当按下crtl + c时，结束输入流，程序终止
	{
		printf("你输入的是%c", c);
		getchar();  //清楚输入缓冲区中的enter
	}
	return 0;
}