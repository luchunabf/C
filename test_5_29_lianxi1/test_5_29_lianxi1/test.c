#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int less(int a, int b)
{
	return a < b;
}

int main()
{
	int a = 3;
	int b = 2;
	int ret = less(a, b);
	printf("%d\n", ret);
	system("pause");
	return 0;

}