#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int count = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 10 == 0)
			count++;
		if (i / 10 == 0)
			count++;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}