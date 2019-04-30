#define _CRT_SECURE_NO_WARNINGS 1
//Ä£ÄâÊµÏÖstrcmp
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 && *str2)
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		else if (*str1 < *str2)
			return -1;
		else
		{
			str1++;
			str2++;
		}
	}
	if (*str1 != '\0')
		return 1;
	else if (*str2 != '\0')
		return -1;
	else
		return 0;
}
int main()
{
	char* a1 = "abcdef";
	char* b1 = "abcdee";
	printf("%d\n", my_strcmp(a1, b1));
	char* a2 = "abcdef";
	char* b2 = "abcdeg";
	printf("%d\n", my_strcmp(a2, b2));
	char* a3 = "abcdef";
	char* b3 = "abcdef";
	printf("%d\n", my_strcmp(a3, b3));
	char* a4 = "abd";
	char* b4 = "abcdef";
	printf("%d\n", my_strcmp(a4, b4));
	system("pause");
	return 0;
}