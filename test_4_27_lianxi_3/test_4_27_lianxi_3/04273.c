#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int *ptr1 = (int*)(&a + 1);
	int *ptr2 = (int*)((int)a + 1);//  a[0]: 01 00 00 00  a[1]:02 00 00 00  (int)a����������Ԫ�صĵ�ַaǿתΪ���ͣ���+1��ֻ+1������� 00 00 00 02 ������ΪС�˻��ӵ͵��ߴ�ţ������02 00 00 00.
	printf("%x,%x", ptr1[-1], *ptr2);
	system("pause");
	return 0;
}