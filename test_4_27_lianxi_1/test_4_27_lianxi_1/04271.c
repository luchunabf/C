#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int *ptr = (int*)(&a + 1);//(&a+1)取得是整个数组的地址，+1是指下一个同样大小的数组（首元素的地址），所以类型是数组指针
	printf("%d,%d\n", *(a + 1), *(ptr - 1));
	system("pause");
	return 0;
}