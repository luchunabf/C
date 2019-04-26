#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("请输入要找的数的序号N：N=:");
	int n = 0;
	scanf("%d", &n);
	int m = n - 1;//要注意滤清楚-1，非+1
	int ret = 0;
	ret = arr[m];
	printf("arr[N]=%d\n", ret);
	system("pause");
	return 0;
}