#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

int FindYs(int arr[ROW][COL], int num)
{
	int row = 0;
	int col = COL - 1;
	while (row < ROW && col >= 0)
	{
		if (num > arr[row][col])//如果大于说明这行没有，向下一行查找
		{
			row++;
		}
		else if (num < arr[row][col])//如果小于说明这列没有，向前一行查找
		{
			col--;
		}
		else if (num == arr[row][col])
		{
			return 1;//找到返回1
		}
	}
	return 0;//循环结束没有找到，返回0
}
void test()
{
	int arr[ROW][COL] =
	{
		1, 2, 3,
		4, 5, 6,
		7, 8, 9,
	};
	int ret = FindYs(arr, 5);
	if (1 == ret)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}



//自己写的
//int FindYs(int arr[ROW][COL], int num)
//{
//	int row = 0;
//	int col = 0;
//	for (row = 0; row < ROW; row++)
//	{
//		for (col = 0; col < COL; col++)
//		{
//			if (num == arr[row][col])
//				return 1;
//		}
//	}
//	return 0;
//}
//void test()
//{
//	int arr[ROW][COL] =
//	{
//		1, 2, 3,
//		4, 5, 6,
//		7, 8, 9,
//	};
//	int ret = FindYs(arr, 5);
//	if (1 == ret)
//	{
//		printf("找到了\n");
//	}
//	else
//	{
//		printf("没找到\n");
//	}
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}