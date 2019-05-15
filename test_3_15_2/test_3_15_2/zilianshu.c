#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0, a, b, c;
	for (i = 0; i <1000; i++)
	{
		a = i / 100;
		b = (i % 100) / 10;
		c = i % 10;
		if (i == (a*a*a) + (b*b*b) + (c*c*c))
			printf("%d ", i);
		
	}
	system("pause");
	return 0;
}