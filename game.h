#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define ROW 3
#define COL 3
void InitBoard(char arr[ROW][COL], int row, int col);          //��ʼ������
void DisplayBoard(char arr[ROW][COL], int row,int col);        //��ӡ����
void PalyerMove(char arr[ROW][COL],int row, int col);          //����ƶ�
void ComputerMove(char arr[ROW][COL], int row, int col);       //�����ƶ�
char Is_Win(char arr[ROW][COL], int row, int col);             //�ж���Ӯ

#endif    //__GAME_H__