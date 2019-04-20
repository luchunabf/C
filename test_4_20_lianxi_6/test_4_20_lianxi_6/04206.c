#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[2][3] = { 1, 2, 3, 4, 5 ,6};
	printf("%d\n", arr[0][1]);
	printf("%d\n", sizeof(arr[0]));//首行元素的字节
	printf("%d\n", sizeof(arr[0]+1));//指针
	char arr1[2][3] = { 1, 2, 3, 4, 5, 6 };
	printf("%d\n", arr1[0][1]);
	printf("%d\n", sizeof(arr1[0]));//首行元素的字节
	printf("%d\n", sizeof(arr1[0] + 1));//指针
	system("pause");
	return 0;
}