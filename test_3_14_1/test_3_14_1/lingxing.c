#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0, j = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	for (i = 1; i <= 7; i++)
	{

		{
			j = (i * 2 - 1);
			d = 6 - ((j - 1) / 2);
			for (c=1 ; c <=d; c++)
				printf(" ");
		    for (a = 1; a <= j; a++)
			printf("*"); 
		}
		printf("\n");
	}
	int l = 13;
	for (i = 8; i <= 13; i++)
	{
		{
			l = l - 2;
			f = 6 - ((l - 1) / 2);
			for (e = 1; e <= f; e++)
				printf(" ");
			for (b = 1; b <= l; b++)
				printf("*"); 
		}
		printf("\n");
	}
		system("pause");
	return 0;
}