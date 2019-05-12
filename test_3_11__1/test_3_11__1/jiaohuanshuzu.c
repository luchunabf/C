#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 6, 7, 8, 9, 10 };
	int i;
	for (i = 0; i < 5; i++)   //i为什么必须从0开始，1为什么不行？
	{
		int data;
		data = a[i];
		a[i] = b[i];
		b[i] = data;
		/*printf("%d\n", a[i]);
		printf("%d", b[i]);*/
	}


	for (i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}