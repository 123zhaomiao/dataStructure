#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define ROW 6
#define COL 6


typedef struct position
{
	int x;
	int y;
}position;


typedef struct stack
{
	position data[20];
	int top;
}stack;

//栈初始化
void StackInit(stack *s);
//走迷宫
void  PassMaze(int Maze[ROW][COL], position enter, position Enter, stack * path, stack *  shortpath);
//打印迷宫最短路径
void Print(stack * shortpath);
//打印迷宫
void print(int Maze[ROW][COL]);