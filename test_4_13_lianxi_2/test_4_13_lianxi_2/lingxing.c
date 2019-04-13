#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int n = 0;
	printf("请输入最大行数n：");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (int j = 1; j <= (n - i); j++)
		{
			printf(" ");
		}
		for (int j = 1; j <= (2 * i - 1); j++)
		{
			printf("$");
		}
		printf("\n");
	}
	for (i = 1; i <= n-1; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf(" ");
		}
		for (int j = 1; j <= (2 * n - 1-2*i); j++)
		{
			printf("$");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}