#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define ROW  6
#define COL  6

//���������ֵ
typedef struct position
{
	int x;
	int y;
}position;

//��̬ջ�����ڴ洢·��
typedef struct  stack
{
	position data[20];
	int top;
}stack;


//��ʼ��ջ
void InitStack(stack *s);

//���Թ�
void PassMaze(int Maze[ROW][COL],position enter,stack* s);

//��ӡ�Թ�
void print(int Maze[ROW][COL]);

//��ӡ�Թ�·��
void printStack(stack *s);