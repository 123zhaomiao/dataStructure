#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdio.h>
//��װ��̬ջ
#define MAX 20
typedef struct s
{
	int arr[MAX];
	int top;
}stack;
//ö��
enum Calc
{
	ADD,
	SUB,
	MUL,
	DIV,
	DATA
};
//����
typedef struct operate
{
	enum calc op;
	int _data;
}operate;
//ջ��ʼ��
void StackInit(stack *s);
//ջ��Ԫ��
int TopStack(stack *s);
//��ջ
void PopStack(stack *s);
//�沨�����ʽ�����
int CalcRPN(operate *cal, stack *s,int size);