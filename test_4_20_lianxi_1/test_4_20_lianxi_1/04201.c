#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));/////////////sizeof ����������͵Ĵ�С
	printf("%d\n", sizeof(a+0));
	printf("%d\n", sizeof(a + 1));
	printf("%d\n", sizeof(a[0]));
	printf("%d\n", sizeof(a[1]));
	printf("%d\n", sizeof(*&a));//////����ĵ�ַ ������ �����������飬������16
	printf("%d\n", sizeof(&a));
	printf("%d\n", sizeof(&a+1));
	printf("%d\n", sizeof(&a[0]));
	printf("%d\n", sizeof(&a[0]+1));



	/*char b[] = "abc";
	printf("%d\n", sizeof(b[0]));
	printf("%d\n", sizeof(b+0));

	printf("%d\n", sizeof(b[1]));
	printf("%d\n", sizeof(b+1));*/



	system("pause");
	return 0;
}