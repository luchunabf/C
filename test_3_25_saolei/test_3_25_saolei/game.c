#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-------------------------------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------------\n");
}

void set_board(char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = EASY_COUNT;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
static int getminecount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1]
		+ mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}

static void Sweep(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{

	int i = 0;
	int j = 0;
	int AroundCount = 0;
	if (show[x][y] == '*')
	{

		AroundCount = getminecount(mine, x, y);
		if (AroundCount != 0)
		{
			show[x][y] = '0' + AroundCount;
		}
		else
		{
			show[x][y] = '0';
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					if (x + i >= 1 && x + i <= ROW && y + j >= 1 && y + j <= COL)
					{
						if (i != 0 || j != 0)
						{
							Sweep(mine, show, x + i, y + j);
						}
					}
				}
			}
		}
	}
}


void find_board(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{

	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row*col - EASY_COUNT)
	{
		printf("请输入要排的坐标：\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				display_board(mine, ROW, COL);
				break;
			}
			else
			{
				int count = getminecount(mine, x, y);
				show[x][y] = count + '0';
				Sweep(mine, show, x, y);
				display_board(show, ROW, COL);
				win++;

			}
		}
		else
		{
			printf("选择错误，请重新选择：\n");
		}
	}
	if (win >= row*col - EASY_COUNT)
	{
		printf("恭喜您排雷成功！\n");
		display_board(mine, row, col);
	}
}