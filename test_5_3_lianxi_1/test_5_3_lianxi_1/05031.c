#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//ת�Ʊ� ʵ�ּ򵥼�����
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
		printf("��������Ϊ��\n");
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
int(*oper_func[])(int, int) = { NULL, my_add, my_sub, my_mul, my_div };//���飬����0,1,2,3,4��˳�򣬼�a[0] = NULL����Ԫ�أ�

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
				printf("������a��\n");
				scanf("%d", &a);
				printf("������b��\n");
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