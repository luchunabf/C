#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int *ptr = (int*)(&a + 1);//(&a+1)ȡ������������ĵ�ַ��+1��ָ��һ��ͬ����С�����飨��Ԫ�صĵ�ַ������������������ָ��
	printf("%d,%d\n", *(a + 1), *(ptr - 1));
	system("pause");
	return 0;
}