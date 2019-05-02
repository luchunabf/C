#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
size_t my_strlen(const char* str)
{
	assert(str);
	size_t count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char* a = "abcdfghj";
	size_t ret = my_strlen(a);
	printf("%d\n", ret);
	system("pause");
	return 0;


}