#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d", i);

		for (int j = 0; j < 5; j++)
		{
			printf("%d",j);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}