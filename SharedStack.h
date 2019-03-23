#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define Max 10
#define DataType int 
typedef struct SharedStack
{
	DataType data[Max];
	int top1;
	int top2;
}sharedstack;
//����ջ��ʼ��
void InitShared(sharedstack *s);
//ջ��
DataType SharedStackTop(sharedstack *s, int which);
//ջ����
DataType SharedStackSize(sharedstack *s, int which);
//��ջ
void PushSharedStack(sharedstack *s,DataType d, int which);
//��ջ
void PopSharedStack(sharedstack *s, int which);