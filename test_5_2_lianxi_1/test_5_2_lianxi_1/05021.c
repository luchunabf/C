#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int my_strlen(const char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char* arr = "abcde";
	int ret = my_strlen(arr);
	printf("%d\n", ret);
	system("pause");
	return 0;
}