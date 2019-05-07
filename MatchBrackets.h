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


//初始化
void StackInit(stack *s);
//压栈
void PushStack(stack *s,DataType d);
//出栈
void PopStack(stack *s);
//栈是否为空
int EmptyStack(stack *s);
//栈中元素的个数
int LengthStack(stack *s);
//栈顶元素
DataType TopStack(stack *s);

//括号匹配
void MatchBrackets(stack *s,char arr[]);