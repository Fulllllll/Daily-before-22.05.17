#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define ROW 10
#define COL 10
#define M_NUM 21
void InitBoard(char board[ROW + 2][COL + 2], int rows, int cols, char set);
void Display(char board[ROW+2][COL + 2], int row, int col);
void SetMine(char board[ROW + 2][COL + 2], int row, int col);
void FindMine(char mine[ROW + 2][COL + 2], char show[ROW + 2][COL + 2],int bcount[ROW + 2][COL + 2], int row, int col);
void Dig(char mine[ROW + 2][COL + 2], char show[ROW + 2][COL + 2], int bcount[ROW + 2][COL + 2], int x, int y,int* win);