#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int a = 1;
//	while (a <= 100)
//	{
//		printf("凤宝宝最棒么么哒\n");
//		a++;
//	}
int main()
 {
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200;i++)
 	{
		int j = 0;
		for (j = 2; j <= i / 2;j++)
 		{
			if (i%j == 0)
				break;
 		}
		if (j>i/2)
 		{
			printf("%d ", i);
			count++;
 		}
 	}
	printf("count=%d\n", count);
// 	系统（“暂停”）;
// 	返回0;
// }
	system("pause");
	return 0;
}