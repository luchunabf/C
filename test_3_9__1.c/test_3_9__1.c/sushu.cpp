#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int a, b, c, d = 0;
	for (a = 101; a <= 200; a=a+2 )
	{
		b = sqrt(a);
		for (c = 2; c <=b ; c++)
		if (a%c == 0)
			break;
		if (c>=b+1)
		{
			printf("%d", a);
			d = d + 1;
		}
		if (d % 10 == 0)printf("\n");
	}
	printf("\n");
	system("pause");
	return 0;
}