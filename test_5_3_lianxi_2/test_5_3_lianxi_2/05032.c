#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//��ϰʹ��qsort��������������͵�����
int cmp1(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);//����
}
int cmp2(const void* a, const void* b)
{
	return (*(char*)a - *(char*)b);//�ַ�����
}
int cmp3(const void** a, const void** b)
{
	return (*(char**) a - *(char**) b);//�ַ��� return strcmp(����)
}
int cmp4(const void* a, const void* b)
{
	return ((*(double*)a - *(double*)b) > 0) ? 1 : 0;//������
}
int main()
{
	int arr[10] = { 9, 6, 4, 7, 2, 1, 8, 3, 5, 0 };
	char str[6] = { 'f', 'u', 'p', 'h', 'g', 'j' };
	//char* str1[4] = { "aaabc", "bbbngf", "hhuuyt", "llkiuy" };
	char* str1[4] = { "aaabc", "bbbngf", "hhuuyt", "llkiuy" };/////////��һ����ָ������,������char* str[4]
	//char* a="abcdef";
	//char a[]="abcdef";  ����
	//char* a[]       ָ������

	double arr1[5] = { 2.0, 4.4, 3.6, 5.5 };
	qsort(arr, 10, sizeof(int), cmp1);
	qsort(str, 6, sizeof(char), &cmp2);
	qsort(str1, 4, sizeof(char*), cmp3);
	qsort(arr1, 5, sizeof(double), cmp4);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%c ", str[i]);
	}
	printf("\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%s ", str1[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%f ", arr1[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}