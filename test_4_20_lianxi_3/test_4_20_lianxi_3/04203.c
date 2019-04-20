#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	//int arr[] = { 0 };
	//printf("%p\n", arr);//首元素地址
	//printf("%p\n", &arr);//数组地址

	int arr[10] = { 0 };
	printf("%p\n", arr);//首元素地址
	printf("%p\n", &arr);//数组地址(对数组名取地址取得是整个数组的地址)
	printf("arr+1=%p\n", arr+1);//+1
	printf("&arr+1=%p\n", &arr+1);//+40


	system("pause");
	return 0;

}