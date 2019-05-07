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

//��ʼ��
void InitStack(stack *ps);
//��ջ
void PushStack(stack *s, stack *mins, DataType d);
//ջ��Сֵ
DataType MinStack(stack *mins);
//��ջ
void PopStack(stack *s, stack *mins);