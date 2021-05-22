#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		/*1.��ӡ����*/
		for (j = 0; j < col; j++)
		{
				printf(" %c ", board[i][j]);
				if (j < col-1)
				{
					printf("|");
				}
		}
		printf("\n");
		/*2.��ӡ�ָ���*/
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void Playermove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("��������壺\n"); 
	while (1)
	{
		printf("�������������꣺\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*'; break;
			}
			else
				printf("������ռ�ã�\n");
		}
		else
		{
			printf("���벻�Ϸ�!"); break;
		}
	}
}
void Computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("���������壺\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;/*������ɺ�������*/
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '#'; break;
		}
		else
		{
			continue;
		}
	}
}
char Iswin(char board[ROW][COL], int row, int col)
{
	int x ;
	int y ;
	for (x = 0; x < row; x++)/*������*/
	{
		if (board[x][0] == board[x][1] && board[x][1] == board[x][2] && board[x][1] != ' ')
		{
			return board[x][1];/*����ֵ*/
		}
	}
	for (y = 0; y < col; y++)/*������*/
	{
		if (board[0][y] == board[1][y] && board[1][y] == board[2][y] && board[1][y] != ' ')
		{
			return board[1][y];/*����ֵ*/
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')/*б*/
	{
		return board[1][1];/*����ֵ*/
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')/*б*/
	{
		return board[1][1];/*����ֵ*/
	}

	if (1 == Isfull(board, ROW, COL))/*�ж������Ƿ���*/
	{
		return '$';
	}
	else
	{
		return 'c';
	}
}
int Isfull(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}