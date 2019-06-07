#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void swap(int*a, int*b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
	printf("a=%d,b=%d\n", *a, *b);//要不要加*,要
}

int main()
{
	int a = 0;
	int b = 0;
	printf("请输入a和b的值:\n");
	scanf("%d %d", &a, &b);
	swap(&a, &b);//何时用*？何时用&     对地址而言

	system("pause");
	return 0;
}


//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入a和b的值:\n");
//	scanf("%d %d", &a, &b);
//	int tmp = 0;
//	a = a^b;
//	b = a^b;
//	a = a^b;
//	printf("%d,%d\n", a, b);
//
//	system("pause");
//	return 0;
//}