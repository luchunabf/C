#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int year=1000;
	printf("请输入年份\n");
	scanf("%d", &year);
	if (year <= 2000)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			printf("year\n");
			printf("该年是闰年\n");
		}
		else
		{
			printf("year");
			printf("该年不是闰年\n");
		}
	}
	else
	{
		printf("超出范围\n");

	}
	
	return 0;
}