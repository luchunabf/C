#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10] = { 0 };
	printf("arr = %p\n", arr);//数组名，首元素首字节地址
	printf("&arr = %p\n", &arr);//整个数组的地址
	printf("\n");
	printf("arr+1 = %p\n", arr + 1);//arr + 4
	printf("&arr+1 = %p\n", &arr + 1);//&arr + 40
	system("pause");
	return 0;

}