#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
//int fib(size_t n)
//{
//	if (n <= 2)
//		return 1;
//	return (fib(n - 2) + fib(n - 1));
//}
//int fib(size_t n)
//{
//	int ret = 0;
//	int a = 0;
//	int b = 0;
//	for (size_t i = 0; i <= n; ++i)
//	{
//		if (i <= 2)
//		{
//			a = 1;
//			b = 1;
//			ret = 1;
//		}
//		else
//		{
//			ret = a + b;
//			a = b;
//			b = ret;
//		}
//	}
//	return ret;
//}
int fib(size_t n)
{
	if (n <= 2)
		return 1;
	else
	{
		int a = 1, b = 1, ret = 0;
		for (size_t i = 3; i <= n; ++i)
		{
			ret = a + b;
			a = b;
			b = ret;
		}
		return ret;
	}
}
int main()
{
	int a = 5;
	int ret = fib(a);
	printf("%d\n", ret);
	system("pause");
	return 0;
}