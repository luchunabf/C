#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//int main()
//{
//	char a[] = { 1, 2, 3 };
//	char* p = a;
//	printf("%d\n", *p++);//2��Ϊ1   ��*p��++ �ر�ע�⣺����++����ʹ�ú�++��Ҳ�����������*p��������*p++ 
//	printf("%d\n", *++p);//3
//	printf("%d\n", *p);//3
//	printf("%d\n", p[1]);//Խ��
//	printf("a[3]=%d\n", a[3]);
//	printf("a[4]=%d\n", a[4]);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char a[] = "\0"; //�����ַ�'\0'����a[0] = '\0', a[1] = '\0'
//	char c1 = '\0';//  �ַ���������ʶ�ַ� ����ascallֵΪ0
//	char c2 = '0';//   �ַ�0������ascallֵΪ48
//	              //   NULL �곣��
//	              //   0    ���γ���
//
//	return 0;
//}
//int main()
//{
//	char* str1 = "abcdef";
//	printf("%d\n", strlen(str1));//6  ��'\0'
//	printf("%d\n", sizeof(str1));//4��8  sizeof()������ֻҪ��������������ά������a[i]����i�е�������������ô����Ķ������͵Ĵ�С
//	printf("\n");
//	char str2[] = "abcdef";
//	printf("%d\n", strlen(str2));//6  ��'\0'
//	printf("%d\n", sizeof(str2));//7  �ر�ע�⣺sizeof�����ַ������ʱ��ǵ�Ҫ��'\0'���м�
//	printf("\n");
//	char str3[] = "abcde\0gh\0";
//	printf("%d\n", strlen(str3));//5  strlen������һ��'\0'�ͽ�����������������
//	printf("%d\n", sizeof(str3));//10 sizeof�����ַ����飨������ʱ��\0����һ���ַ�����ʶ�ַ���
//	printf("\n");
//	char str4[] = "abcde\\0gh\\\0";
//	printf("%d\n", strlen(str4));// 10 '\\'����1���ַ��������'\',����'\\0'��'\\'��'0';��'\\\0'��'\\'��'\0'�������ַ�
//	printf("%d\n", sizeof(str4));// 12 sizeof�����ַ������С�ķ�ʽͬstrlen��ֻ����Ҫע��'\0'Ҳ��1���ַ���������strlen������һ��'\0'�ͻ��������
//	printf("\n");
//	char str5[] = "\0";
//	printf("%d\n", strlen(str5));// 0 ����str5������'\0'Ԫ�أ�����strlen������Ϊ0
//	printf("%d\n", sizeof(str5));// 2 ͻ����ʾ��sizeofҪ����'\0'Ϊ1���ַ�
//	printf("\n");
//	char str6[] = "abcde\\0gh\t\r\n";  //�����ַ������С��ʱ���������е�ת���ַ�����Ϊ1���ַ���������
//	printf("%d\n", strlen(str6));// 12 
//	printf("%d\n", sizeof(str6));// 13
//	printf("\n");
//	printf("%s\n", "abc\nd\tge");//'\n'��'\t'�����ת�壬�������
//	system("pause");
//	return 0;
//}
//
//ģ��ʵ��strlen
//1 �������� 2 �ݹ� 3 ָ��-ָ��
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

//ģ��ʵ��strcpy
//char* my_strcpy1(char* dst, const char* src)//(������char*)ע��const��λ��
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
//	return ret;//��dst��Ԫ�صĵ�ַ��ֵ��ret��Ȼ���*dst��ֵ��������ret��*dst��ֵ�ı���%s
//}
//int main()
//{
//	char* a = "hello";
//	char arr[10];
//	char* ret = my_strcpy1(arr, a);/////////char* ���͵ĺ�������ֱ��ʹ�ã�������ֱ�ӣ� my_strcpy1(arr, a);
//	my_strcpy2(arr, a);
//	printf("%s\n", ret);
//	printf("%s\n", arr);
//
//	system("pause");
//	return 0;
//}
////����
////int main()
////{
////	char dst[10];
////	my_strcpy1(dst, "hello");/////////char* ���͵ĺ�������ֱ��ʹ��
////
////	printf("%s\n", dst);
////	system("pause");
////	return 0;
////}

//ģ��ʵ��strcat 
//char* my_strcat1(char* dst, const char* src)//������char* ע��const��λ��
//{
//	assert(src && dst);//��һ������Ҫ
//	char* ret = dst;
//	while (*dst++);//��dst��'\0'��λ�ã�����++�Ļ���'\0'��ʱ�򻹻��ټ�һ��
//	dst--;         //������һ��Ҫ�Ѷ�ӵ�һ������
//	while (*dst++ = *src++);//��һ����strcpyһ����������
//	//return dst;
//	return ret;
//
//}
//char* my_strcat2(char* dst, const char* src)
//{
//	assert(src && dst);
//	char* ret = dst;
//	size_t count = 0;
//	while (dst[count])//��countֱ��ȥѰ��'\0'��λ��
//	{
//		count++;//�ߵ�'\0'��ʱ��Ͳ�++�ˣ��ʲ���Ҫ--������������
//	}
//	dst += count;//�� dst �ߵ�'\0'����Ȼ����丳ֵ
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

//ģ��ʵ��strcmp
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
	}//��һ��Ĭ��������*str1��*str2������һ��Ϊ'\0';���ں����ж�˭������'\0'.�жϵ���'\0'��ֶ�����������ӻ�
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