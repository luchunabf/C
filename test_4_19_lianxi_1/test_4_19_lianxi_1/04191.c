#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int ret = 1;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++)
	{
		ret *= i;
	}
	printf("%d\n",ret);
	system("pause");
	return 0;
}