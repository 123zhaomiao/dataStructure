#include"SharedStack.h"
//共享栈初始化
void InitShared(sharedstack *s)
{
	assert(s);
	s->top1 = 0;
	s->top2 = Max - 1;
	memset(s->data, 0, Max*sizeof(DataType));
}
//入栈
void PushSharedStack(sharedstack *s, DataType d, int which)
{
	assert(s);
	if (which == 1)
	{
		if (s->top1 <= s->top2)
		{
			s->data[s->top1++] = d;
		}
		else
		{
			printf("栈已满！\n");
			return;
		}
	}
	else
	{
		if (s->top1 <= s->top2)
		{
			s->data[s->top2--] = d;
		}
		else
		{
			printf("栈已满！\n");
			return;
		}
	}
}

//栈顶
DataType SharedStackTop(sharedstack *s, int which)
{
	assert(s);
	if (which == 1)
	{
		if (s->top1 == 0)
		{
			printf("栈空！\n");
			return -1;
		}
		else
			return s->data[s->top1 - 1];
	}
	
	else
	{
		if (s->top2 == Max-1)
		{
			printf("栈空！\n");
			return -1;
		}
		else
			return s->data[s->top2 + 1];
	}
}

//栈长短
DataType SharedStackSize(sharedstack *s, int which)
{
	assert(s);
	if (which == 1)
	{
		return s->top1;
	}
	else
		return Max - s->top2 - 1;
}

//出栈
void PopSharedStack(sharedstack *s, int which)
{
	assert(s); 
	if (which == 1)
	{
		if (s->top1 == 0)
		{
			printf("栈空！\n");
			return;
		}
		else
		{
			s->top1--;
		}
	}
	else
	{
		if (s->top2 == Max-1)
		{
			printf("栈空！\n");
			return;
		}
		else
		{
			s->top2++;
		}
	}
}
