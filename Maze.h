#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define ROW  6
#define COL  6

//横纵坐标的值
typedef struct position
{
	int x;
	int y;
}position;

//静态栈，用于存储路径
typedef struct  stack
{
	position data[20];
	int top;
}stack;


//初始化栈
void InitStack(stack *s);

//走迷宫
void PassMaze(int Maze[ROW][COL],position enter,stack* s);

//打印迷宫
void print(int Maze[ROW][COL]);

//打印迷宫路径
void printStack(stack *s);