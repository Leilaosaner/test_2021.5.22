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
	//����һ����ά���飬�����Ϣ
	char Board[ROW][COL] = {0};//ȫ���ǿո�
	//��ʼ��
	InitBoard(Board, ROW, COL);
	//��ӡ����
	DisplayBoard(Board, ROW, COL);
	//����
	while (1)
	{
		//�������
		Playermove(Board, ROW, COL);
		system("cls");
		menu();
		DisplayBoard(Board, ROW, COL);
		Sleep(1000);

		//�ж��Ƿ�Ӯ
		ret = Iswin(Board, ROW, COL);
	    if (ret != 'c')
		{
			break;
		}

		//��������
		Computermove(Board, ROW, COL);
		system("cls");
		menu();
		DisplayBoard(Board, ROW, COL);
		Sleep(1000);
		//�ж��Ƿ�Ӯ
		
		ret = Iswin(Board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}

	if (ret == '*')
		printf("���Ӯ��\n");
	else if (ret == '#')
		printf("����Ӯ��\n");
	else if (ret == '$')
		printf("ƽ�֣�\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)(time(NULL)));/*�������������*/
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("�������!");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}