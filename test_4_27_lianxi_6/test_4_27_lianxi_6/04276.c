#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//ָ��+1��������
	int* ptr1 = (int*)(&aa + 1);//&aa,�������������飬+1���ӵ���һ��������Ԫ�ش�
	int* ptr2 = (int*)(*(aa + 1));//aa����������Ԫ�ص�ַ����ά������Ԫ�������У�+1���ӵ��ڶ�����Ԫ�ص�ַ��
	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));
	system("pause");
	return 0;
}