#define _CRT_SECURE_NO_WARNINGS 1
//ģ��ʵ��memcpy
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void* my_memcpy(void* dst, const void* src, size_t count)
{
	assert(dst && src);
	if (dst == '\0' || src == '\0')
		return NULL;
	char* pdst = (char*)dst;
	char* psrc = (char*)src;
	while (count--)
	{
		*pdst++ = *psrc++;
	}
	return dst;
}
int main()
{
	char a[10] = "hello";//a[10]ֻ����������������char*����Ϊ�涨a��������ȫ������b
	char* b = "world";
	my_memcpy(a, b, 5);
	printf("%s\n", a);
	system("pause");
	return 0;
}