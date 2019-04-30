#define _CRT_SECURE_NO_WARNINGS 1
//Ä£ÄâÊµÏÖmemmove
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void* my_memmove(void* dst, const void* src, size_t count)
{
	assert(NULL != src && NULL != dst);
	char* tmpdst = (char*)dst;
	char* tmpsrc = (char*)src;
	if (tmpdst <= tmpsrc || tmpdst >= tmpsrc + count)
	{
		while (count--)
		{
			*tmpdst++ = *tmpsrc++;
		}
	}
	else
	{
		tmpdst = tmpdst + count - 1;
		tmpsrc = tmpsrc + count - 1;
		while (count--)
		{
			*tmpdst-- = *tmpsrc--;
		}
	}

	return dst;
}
int main()
{
	char a[10] = "abcdef";
	char* b = "defghi";
	my_memmove(a, b, 6);
	printf("%s\n", a);
	system("pause");
	return 0;

}