#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char *turn_one(char *str) //每次调用将字符串最左边的值放到最右边
{
	char *get = str;
	char *get_get = get;
	char tmp = *str;
	str++;
	while (*str != '\0')
		*(get++) = *(str++);
	*get = tmp;
	return get_get;
}
char *turn_left(char *str, int num) //控制左旋的字符个数
{
	int i = 0;
	for (i = 0; i<num - 1; i++)
		turn_one(str);
	return turn_one(str);
}

int jude_same(char *str1, char *str2, int len1) //判断是否为旋转之后字符串
{
	int i = 0;
	for (i = 0; i<len1; i++){                   //将其中一个字符串每次左旋一个字符，然后与另一个字符串比较
		if (strcmp(turn_left(str1, i), str2) == 0)
			return 1;
	}
	return 0;
}
int main()
{
	char str1[] = "hello";                  //str1与str2为测试数组
	int len1 = strlen(str1);
	char str2[] = "llohe";
	int len2 = strlen(str2);
	if (len1 == len2)                        //当俩个字符串大小相等进入比较
	{
		if (jude_same(str1, str2, len1))
			printf("是\n");
		else printf("不是");
	}
	else printf("不是\n");
	system("pause");
	return 0;
}