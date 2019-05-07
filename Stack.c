#include"Stack.h"


//��ʼ��
void InitStack(stack *ps)
{
	assert(ps);
	ps->top = 0;
	memset(ps->data, 0, Max*sizeof(DataType));
}

//ջΪ��
int StackEmpty(stack *ps)
{
	assert(ps);
	return ps->top == 0;
}
//ջ��Ԫ��
DataType StackTop(stack *ps)
{
	assert(ps);
	return ps->data[ps->top - 1];
}

//��ջ
void PushStack(stack *s, stack *mins, DataType d)
{
	assert(s);
	assert(mins);
	s->data[s->top++] = d;
	//����СֵջΪ�գ�����Ҫ��������ݱ���Сֵ��ջ��Ԫ��С����Ҳ����Сֵջ
	if (StackEmpty(mins)||d <= StackTop(mins))
	{
		mins->data[mins->top++] = d;
	}
}
//ջ��Сֵ
DataType MinStack(stack *mins)
{
	assert(mins);
	return mins->data[mins->top - 1];
}

//��ջ
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