#define _CRT_SECURE_NO_WARNINGS 1
//ģ��ʵ��strcat
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* my_strcat1(char* dst, const char* src)
{
	assert(src && dst);
	char* ret = dst;
	while (*dst++);/////////��������ߵ�'\0'��ʱ�򣬺���������++
	dst--;
	/*while (*dst != '\0')//����������ߵ�'\0'��ʱ�򣬾Ͳ���++
	{
		dst++;
	}*/
	while (*dst++ = *src++);
	return dst;//return dst�Ļ�Ҫ��������һ�к���ִ�У�my_strcat1(a1, b);����Ȼ�����a1���������Ӧ
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
	return ret;//ֱ������Ļ���Ҫreturn ret;�������Ӧ
}
int main()
{
	char a1[20] = "hello";
	char a2[20] = "hello";
	char* b = " world";
	my_strcat1(a1, b);//return dst�Ļ�Ҫ��������һ�к���ִ�У�my_strcat1(a1, b);����Ȼ�����a1
	printf("%s\n", a1);
	printf("%s\n", my_strcat2(a2, b));//ֱ������Ļ���Ҫreturn ret;
	system("pause");
	return 0;

}