#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	for (; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int z = 0; z < 5; z++)
			{
				printf("#");
				printf("\n");

			}
			printf("\n");
		}
		printf("\n");

	}

	system("pause");
	return 0;
}