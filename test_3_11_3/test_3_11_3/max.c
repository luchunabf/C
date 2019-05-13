#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int max = 0;
	int arr[10] = { 0 };
	printf("输入十个数:\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	max = arr[1];
	for (i = 1; i < 10; i++)
	{
		if (arr[i]>max)
			max = arr[i];
	}
	printf("最大的数为：");
	printf("%d\n", max);

	system("pause");
	return 0;
}