#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10] = { 0 };
	printf("arr = %p\n", arr);//����������Ԫ�����ֽڵ�ַ
	printf("&arr = %p\n", &arr);//��������ĵ�ַ
	printf("\n");
	printf("arr+1 = %p\n", arr + 1);//arr + 4
	printf("&arr+1 = %p\n", &arr + 1);//&arr + 40
	system("pause");
	return 0;

}