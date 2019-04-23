#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define N 5
int main()
{
	int arr[N] = { 0 };
	printf("请输入五个数字（只有一个数字出现一次，其他数字均出现两次的数组，用回车隔开）\n");
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);//N个数用回车键隔开
	}
	//int arr[N] = { 1, 2, 3, 2, 1 };
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		ret ^= arr[i];
	}
	printf("单个数字是：%d\n", ret);
	system("pause");
	return 0;
}