#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int a = 10;
//	int b = 30;
//	int m = a&b;//a和b二进制中相同的位数
//	int n = a^b;//a和b二进制中不同的位数
//	int average = m + n/2;
//	printf("%d\n", average);
//	system("pause");
//	return 0;
//}

int main()
{
	int a = 10;
	int b = 30;
	
	int average = a+((b-a)>>1);//（二进制位）右移一位相当于除以2
	printf("%d\n", average);
	system("pause");
	return 0;
}
