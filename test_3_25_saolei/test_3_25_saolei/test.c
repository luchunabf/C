#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("******************************\n");
	printf("*****       1.play       *****\n");
	printf("*****       0.exit       *****\n");
	printf("******************************\n");

}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');
	display_board(show, ROW, COL);
	set_board(mine, ROW, COL);
	/*display_board(mine, ROW, COL);*///可取消
	find_board(mine, show, ROW, COL);


}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("make your choices:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择：\n");
			break;
		}
	} while (input);

}
int main()
{
	test();
	system("pause");
	return  0;
}