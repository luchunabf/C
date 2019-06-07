#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void kjb(int m)
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <=i ; j++)
			printf("%d*%d=%-5d", i, j, i*j);
		printf("\n");
	}
}



int main()
{
	int m = 0;
	printf("ÇëÊäÈëÐÐÊý£º\n");
	scanf("%d", &m);
	kjb(m);

	system("pause");
	return 0;
}