#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int sushu(int a)
{
	int i = 0;
	for (i = 2; i <= a - 1; i++)
	{
		if (a%i == 0)
			return 0;
	}
	if (a == 0 || a == 1)
			return 0;
	return 1;
}

int main()
{
	int a = 0;
	while (1)
	{
		printf("请输入要判断的值：\n");
		scanf("%d", &a);
		if (sushu(a))
			printf("该数是素数\n");
		else
			printf("该数不是素数\n");
	}
	system("pause");
	return 0;
}
