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
	strncpy(arr, p, 17);*///���strncpy������\0


	char arr[30];
	strcpy(arr, p);//���strcpy����\0

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
	printf("%s\n", p);//��ӡ����abcdeffurgugu

	system("pause");
	return 0;
}
#endif

#if 0
int main()
{

	char p[] = "hello world";//ֻ��������
	//char* p = "hello world";//����������
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

	while (*str1 == *str2)//��*str1 == *str2 == \0 ��ʱ��Ҳ���棬��ѭ��
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
		return (char*)str1;//str1 ��������const char* ��Ҫǿ������ת��

	while (*cp)//��cp���str1ƥ��str2ƥ�䵽��str1�е��ĸ�λ�ô�
	{
		s1 = cp;//�ر���Ҫ��ÿ��ƥ�䲻�ɹ��Ļ�s1ָ��ص�cp��λ�����¿�ʼ��һ�ε�ƥ��
		s2 = str2;//ƥ�䲻�ɹ��Ļ���s2���»ص�str2��ʼλ������ƥ��
		while (*s1 && *s2 && *s1 == *s2)//��ʼƥ��
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')//���s2�����ˣ�Ҳ������ȫƥ��ɹ�
			return (char*)cp;//cp��������const char* ��Ҫǿ������ת��

		cp++;
	}

	return NULL;

}

int main()
{
	char* str1 = "gfufgfugfugabcdeffurgugu";
	char* str2 = "abcde";
	char* p = my_strstr(str1, str2);
	printf("%s\n", p);//��ӡ����abcdeffurgugu

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
		while (*s1 && *s2 && *s1 == *s2)//ע����strcmpʵ����ѭ������������
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
	printf("%s\n", p);//��ӡ����abcdeffurgugu

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

	char p[] = "hello world";//ֻ��������
	//char* p = "hello world";//����������
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
			//*(char*)dest = *(char*)src;//����ַǿתΪchar*��1���ֽڣ���Ȼ������ø�ֵ
			//((char*)dest)++;//��ַ��ǿתΪchar*��1���ֽڣ���Ȼ����1���ֽ������һ��
			//((char*)src)++;//ͬ��
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

	char p[] = "hello world";//ֻ��������
	//char* p = "hello world";//����������
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