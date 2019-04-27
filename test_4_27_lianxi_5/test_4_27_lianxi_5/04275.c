#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[5][5];
	int(*p)[4];//数组指针，数组列为4，行视情况往后补
	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//18-22=-4   (-4)的地址是FF FF FF FC   (-1)的地址十六进制全为F：FF FF FF FF
	system("pause");
	return 0;
}