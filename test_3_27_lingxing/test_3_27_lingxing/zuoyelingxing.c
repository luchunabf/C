#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int maxline;
	int m, n,a;
	printf("请输入最大行：\n");
	scanf("%d", &maxline);

	for (int i = 0; i < maxline; i++)
	{
		m = (2*maxline - 1) / 2 - i;
		for (int j = 1; j <= m; j++)
		{
			printf(" ");
		}
		n = (2*i + 1);
		for (int k = 1; k <= n; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 1; i <= maxline-1; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf(" ");
		}
		a = (2*maxline-1)-(2*i);
		for (int k = 1; k <= a; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	system("pause");
	return 0;
}