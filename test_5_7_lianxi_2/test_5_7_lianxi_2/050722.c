#define _CRT_SECURE_NO_WARNINGS 1
//Ä£ÄâÊµÏÖstrcat
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* my_strcat1(char* dst, const char* src)
{
	assert(dst && src);
	char* ret = dst;
	size_t count = 0;
	while (dst[count] != '\0')
	{
		count++;
	}
	dst += count;
	while (*dst++ = *src++);
	return ret;
}
char* my_strcat2(char* dst, const char* src)
{
	assert(src && dst);
	char* ret = dst;
	while (*dst++);
	dst--;
	while (*dst++ = *src++);
	return ret;
}
int main()
{
	char str1[20] = "hello";
	char str2[20] = "hello";
	char* str = " world";
	printf("%s\n", my_strcat1(str1, str));
	printf("%s\n", my_strcat2(str2, str));
	system("pause");
	return 0;
}