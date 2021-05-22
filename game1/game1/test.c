#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("********************************\n");
	printf("*****1.play          0.exit*****\n"); 
	printf("********************************\n");
}
void game()
{
	char ret = 0;
	//定义一个二维数组，存放信息
	char Board[ROW][COL] = {0};//全部是空格
	//初始化
	InitBoard(Board, ROW, COL);
	//打印棋盘
	DisplayBoard(Board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		Playermove(Board, ROW, COL);
		system("cls");
		menu();
		DisplayBoard(Board, ROW, COL);
		Sleep(1000);

		//判断是否赢
		ret = Iswin(Board, ROW, COL);
	    if (ret != 'c')
		{
			break;
		}

		//电脑下棋
		Computermove(Board, ROW, COL);
		system("cls");
		menu();
		DisplayBoard(Board, ROW, COL);
		Sleep(1000);
		//判断是否赢
		
		ret = Iswin(Board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}

	if (ret == '*')
		printf("玩家赢！\n");
	else if (ret == '#')
		printf("电脑赢！\n");
	else if (ret == '$')
		printf("平局！\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)(time(NULL)));/*随机数函数申明*/
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("输入错误!");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}