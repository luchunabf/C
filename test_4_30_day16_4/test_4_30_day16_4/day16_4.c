#define _CRT_SECURE_NO_WARNINGS 1
//Ä£ÄâÊµÏÖstrchr
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//char* mystrchr(const char* str, char c)
//{
//	if (*str == '\0')
//	{
//		return NULL;
//	}
//	char* s1 = (char*)str;
//	while (*s1)
//	{
//		if (*s1 == c)
//		{
//			return s1;
//		}
//		s1++;
//	}
//	return NULL;
//}
char* my_strchr(const char* str, int c)
{
	assert(str);
	char* ret =(char*) str;
	while (*ret)
	{
		if (*ret == c)//?
		{
			return ret;
		}
		ret++;
	}
	return NULL;
}
int main()
{
	char* str = "abcccdef";
	char* ret = my_strchr(str, 'c');
	printf("%s\n", ret);
	system("pause");
	return 0;
}