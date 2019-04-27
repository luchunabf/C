#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//指针+1，看类型
	int* ptr1 = (int*)(&aa + 1);//&aa,类型是整个数组，+1，加到下一个数组首元素处
	int* ptr2 = (int*)(*(aa + 1));//aa，类型是首元素地址，二维数组首元素是首行，+1，加到第二行首元素地址处
	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));
	system("pause");
	return 0;
}