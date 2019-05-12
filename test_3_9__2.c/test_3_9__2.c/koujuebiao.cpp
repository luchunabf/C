#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int a=1, b=1,c=0;
	for (a = 1; a <= 9; a++)
	{
		for (b = 1; b <= a; b++)
		{
			c = a*b;
			printf("%d", b);
			printf("*");
			printf("%d", a);
			printf("=");
			printf("%d ", c);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}