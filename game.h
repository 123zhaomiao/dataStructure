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
#define Easy_Count 10                                                    //�׵�����
void InitBoard(char arr[ROWS][COLS],int rows,int cols,char sz);          //��ʼ������
void SetMine(char mine[ROWS][COLS], int row, int col);                   //����
void DisplayBoard(char arr[ROWS][COLS], int row, int col);               //��ӡ����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);  //ɨ��


#endif //__GAME_H__