#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void menu()//函数定义要在主函数的前面
{
	printf("********************************\n");
	printf("***********  1.猜数字   ********\n");
	printf("***********  0.退出游戏 ********\n");
	printf("********************************\n");

}

void game()
{
	int input = 0;
	int key = 0;
	key = rand() % 100 + 1;
	printf("请输入所猜的数字：");
	while (1)
	{
		scanf("%d", &input);
		if (input > key)
		{
			printf("猜大了,请重新选择：\n");
		}
		else if (input < key)
		{
			printf("猜小了，请重新选择：\n");
		}
		else
		{
			printf("恭喜你，找到了，key=%d\n", key);
			break;
		}
	}
}
//我写的
int main()
{
	menu();
	int input = 0;
	srand((unsigned)time(NULL));
	printf("请选择\n");
	do
	{
	scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			input = 0;
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择：");
		}
	} while (input);

	
	system("pause");
	return 0;
}


//老师的
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新选择：\n");
//			break;
//		}
//	} while (input);
//
//
//	system("pause");
//	return 0;
//}