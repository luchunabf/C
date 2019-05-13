#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b, c;
	printf("请输入三个数： ");
	scanf("%d %d %d", &a, &b, &c);
	if (a > b)
	{
		if (b > c)
			printf("%d %d %d", a, b, c);
		else if (a > c)
			printf("%d %d %d", a, c, b);
		else
			printf("%d %d %d", c, a, b);
			
	}
	else//a<b
	if (b < c)
		printf("%d %d %d", c, b, a);
	else if (a < c)
		printf("%d %d %d", b, c, a);
	else
		printf("%d %d %d", b, a, c);
	system("pause");
	return 0;
}