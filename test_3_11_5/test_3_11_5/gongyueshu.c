#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, t;
	printf("输入要求公约数的两个数：");
	scanf("%d %d", &a, &b);
	if (a < b)
	{
		t = a;
		a = b;
		b = t;
	}
	while (a%b != 0)
	{
		t = a%b;
		a = b;
		b = t;
	}
	printf("两个数的最大公约数为：%d\n", b);


	system("pause");
	return 0;
}