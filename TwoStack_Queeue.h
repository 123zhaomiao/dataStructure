#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#define Max 10
#define Datatype int
typedef struct stack
{
	Datatype data[Max];
	int top ;
}stack;
typedef struct Queue
{
	stack s1;
	stack s2;
}queue;
//初始化对列
void InitQueue(queue *q);
//入对列
void PushQueue(queue *q, Datatype d);
//对列元素个数
int SizeQueue(queue *q);
//对列尾
int QueueBack(queue *q);
//对列尾
int QueueFront(queue *q);
//出对列
void PopQueue(queue *q);