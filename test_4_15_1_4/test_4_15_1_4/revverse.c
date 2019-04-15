//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//static int stringlenth(char*arr)
//{
//	if (*arr == '\0')
//		return 0;
//	return 1 + stringlenth(arr + 1);
//}
//static void reverse(char* start,char* end)
//{
//	
//	while (start<end)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//void reverse2(char* arr)
//{
//	int len = stringlenth(arr);
//	reverse(arr, arr + len - 1);
//	while (*arr != '\0')
//	{
//		
//		char* pos = arr;
//		while ((*arr != ' ') && (*arr != '\0'))
//		{
//			arr++;
//		}
//		reverse(pos,arr-1);
//		if (*arr != '\0')
//			arr++;
//	}
//}
//int main()
//{
//	char arr[1024] = { 0 };
//	printf("请输入字符串：\n");
//	scanf("%s", &arr);
//	reverse2(arr);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int  my_len(char *str)
{
	assert(str);
	int count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}

void reverse(char *start, char *end)
{
	assert(start&&end);
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

void str_reverse(char *str)
{
	assert(str);
	int len = my_len(str);
	reverse(str, str + len - 1);  //全部逆置
	while (*str != '\0')
	{
		char *pos = str;
		while ((*str != ' ') && (*str != '\0'))
		{
			str++;
		}
		reverse(pos, str - 1);    //每个单词的逆置
		if (*str != '\0')
			str++;
	}
}

int main()
{
	char str[] = "student a am i";
	str_reverse(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}
