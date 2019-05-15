#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0, a, b, c, d, e;
	int Sn = 0;
	printf("请输入一个数字:");
	scanf("%d", &i);
	if (i >= 0 && i <= 9)
	{
		a = i;
		b = i * 10 + i;
		c = i * 100 + b;
		d = i * 1000 + c;
		e = i * 10000 + d;
		Sn = a + b + c + d + e;
		printf("%d\n", Sn);
	}
	else
		printf("error\n");


	system("pause");
	return 0;
}