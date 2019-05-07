#include"Stack.h"


//初始化
void InitStack(stack *ps)
{
	assert(ps);
	ps->top = 0;
	memset(ps->data, 0, Max*sizeof(DataType));
}

//栈为空
int StackEmpty(stack *ps)
{
	assert(ps);
	return ps->top == 0;
}
//栈顶元素
DataType StackTop(stack *ps)
{
	assert(ps);
	return ps->data[ps->top - 1];
}

//入栈
void PushStack(stack *s, stack *mins, DataType d)
{
	assert(s);
	assert(mins);
	s->data[s->top++] = d;
	//若最小值栈为空，或者要插入的数据比最小值的栈顶元素小，则也入最小值栈
	if (StackEmpty(mins)||d <= StackTop(mins))
	{
		mins->data[mins->top++] = d;
	}
}
//栈最小值
DataType MinStack(stack *mins)
{
	assert(mins);
	return mins->data[mins->top - 1];
}

//出栈
void PopStack(stack *s, stack *mins)
{
	assert(s);
	assert(mins);
	if (StackEmpty(s))
		return;
	if (StackTop(s) == StackTop(mins))
	{
		mins->top--;
	}
	s->top--;
}
