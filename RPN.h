#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdio.h>
//包装静态栈
#define MAX 20
typedef struct s
{
	int arr[MAX];
	int top;
}stack;
//枚举
enum Calc
{
	ADD,
	SUB,
	MUL,
	DIV,
	DATA
};
//操作
typedef struct operate
{
	enum calc op;
	int _data;
}operate;
//栈初始化
void StackInit(stack *s);
//栈顶元素
int TopStack(stack *s);
//出栈
void PopStack(stack *s);
//逆波兰表达式的求解
int CalcRPN(operate *cal, stack *s,int size);