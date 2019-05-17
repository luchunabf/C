#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
	
int fib(int n)//非递归
{
	int a = 1;
	int b = 1;
	int result = 0;
	if (n > 0 && n <= 2)
		return a;
	else if (n > 2)
	{
		for (int i = 3; i < n + 1; i++)
		{
			result = a + b;
			a = b;
			b = result;
		}
		return result;
	}
	else
		return 0;
}
int f(int n)//递归
{
	if (n > 0 && n <= 2)
		return 1;
	else if (n > 2)
	{
		return f(n - 1) + f(n - 2);
	}
	else
		return 0;
}
int main()
{
	int n=0;
	int ret1,ret2;
	printf("请输入n的值：\n");
	scanf("%d", &n);
	ret1 = fib(n);
	ret2 = f(n);
	printf("%d\n", ret1);
	printf("%d\n", ret2);

	system("pause");
	return 0;
}