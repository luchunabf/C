#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define N 10
int main()
{
	int arr[N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int start = 0;//用移动下标的方式去寻找数组中的奇偶数组
	int end = N - 1;
	while (start < end)
	{
		while ((arr[start] % 2 != 0))//找偶
		{
			start++;
		}
		while ((arr[end] % 2 == 0))//找奇
		{
			end--;
		}
		if (start < end)//在下面需要加限制条件，否则会多交换一次
		{
			int tmp = arr[start];
			arr[start] = arr[end];
			arr[end] = tmp;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}