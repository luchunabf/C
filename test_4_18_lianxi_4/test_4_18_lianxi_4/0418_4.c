#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	void swap(int x, int y);
//	int a = 10;
//	int b = 20;
//	printf("a=%d,b=%d\n", a, b);
//	swap(a, b);
//	printf("a=%d,b=%d\n", a, b);
//	system("pause");
//	return 0;
//}
//void swap(int x, int y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
int main()
{
	void swap(int* x, int* y);//声明
	int a = 10;
	int b = 20;
	printf("a=%d,b=%d\n", a, b);
	swap(&a, &b);
	printf("a=%d,b=%d\n", a, b);
	system("pause");
	return 0;
}
void swap(int* x, int* y)
{
	int tmp = *x;//tmp前不能加*
	*x = *y;
	*y = tmp;
}