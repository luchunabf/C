#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	for (; i < 3; i++)//三个“三个正方形矩阵，没在同一水平线”（由循环最里层往外理解容易解读）
	{
		for (int j = 0; j < 3; j++)//三个正方形矩阵，没在同一水平线
		{
			for (int z = 0; z < 3; z++)//最里面的两层循环输出正方形矩阵，然后增加循环即增加维度
			{
				for (int l = 0; l < 3; l++)//最里面的两层循环输出正方形矩阵，然后增加循环即增加维度
				{
					printf("#");
					/*printf("\n");*/
				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");

	}

	system("pause");
	return 0;
}