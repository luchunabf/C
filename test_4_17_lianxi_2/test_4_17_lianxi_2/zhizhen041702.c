#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr));//6
	printf("%d\n", sizeof(arr+0));//1¸Ä4
	printf("%d\n", sizeof(*arr));//1
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4
	printf("%d\n", sizeof(&arr+1));//4
	printf("%d\n", sizeof(&arr[0]+1));//4
	printf("\n");
	//printf("%d\n", strlen(arr));//
	//printf("%d\n", strlen(arr + 0));//
	//printf("%d\n", strlen(*arr));//
	//printf("%d\n", strlen(arr[1]));//
	//printf("%d\n", strlen(&arr));//
	//printf("%d\n", strlen(&arr + 1));//
	//printf("%d\n", strlen(&arr[0] + 1));//

	system("pause");
	return 0;
}