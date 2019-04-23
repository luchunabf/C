#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//自定义strlen函数
static int mystrlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return count;
}
//定义逆置整个字符串函数
static void reverse(char* start, char* end)
{

	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}

}
//定义逆置函数
void reverse_str(char* str)
{
	int sz = mystrlen(str);//获得字符串长度
	//整体逆转
	reverse(str, str + sz - 1);//务必要减1
	//局部逆转
	while (*str!='\0')
	{
		char* start = str;//获得最初地址并赋给start
		while ((*str != '\0') && (*str != ' '))//获得单词的结束
		{
			str++;//地址往后移动
		}
		//单词逆转
		reverse(start, str - 1);//务必要减1
		while (*str == ' ')
		{
			str++;//当str指向空格的时候，移动到下一个单词的起始位置
		}
	}
}
int main()
{
	char arr[100] = { 0 };
	printf("请输入一组带空格的字符串：\n");
	//
	//字符串常量不能被修改
	//char* str1 = "12345 6789";
	//char str[100];
	//scanf: 遇到空格或者换行结束
	//scanf("%s", str);
	//gets：读取一行内容，遇到换行结束
	gets(arr);
	reverse_str(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}