#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//һ����16
	printf("%d\n", sizeof(a[0]+1));//��һ�У�16������һ����4
	printf("%d\n", sizeof(*(a[0]+1)));//4
	printf("%d\n", sizeof(a+1));//4
	printf("%d\n", sizeof(*(a + 1)));//4��16����
	printf("%d\n", sizeof(&a[0] + 1));//4
	printf("%d\n", sizeof(*(&a[0] + 1)));//4��16
	printf("%d\n", sizeof(*a));//4��16
	printf("%d\n", sizeof(a[3]));//һ�У�16
	system("pause");
	return 0;
}