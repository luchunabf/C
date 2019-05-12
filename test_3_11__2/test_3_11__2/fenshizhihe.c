#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int sign = 1;
	double sum = 1;
	double deno;
	double term;
	int i=0;
	for (i = 0; i < 99;i++)
	{
		deno = i + 2;
		sign = sign*(-1);
		term = sign*(1 / deno);
		sum = sum + term;
		
	}
	printf("%f\n", sum);
	system("pause");
	return 0;
}