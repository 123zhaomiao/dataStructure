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
//共享栈初始化
void InitShared(sharedstack *s);
//栈顶
DataType SharedStackTop(sharedstack *s, int which);
//栈长短
DataType SharedStackSize(sharedstack *s, int which);
//入栈
void PushSharedStack(sharedstack *s,DataType d, int which);
//出栈
void PopSharedStack(sharedstack *s, int which);