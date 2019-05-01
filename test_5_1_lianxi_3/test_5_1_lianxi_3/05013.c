#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* my_strcat1(char* dst, const char* src)
{
	assert(dst && src);
	char* ret = dst;
	while (*dst++);
	dst--;
	while (*dst++ = *src++);
	return ret;
}
char* my_strcat2(char* dst, const char* src)
{
	assert(dst && src);
	char* ret = dst;
	size_t count = 0;
	while (dst[count])
	{
		count++;
	}
	dst += count;
	while (*dst++ = *src++);
	return ret;
}
int main()
{
	char a1[20] = "hello";
	char a2[20] = "hello";
	char* b = " world";
	printf("%s\n", my_strcat1(a1, b));
	printf("%s\n", my_strcat2(a2, b));
	system("pause");
	return 0;
}