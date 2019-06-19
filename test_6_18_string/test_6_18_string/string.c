#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>

#if 0
int main()
{
	char* p = "luchunabf@163.com";
	/*char arr[30] = { 0 };
	strncpy(arr, p, 17);*///这个strncpy不拷贝\0


	char arr[30];
	strcpy(arr, p);//这个strcpy拷贝\0

	char* str = NULL;
	for (str = strtok(arr, ".@"); str != NULL; str = strtok(NULL, ".@"))
		printf("%s\n", str);

	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	char* str1 = "abcdf";
	char* str2 = "abcde";

	//int ret = strncmp(str1, str2, 5);
	int ret = memcmp(str1, str2, 4);

	printf("%d\n", ret);

	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	char* str1 = "gfufgfugfugabcdeffurgugu";
	char* str2 = "abcde";
	char* p = strstr(str1, str2);
	printf("%s\n", p);//打印的是abcdeffurgugu

	system("pause");
	return 0;
}
#endif

#if 0
int main()
{

	char p[] = "hello world";//只能这样给
	//char* p = "hello world";//不能这样给
	//char* p1 ;
	char p1[10] = { 0 };

	//memcpy(p1, p, sizeof(p)+1);
	memmove(p, p + 6, 5);

	//printf("%s\n", p1);
	printf("%s\n", p);

	system("pause");
	return 0;
}
#endif

#if 0
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);

	while (*str1 == *str2)//当*str1 == *str2 == \0 的时候也算真，入循环
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	if (*str2 == '\0')
		return 1;
	else
		return -1;

}

int main()
{
	const char* p1 = "hello";
	const char* p2 = "helloo";

	int ret = my_strcmp(p1, p2);
	printf("%d\n", ret);

	system("pause");
	return 0;
}
#endif 

#if 0
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);

	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	return *str1 - *str2;

}
int main()
{
	const char* p1 = "helloo";
	const char* p2 = "hello";

	int ret = my_strcmp(p1, p2);
	printf("%d\n", ret);

	system("pause");
	return 0;
}
#endif

#if 0
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* cp = str1;

	if (*str2 == '\0')
		return (char*)str1;//str1 的类型是const char* 需要强制类型转换

	while (*cp)//用cp标记str1匹配str2匹配到了str1中的哪个位置处
	{
		s1 = cp;//特别重要，每次匹配不成功的话s1指针回到cp的位置重新开始下一次的匹配
		s2 = str2;//匹配不成功的话，s2重新回到str2开始位置重新匹配
		while (*s1 && *s2 && *s1 == *s2)//开始匹配
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')//如果s2走完了，也就是完全匹配成功
			return (char*)cp;//cp的类型是const char* 需要强制类型转换

		cp++;
	}

	return NULL;

}

int main()
{
	char* str1 = "gfufgfugfugabcdeffurgugu";
	char* str2 = "abcde";
	char* p = my_strstr(str1, str2);
	printf("%s\n", p);//打印的是abcdeffurgugu

	system("pause");
	return 0;
}
#endif

#if 0 
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* cp = str1;
	if (*str2 == '\0')
		return (char*)str1;
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1 && *s2 && *s1 == *s2)//注意与strcmp实现是循环条件的区别
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return (char*)cp;
		cp++;
	}
	return NULL;
}

int main()
{
	char* str1 = "gfufgfugfugabcdeffurgugu";
	char* str2 = "abcde";
	char* p = my_strstr(str1, str2);
	printf("%s\n", p);//打印的是abcdeffurgugu

	system("pause");
	return 0;
}
#endif

#if 0
void* my_memcpy(void* dest, const void* src, int count)
{
	void* ret = dest;
	assert(dest);
	assert(src);
	while (count--)
	{
		*(char*)dest = *(char*)src;
		((char*)dest)++;
		((char*)src)++;
	}
	return ret;
}
int main()
{

	char p[] = "hello world";//只能这样给
	//char* p = "hello world";//不能这样给
	//char* p1 ;
	char p1[15] = { 0 };

	my_memcpy(p1, p, sizeof(p)+1);
	//memmove(p, p + 6, 5);

	//printf("%s\n", p1);
	printf("%s\n", p);

	system("pause");
	return 0;
}
#endif

#if 0
void* my_memmove(void* dest, void* src,int count)
{
	assert(dest);
	assert(src);
	void* ret = dest;

	if (dest < src)
	{
		while (count--)
		{
			//*(char*)dest = *(char*)src;//将地址强转为char*（1个字节），然后解引用赋值
			//((char*)dest)++;//地址先强转为char*（1个字节），然后以1个字节往后加一个
			//((char*)src)++;//同上
			*((char*)dest)++ = *((char*)src)++;
		}
	}
	else
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}

int main()
{

	char p[] = "hello world";//只能这样给
	//char* p = "hello world";//不能这样给
	//char* p1 ;
	char p1[15] = { 0 };

	//my_memcpy(p1, p, sizeof(p)+1);
	my_memmove(p, p + 6, 5);

	//printf("%s\n", p1);
	printf("%s\n", p);

	system("pause");
	return 0;
}
#endif