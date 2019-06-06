#define _CRT_SECURE_NO_WARNINGS  1
#ifndef __GAME_H__
#define __GAME_H__


#include<stdio.h>
#include<stdlib.h>
#include<time.h>  
#include<string.h>
#define ROW 9         
#define COL 9
#define ROWS  ROW+2
#define COLS  COL+2 
#define Easy_Count 10                                                    //雷的数量
void InitBoard(char arr[ROWS][COLS],int rows,int cols,char sz);          //初始化数组
void SetMine(char mine[ROWS][COLS], int row, int col);                   //布雷
void DisplayBoard(char arr[ROWS][COLS], int row, int col);               //打印数组
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);  //扫雷


#endif //__GAME_H__