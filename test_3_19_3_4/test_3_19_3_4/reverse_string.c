#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>



//char* reverse_string(char *string,int left,int right)
//{
//	left = 0;
//	/*string[7]="0";*/
//	right = sizeof string / sizeof string[0]-1;
//	if (left<=right)
//	{
//		int temp = 0;
//		temp = string[left];
//		string[left] = string[right];
//		string[right] = temp;
//		reverse_string(string, left + 1, right - 1);
//		return string;
//	}
//	else 
//		return string;
//}
//
//int main()
//{
//	char string[] = "abcdef";
//	reverse_string(string, 0, 6);
//	printf("%s", string);
//
//	system("pause");
//	return 0;
//}

int stringlength(char* str)
{
	if (*str == '\0')
		return 0;
	return 1 + stringlength(str + 1);
}

void reverse_string(char* str)
{
	int len = stringlength(str);
	if (*str != 0)
	{
		char tmp;
		tmp = str[0];
		str[0] = str[len - 1];
		str[len - 1] = '\0';
		reverse_string(str + 1);
		str[len - 1] = tmp;

	}
}

int main()
{
	char arr[1024] = { 0 };
	printf("请输入字符串：\n");
	scanf("%s", &arr);
	reverse_string(arr);
	printf("字符串的反向排列为：\n%s\n",arr);
	system("pause");
	return 0;
}