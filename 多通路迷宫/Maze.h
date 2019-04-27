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

//Õ»³õÊ¼»¯
void StackInit(stack *s);
//×ßÃÔ¹¬
void  PassMaze(int Maze[ROW][COL], position enter, position Enter, stack * path, stack *  shortpath);
//´òÓ¡ÃÔ¹¬×î¶ÌÂ·¾¶
void Print(stack * shortpath);
//´òÓ¡ÃÔ¹¬
void print(int Maze[ROW][COL]);
