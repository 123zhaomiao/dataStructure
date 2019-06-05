#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define ROW 3
#define COL 3
void InitBoard(char arr[ROW][COL], int row, int col);          //初始化棋盘
void DisplayBoard(char arr[ROW][COL], int row,int col);        //打印棋盘
void PalyerMove(char arr[ROW][COL],int row, int col);          //玩家移动
void ComputerMove(char arr[ROW][COL], int row, int col);       //电脑移动
char Is_Win(char arr[ROW][COL], int row, int col);             //判断输赢

#endif    //__GAME_H__
