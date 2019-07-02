#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)
{
	printf("ÇëÊäÈëÊı×Ö£º\n");
	scanf("%d", &value);
	int i = 0;
	int count = 0;
	while (value)
	{
		count++;
		value = value&(value - 1);
	}
	return count;
	
}

int main()
{
	int value = 0;
	int ret = count_one_bits(value);
	printf("%d\n", ret);
	system("pause");
	return 0;
}