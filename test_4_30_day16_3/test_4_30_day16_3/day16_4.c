#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<assert.h>
//Ä£ÄâÊµÏÖstrstr
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	char* cp = (char*)str1;
//	char* substr = (char*)str2;
//	char* s1 = NULL;
//	if (*str2 == '\0')
//		return NULL;
//	while (*cp)
//	{
//		s1 = cp;
//		substr = str2;
//		while (*s1 && *substr && (*s1 == *substr))
//		{
//			s1++;
//			substr++;
//		}
//		if (*substr == '\0')
//			return cp;
//		cp++;
//	}
//
//}
//int main()
//{
//	char* a = "abcdef";
//	char* b = "cde";
//	my_strstr(a, b);
//	printf("%s\n", my_strstr(a, b));
//	system("pause");
//	return 0;
//	
//}
const char* StrStr(const char *str1, const char *str2)
{
	assert(NULL != str1 && NULL != str2);


	while (*str1 != '\0')
	{
		const char *p = str1;
		const char *q = str2;
		const char *res = NULL;
		if (*p == *q)
		{
			res = p;
			while (*p && *q && *p++ == *q++)
				;

			if (*q == '\0')
				return res;
		}
		str1++;
	}
	return NULL;
}


int main()
{
	const char *str1 = "abcdef";
	const char *str2 = "cd";
	const char *res = StrStr(str1, str2);

	printf("%s\n", res);

	system("pause");

}
