#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void init_board(char board[ROW][COL], int row, int col)
{
	memset(board, ' ', ROW*COL*sizeof (board[0][0]));
}

void display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if (i != 2)
		{
			printf("---|---|---\n");
		}
	}
	
}

void player_board(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
flag1:
printf("请输入要走的坐标：");
scanf("%d%d", &x, &y);
x = x - 1;
y = y - 1;
if ((x >= 0 && x <= 2) && (y >= 0 && y <= 2))
{
	if (board[x][y] == ' ')
	{
		board[x][y] = '*';
	}
	else
	{
		printf("输入被占用，请重新输入：");
		goto flag1;
	}

}
else
{
	printf("输入错误，请重新输入：");
	goto flag1;
}
printf("\n");

}

void comp_board(char board[ROW][COL], int row, int col)
{
	srand((unsigned)time(NULL));
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	printf("\n");
}

int winner_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == '*')
		{
			
			return 1;
		}
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == '#')
		{
			
			return 2;
		}
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] == '*')
		{
			
			return 1;
		}
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] == '#')
		{
			
			return 2;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == '*')
	{
		
		return 1;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == '*')
	{

		return 1;
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == '#')
	{
		
		return 2;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == '#')
	{

		return 2;
	}
	if (is_full(board, ROW, COL) == 5)
	{
		
		return 3;
	}
	return 0;
}

int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 4;
			
		}
	}
	return 5;
}