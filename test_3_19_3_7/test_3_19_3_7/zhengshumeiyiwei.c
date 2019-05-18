#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void f(int n)
{
	if (n < 10)
		printf("%d ",n);
	else
	{
		f(n / 10);
		printf("%d ", n % 10);
	}
}

int main()
{
	int n = 0;
	printf("ÇëÊäÈënµÄÖµ£º\n");
	scanf("%d", &n);
	f(n);
	printf("\n");
	system("pause");
	return 0;
}