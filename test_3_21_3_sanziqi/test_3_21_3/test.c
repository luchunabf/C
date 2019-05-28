#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("##########################\n");
	printf("#######  1.play  #########\n");
	printf("#######  2.exit  #########\n");
	printf("##########################\n");

}

void game()
{
	char board[ROW][COL];
	init_board(board, ROW, COL);
	display_board(board, ROW, COL);
	while (1)
	{
		player_board(board, ROW, COL);
		display_board(board, ROW, COL);
		if (winner_board(board, ROW, COL) == 1)
		{
			printf("玩家赢\n");
			break;
		}
		else if (winner_board(board, ROW, COL) == 3)
		{
			printf("平局\n");
			break;
		}
		comp_board(board, ROW, COL);
		display_board(board, ROW, COL);
		if (winner_board(board, ROW, COL) == 2)
		{
			printf("电脑赢\n");
			break;
		}
		else if (winner_board(board, ROW, COL) == 3)
		{
			printf("平局\n");
			break;
		}

	}

}

int main()
{
	int input = 0;
	menu();
	do
	{
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("已退出，谢谢！\n");
			break;
		default:
			printf("选择错误");
			break;
		}
	} while (input);
	
	return 0;
}