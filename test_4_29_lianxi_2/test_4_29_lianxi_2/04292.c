#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
size_t my_strlen(const char* str)
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
	char a[] = "abcdef";
	size_t ret = my_strlen(a);
	printf("%d\n", ret);
	system("pause");
	return 0;
}