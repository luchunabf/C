#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int b = 0;
	printf("������a��b��ֵ��\n");
	scanf("%d %d", &a, &b);
	int ret = ((a+b)>>1);
	printf("%d\n", ret);
	system("pause");
	return 0;

}
