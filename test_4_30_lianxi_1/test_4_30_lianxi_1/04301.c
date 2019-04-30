#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//int main()
//{
//	char a[] = { 1, 2, 3 };
//	char* p = a;
//	printf("%d\n", *p++);//2改为1   先*p后++ 特别注意：后置++，先使用后++，也就是输出的是*p，而不是*p++ 
//	printf("%d\n", *++p);//3
//	printf("%d\n", *p);//3
//	printf("%d\n", p[1]);//越界
//	printf("a[3]=%d\n", a[3]);
//	printf("a[4]=%d\n", a[4]);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char a[] = "\0"; //两个字符'\0'，即a[0] = '\0', a[1] = '\0'
//	char c1 = '\0';//  字符串结束标识字符 它的ascall值为0
//	char c2 = '0';//   字符0，它的ascall值为48
//	              //   NULL 宏常量
//	              //   0    整形常量
//
//	return 0;
//}
//int main()
//{
//	char* str1 = "abcdef";
//	printf("%d\n", strlen(str1));//6  找'\0'
//	printf("%d\n", sizeof(str1));//4或8  sizeof()括号里只要不是数组名（二维数组是a[i]：第i行的数组名），那么计算的都是类型的大小
//	printf("\n");
//	char str2[] = "abcdef";
//	printf("%d\n", strlen(str2));//6  找'\0'
//	printf("%d\n", sizeof(str2));//7  特别注意：sizeof计算字符数组的时候记得要算'\0'，切记
//	printf("\n");
//	char str3[] = "abcde\0gh\0";
//	printf("%d\n", strlen(str3));//5  strlen遇到第一个'\0'就结束，不再往后运算
//	printf("%d\n", sizeof(str3));//10 sizeof计算字符数组（名）的时候\0属于一个字符（标识字符）
//	printf("\n");
//	char str4[] = "abcde\\0gh\\\0";
//	printf("%d\n", strlen(str4));// 10 '\\'属于1个字符，即输出'\',所以'\\0'即'\\'和'0';而'\\\0'即'\\'和'\0'属两个字符
//	printf("%d\n", sizeof(str4));// 12 sizeof计算字符数组大小的方式同strlen，只不过要注意'\0'也算1个字符，区别是strlen遇见第一个'\0'就会结束运算
//	printf("\n");
//	char str5[] = "\0";
//	printf("%d\n", strlen(str5));// 0 数组str5有两个'\0'元素，但是strlen计算结果为0
//	printf("%d\n", sizeof(str5));// 2 突出显示了sizeof要计算'\0'为1个字符
//	printf("\n");
//	char str6[] = "abcde\\0gh\t\r\n";  //计算字符数组大小的时候，遇见所有的转义字符都视为1个字符进行运算
//	printf("%d\n", strlen(str6));// 12 
//	printf("%d\n", sizeof(str6));// 13
//	printf("\n");
//	printf("%s\n", "abc\nd\tge");//'\n'和'\t'会进行转义，不会输出
//	system("pause");
//	return 0;
//}
//
//模拟实现strlen
//1 计数器法 2 递归 3 指针-指针
//size_t my_strlen1(const char* str)
//{
//	assert(str != NULL);
//	size_t count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//size_t my_strlen2(const char* str)
//{
//	assert(str);
//	if (*str == '\0')
//		return 0;
//	/*else*/
//	return 1 + my_strlen2(str + 1);
//}
////size_t my_strlen3(const char* str)
////{
////	assert(str);
////	const char* p = str;
////	while (*p != '\0')
////	{
////		p++;
////	}
////	return p - str;
////}
//size_t my_strlen3(const char* str)
//{
//	assert(str);
//	const char* p = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return str - p;
//}
//
//int main()
//{
//	char a[] = "abcdef";
//	size_t ret1 = my_strlen1(a);
//	size_t ret2 = my_strlen2(a);
//	size_t ret3 = my_strlen3(a);
//	printf("%d\n", ret1);
//	printf("%d\n", ret2);
//	printf("%d\n", ret3);
//	system("pause");
//	return 0;
//}

