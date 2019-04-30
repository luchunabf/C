#define _CRT_SECURE_NO_WARNINGS 1
//模拟实现strcat
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* my_strcat1(char* dst, const char* src)
{
	assert(src && dst);
	char* ret = dst;
	while (*dst++);/////////这个代码走到'\0'的时候，后面无条件++
	dst--;
	/*while (*dst != '\0')//而这个代码走到'\0'的时候，就不在++
	{
		dst++;
	}*/
	while (*dst++ = *src++);
	return dst;//return dst的话要在下面有一行函数执行（my_strcat1(a1, b);），然后输出a1，与下面对应
}
char* my_strcat2(char* dst, const char* src)
{
	assert(src && dst);
	char* ret = dst;
	size_t count = 0;
	while (dst[count])
	{
		count++;
	}
	dst += count;
	while (*dst++ = *src++);
	return ret;//直接输出的话需要return ret;与下面对应
}
int main()
{
	char a1[20] = "hello";
	char a2[20] = "hello";
	char* b = " world";
	my_strcat1(a1, b);//return dst的话要在下面有一行函数执行（my_strcat1(a1, b);），然后输出a1
	printf("%s\n", a1);
	printf("%s\n", my_strcat2(a2, b));//直接输出的话需要return ret;
	system("pause");
	return 0;

}