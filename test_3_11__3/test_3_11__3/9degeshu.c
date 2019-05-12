#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 1, b = 0, c = 0;
	int i = 0, j = 0;
	while (a <= 100)
	{
		b = (a - 9) % 10;
		a = a + 1;
		if (b == 0)
			i++;
	}
	for (a = 1; a <= 100; a++)
	{
		c = a / 10;
		if (c == 9)
			j++;
	}
	printf("%d\n", i+j);
	system("pause");
	return 0;
}