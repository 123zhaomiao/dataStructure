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
//��ʼ������
void InitQueue(queue *q);
//�����
void PushQueue(queue *q, Datatype d);
//����Ԫ�ظ���
int SizeQueue(queue *q);
//����β
int QueueBack(queue *q);
//����β
int QueueFront(queue *q);
//������
void PopQueue(queue *q);