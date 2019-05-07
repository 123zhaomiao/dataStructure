#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


#define Max 20
#define DataType char 
typedef struct Stack
{
	DataType data[Max];
	int top;
}stack;


//��ʼ��
void StackInit(stack *s);
//ѹջ
void PushStack(stack *s,DataType d);
//��ջ
void PopStack(stack *s);
//ջ�Ƿ�Ϊ��
int EmptyStack(stack *s);
//ջ��Ԫ�صĸ���
int LengthStack(stack *s);
//ջ��Ԫ��
DataType TopStack(stack *s);

//����ƥ��
void MatchBrackets(stack *s,char arr[]);