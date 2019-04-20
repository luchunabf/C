#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));/////////////sizeof 计算的是类型的大小
	printf("%d\n", sizeof(a+0));
	printf("%d\n", sizeof(a + 1));
	printf("%d\n", sizeof(a[0]));
	printf("%d\n", sizeof(a[1]));
	printf("%d\n", sizeof(*&a));//////数组的地址 解引用 还是整个数组，所以是16
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