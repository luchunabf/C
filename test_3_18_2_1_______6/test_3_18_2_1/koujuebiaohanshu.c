#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//int koujuebiao(int i)
//{
//	int a = 1, b = 1, c = 0;
//	for (a = 1; a <= i; a++)
//	{
//		for (b = 1; b <= a; b++)
//		{
//			c = a*b;
//			printf("%d", b);
//			printf("*");
//			printf("%d", a);
//			printf("=");
//			printf("%d ", c);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int i = 0;
//	int ret;
//	printf("请输入一个数i=:");
//	scanf("%d", &i);
//	ret = koujuebiao(i);
//	printf("%d\n", ret);
//
//	system("pause");
//	return 0;
//}



void koujuebiao(int i)
{
	int a = 1, b = 1;
	for (a = 1; a <= i; a++)
	{
		for (b = 1; b <= a; b++)
		{
			printf("%d*%d=%-5d", b,a,a*b);
		}
		printf("\n");
	}
}

int main()
{
	int i = 0;
	printf("请输入一个数i=:");
	scanf("%d", &i);
	koujuebiao(i);
	system("pause");
	return 0;
}