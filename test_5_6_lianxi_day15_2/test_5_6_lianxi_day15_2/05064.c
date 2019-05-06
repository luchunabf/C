#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 20;
	int x = a / 2;
	int y = a % 2;
	int z = x + y;
	int b = a + x;
	while (z >= 2)
	{
		x = z / 2;
		y = z % 2;
		z = x + y;
		b = b + x;
	}
	printf("%d\n", b);
	system("pause");
	return 0;
}