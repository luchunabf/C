#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("***************\n");
	printf("*****1.play****\n");
	printf("*****0.exit****\n");
	printf("***************\n");
}

void game()
{
	int key = rand() % 100 + 1;
	int word = 0;
	while (1)
	{
		printf("请猜数字：");
		scanf("%d", &word);
		if (word > key)
			printf("猜大了\n");
		else if (word < key)
			printf("猜小了\n");
		else
		{
			printf("恭喜你，猜对啦！\n");
			break;
		}
	}
}

int main()
{
	int word = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &word);
		switch (word)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择：");
			break;
		}
	}
	while(word);
	system("pause");
	return 0;
}