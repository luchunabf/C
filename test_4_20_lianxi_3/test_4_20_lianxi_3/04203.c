#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	//int arr[] = { 0 };
	//printf("%p\n", arr);//��Ԫ�ص�ַ
	//printf("%p\n", &arr);//�����ַ

	int arr[10] = { 0 };
	printf("%p\n", arr);//��Ԫ�ص�ַ
	printf("%p\n", &arr);//�����ַ(��������ȡ��ַȡ������������ĵ�ַ)
	printf("arr+1=%p\n", arr+1);//+1
	printf("&arr+1=%p\n", &arr+1);//+40


	system("pause");
	return 0;

}