#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", i);
		for (j = 0; j < 10; j++)
		{
			if (i == 0)
			{
				printf("%d ", j);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}