#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int n = 0;
	int a = 0;
	int sum = 0;
	int tmp = 0;
	printf("请输入要求前n项a的和中的a和n：");
	scanf("%d %d",&a, &n);
	for (i = 1; i <= n; i++)
	{
		/*int sum = 0;//定义变量必须在外面，否则每次循环会变0；
		int tmp = 0;*/
		tmp = tmp * 10 + a;//
		sum += tmp;
	}
	printf("%d\n",sum);
	system("pause");
	return 0;
}