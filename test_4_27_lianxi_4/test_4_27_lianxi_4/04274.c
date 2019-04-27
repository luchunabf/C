#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };//逗号表达式中的值是最后一个逗号后面的值，即a[3][2]={1,3,5}
	int* p;
	p = a[0];//二维数组a[0]代表首行的数组名
	printf("%d\n", p[0]);//p[0]即(*(p+0)) 从p往后走0个类型大小(int*)
	printf("%d\n", p[1]);//p[1]即(*(p+1)) 从p往后走1个类型大小(int*)
	printf("%d\n", p[2]);//p[2]即(*(p+2)) 从p往后走2个类型大小(int*)
	system("pause");
	return 0;
}