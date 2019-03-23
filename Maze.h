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

//ջ��ʼ��
void StackInit(stack *s);
//���Թ�
void  PassMaze(int Maze[ROW][COL], position enter, position Enter, stack * path, stack *  shortpath);
//��ӡ�Թ����·��
void Print(stack * shortpath);
//��ӡ�Թ�
void print(int Maze[ROW][COL]);