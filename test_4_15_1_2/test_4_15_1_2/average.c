#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int average(int a, int b)
{
	int num = 0;
	num = a + (b - a) / 2;
	return num;
}
int main()
{
	printf("请输入两个数：\n");
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int ret = average(a, b);
	printf("两个数的平均值是：");
	printf("%d\n", ret);
	system("pause");
	return 0;
}