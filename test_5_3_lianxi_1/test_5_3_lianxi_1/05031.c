#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//转移表 实现简单计算器
int my_add(int a, int b)//add sub mul div clr exit
{
	return a + b;
}
int my_sub(int a, int b)
{
	return a - b;
}
int my_mul(int a, int b)
{
	return a * b;
}
int my_div(int a, int b)
{
	if (b == 0)
	{
		printf("除数不能为零\n");
		exit(EXIT_FAILURE);
	}
	return a / b;
}
void operation()
{
	printf("*************************\n");
	printf("*** 1.add  **** 2.sub ***\n");
	printf("*** 3.mul  **** 4.div ***\n");
	printf("*** 0.exit **** 5.clr ***\n");
	printf("*************************\n");
	printf("\n");
}
int(*oper_func[])(int, int) = { NULL, my_add, my_sub, my_mul, my_div };//数组，按照0,1,2,3,4的顺序，即a[0] = NULL（首元素）

int main()
{
	int choice = 0;
	int a = 0;
	int b = 0;
	int result;
Operation:
	operation();
	while (1)
	{
	printf("make your choice:");
	scanf("%d", &choice);
		if (choice >= 0 && choice < 6)
		{
			if (choice == 0)
				exit(EXIT_SUCCESS);
			else if (choice == 5)
			{
				system("cls");//////////?
				goto Operation;
			}
			else
			{
				printf("请输入a：\n");
				scanf("%d", &a);
				printf("请输入b：\n");
				scanf("%d", &b);
				result = oper_func[choice](a, b);
				printf("%d\n", result);
			}
		}
		else
		{
			printf("ERROR\n");
			exit(EXIT_FAILURE);
		}
	}
	//system("pause");
	return 0;
}