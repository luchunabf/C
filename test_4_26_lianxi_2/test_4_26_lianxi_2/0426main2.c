#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("������Ҫ�ҵ��������N��N=:");
	int n = 0;
	scanf("%d", &n);
	int m = n - 1;//Ҫע�������-1����+1
	int ret = 0;
	ret = arr[m];
	printf("arr[N]=%d\n", ret);
	system("pause");
	return 0;
}