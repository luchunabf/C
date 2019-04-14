#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	double a = 0.000000000;
	double* p = &a;
	printf("%p\n", p);
	printf("%lf\n", *p);
	system("pause");
	return 0;
}