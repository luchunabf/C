#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
size_t my_strlen(const char* str)
{
	assert(str);
	const char* p = str;
	while (*str != '\0')
		str++;
	return str - p;
}
int main()
{
	char* arr = "abcdefg";
	size_t ret = my_strlen(arr);
	printf("%d\n", ret);
	system("pause");
	return 0;
}