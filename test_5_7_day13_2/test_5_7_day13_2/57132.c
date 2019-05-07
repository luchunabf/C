#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
//函数声明中的数组传值   
//一维数组传的时候：传首元素地址
//					void test(int* arr){}或者void test(int* arr[20]){}方括号[20]可有可无，数组会退化为指针。
//                  二级指针传的时候加*就行,void test(int** arr){}
//二维数组传的时候：传首行地址
//					void test(int arr[3][5]){} 或者 void test(int arr[][5]){}（行数可以省略）或者 void test(int (*arr)[5]){}（此时5表示列）
int find_num(int arr[ROW][COL], int num)//要不要*??  都可以，有不同的形式的表达式，但是传的都是首行地址
{
	int row = 0;
	int col = COL - 1;
	while (row < ROW && col > 0)
	{
		if (num > arr[row][col])
			row++;
		else if (num < arr[row][col])
			col--;
		else if (num == arr[row][col])
			return 1;
	}
	return  0;
}
int main()
{
	int arr[ROW][COL] =
	{
		1, 2, 3,
		2, 3, 4,
		3, 4, 5
	};
	int ret = find_num(arr, 5);
	if (ret == 1)
		printf("找到了\n");
	else
		printf("找不到\n");
	system("pause");
	return 0;
}