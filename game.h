#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define ROW 3
#define COL 3
void InitBoard(char arr[ROW][COL], int row, int col);          //≥ı ºªØ∆Â≈Ã
void DisplayBoard(char arr[ROW][COL], int row,int col);        //¥Ú”°∆Â≈Ã
void PalyerMove(char arr[ROW][COL],int row, int col);          //ÕÊº““∆∂Ø
void ComputerMove(char arr[ROW][COL], int row, int col);       //µÁƒ‘“∆∂Ø
char Is_Win(char arr[ROW][COL], int row, int col);             //≈–∂œ ‰”Æ

#endif    //__GAME_H__