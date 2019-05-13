#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 1, b = 2, c;
	c = a;
	a = b;
	b = c;
	printf("%d%d\n", a, b);
	system("pause");
	return 0;
}