//模拟实现strcpy
//char* my_strcpy1(char* dst, const char* src)//(类型是char*)注意const的位置
//{
//	assert(dst && src);
//	char* ret = dst;
//	while (*src != '\0')
//	{
//		*dst = *src;
//		src++;
//		dst++;
//	}
//	*dst = *src;
//	return ret;
//}
//char* my_strcpy2(char* dst, const char* src)
//{
//	assert(dst && src);
//	char* ret = dst;
//	while (*dst++ = *src++);
//	return ret;//将dst首元素的地址赋值给ret，然后给*dst赋值，最后输出ret即*dst赋值改变后的%s
//}
//int main()
//{
//	char* a = "hello";
//	char arr[10];
//	char* ret = my_strcpy1(arr, a);/////////char* 类型的函数可以直接使用，即可以直接： my_strcpy1(arr, a);
//	my_strcpy2(arr, a);
//	printf("%s\n", ret);
//	printf("%s\n", arr);
//
//	system("pause");
//	return 0;
//}
////或者
////int main()
////{
////	char dst[10];
////	my_strcpy1(dst, "hello");/////////char* 类型的函数可以直接使用
////
////	printf("%s\n", dst);
////	system("pause");
////	return 0;
////}

//模拟实现strcat 
//char* my_strcat1(char* dst, const char* src)//类型是char* 注意const的位置
//{
//	assert(src && dst);//这一步很重要
//	char* ret = dst;
//	while (*dst++);//找dst中'\0'的位置，后置++的话到'\0'的时候还会再加一次
//	dst--;         //所以这一步要把多加的一步减掉
//	while (*dst++ = *src++);//这一步和strcpy一样，理解记忆
//	//return dst;
//	return ret;
//
//}
//char* my_strcat2(char* dst, const char* src)
//{
//	assert(src && dst);
//	char* ret = dst;
//	size_t count = 0;
//	while (dst[count])//用count直接去寻找'\0'的位置
//	{
//		count++;//走到'\0'的时候就不++了，故不需要--，与上面区别
//	}
//	dst += count;//让 dst 走到'\0'处，然后对其赋值
//	while (*dst++ = *src++);
//	//return dst;
//	return ret;
//
//}
//int main()
//{
//	char a1[20] = "hello";
//	char a2[20] = "hello";
//	char b[] = " world";
//	my_strcat1(a1, b);
//	printf("%s\n", a1);
//	my_strcat2(a2, b);
//	printf("%s\n", a2);
//	system("pause");
//	return 0;
//}

//模拟实现strcmp
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 && *str2)
	{
		if (*str1 > *str2)
			return 1;
		else if (*str1 < *str2)
			return -1;
		else
		{
			str1++;
			str2++;
		}
	}//有一个默认条件：*str1和*str2至少有一个为'\0';故在后面判断谁不等于'\0'.判断等于'\0'会分多种情况，复杂化
	if (*str1 != '\0')
		return 1;
	else if (*str2 != '\0')
		return -1;
	else
		return 0;
	/*if (*str1 != '\0')
		return 1;
	if (*str2 != '\0')
		return -1;
	if (*str1 == *str2)
		return 0;*/

}
int main()
{
	char* a1 = "abcd";
	char* b1 = "abcd";
	my_strcmp(a1, b1);
	printf("%d\n", my_strcmp(a1, b1));
	char* a2 = "abcd";
	char* b2 = "bbcd";
	my_strcmp(a2, b2);
	printf("%d\n", my_strcmp(a2, b2));
	char* a3 = "bbcd";
	char* b3 = "abcd";
	my_strcmp(a3, b3);
	printf("%d\n", my_strcmp(a3, b3));
	system("pause");
	return 0;
}