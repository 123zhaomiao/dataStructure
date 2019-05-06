#include"RPN.h"

//栈初始化
void StackInit(stack *s)
{
	assert(s);
	s->top = 0;
	memset(s->arr, 0, MAX*sizeof(int));
}


//数据入栈
void PushStack(stack *s, int data)
{
	assert(s);
	if (s->top > MAX)
	{
		return;
	}
	s->arr[s->top] = data;
	s->top++;
}

//栈顶元素
int TopStack(stack *s)
{
	assert(s);
	return s->arr[s->top - 1];
}

//出栈
void PopStack(stack *s)
{
	assert(s);
	s->top--; 
}


//逆波兰表达式的求解
int CalcRPN(operate *cal, stack *s,int size)
{
	int i = 0;
	int left = 0;
	int right = 0;
	int ch = 0;
	assert(s);
	for (i = 0; i < size; i++)
	{
		if (cal->op == DATA)
		{
			//数据入栈
			PushStack(s,cal->_data);
		}
		else
		{
			ch = cal->op;
			//栈顶元素
			right = TopStack(s);
			//出栈
			PopStack(s);
			left = TopStack(s);
			//出栈
			PopStack(s);
			
			switch (ch)
			{
			case ADD:PushStack(s,left + right);
				break;
			case SUB:PushStack(s, left - right);
				break;
			case MUL:PushStack(s, left * right);
				break;
			case DIV:
				if (right == 0)
				{
					printf("除数为0，非法！！！\n");
					return 0;
				}
				else
				{
	               PushStack(s, left / right);
				}
				break;
			default:printf("操作数非法！！\n"); break;
			}
		}
		cal++;
	}
	return TopStack(s);
}
