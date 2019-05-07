#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#define Max 10
#define DataType int 
typedef struct stack
{
	DataType data[Max];
	int top;
}stack;

//初始化
void InitStack(stack *ps);
//入栈
void PushStack(stack *s, stack *mins, DataType d);
//栈最小值
DataType MinStack(stack *mins);
//出栈
void PopStack(stack *s, stack *mins);
