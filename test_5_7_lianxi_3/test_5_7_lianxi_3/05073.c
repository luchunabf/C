#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//for (int i = 0; i < top; i++)
// {
//	char first = str[0];  //先取出第一个
//	
//	for (int j = 0; j < len - 1; j++)
//    {
//		str[j] = str[j + 1];
//	  }
//	str[j] = first;     //加到最后面
//  }
//int main()
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf(" * ");
//		}
//		printf("\n");
//	}
//}
/////左旋字符串
char* turn_left(char* str)
{
	char* get = str;
	char* get_get = get;
	char tmp = *str;
	str++;
	while (*str != '\0')
		*(get++) = *(str++);
	*get = tmp;
	return get_get;
}
char* turnleft_n(char* str, int num)
{
	for (int i = 0; i < num - 1; i++)
		turn_left(str);
	return turn_left(str);
}
int main()
{
	char str[100] = "ABCDEF";
	int n = 3;
	char* strstr = turnleft_n(str, n);
	printf("%s\n", strstr);
	system("pause");
	return 0;
}