#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void printInt(int a)
{
	if (a > 9)
		printInt(a / 10);
	printf("%d ", a % 10);
}
int main()
{
	int n;
	printf("请输入n：");
	scanf("%d", &n);
	printf("该整数的每一位是：\n");
	printInt(n);
	printf("\n");
	system("pause");
	return 0;
}