#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int n=0;int m = 1;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		m = m*i;
//	printf("nµƒΩ◊≥ÀŒ™£∫%d\n", m);
//
//	system("pause");
//	return 0;
//}

int f(int n)
{
	int m=1;
	if (n>1)
	{
		m = n*f(n - 1);
	}
		return m;
}

int main()
{
	int n;
	printf(" ‰»În£∫");
	scanf("%d", &n);
	int ret = f(n);
	printf("%d\n", ret);

	system("pause");
	return 0;
}