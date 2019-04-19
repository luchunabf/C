#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int main()
{
	int a = 0;
	int b = 0;
	printf("请输入a和b的值：\n");
	scanf("%d %d", &a, &b);
	int ret = ((a + b) >> 1);
	for (int i = 0; i < ret; i++)
	{
		Sleep(50);
		printf("%d\n", i);
		printf("I Love Phoner forever\n");
	}
	system("pause");
	return 0;

}