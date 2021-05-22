#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define ROW 3//行
#define COL 3//列

//函数申明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void Playermove(char board[ROW][COL], int row, int col);
void Computermove(char board[ROW][COL], int row, int col);
char Iswin(char board[ROW][COL], int row, int col);
int Isfull(char board[ROW][COL], int row, int col);
//