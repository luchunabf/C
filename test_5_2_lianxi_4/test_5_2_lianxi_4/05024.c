#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
size_t my_strlen(const char* str)
{
	assert(str);
	if (*str == '\0')
		return 0;
	return 1 + my_strlen(str + 1);
}
int main()
{
	char* arr = "abcdefgh";
	size_t ret = my_strlen(arr);
	printf("%d\n", ret);
	system("pause");
	return 0;
}