#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int *ptr1 = (int*)(&a + 1);
	int *ptr2 = (int*)((int)a + 1);//  a[0]: 01 00 00 00  a[1]:02 00 00 00  (int)a即将数组首元素的地址a强转为整型，故+1就只+1，故输出 00 00 00 02 ，又因为小端机从低到高存放，故输出02 00 00 00.
	printf("%x,%x", ptr1[-1], *ptr2);
	system("pause");
	return 0;
}