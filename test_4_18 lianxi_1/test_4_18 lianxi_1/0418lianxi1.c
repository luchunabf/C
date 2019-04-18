#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	printf("%d\n", *(arr + 0));
	printf("%d\n", sizeof(arr+0));
	system("pause");
	return 0;
}