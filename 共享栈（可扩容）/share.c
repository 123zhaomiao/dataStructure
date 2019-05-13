#include"share.h"


//共享栈初始化
void InitShared(sharedstack *s)
{
	assert(s);
	s->capacity = 5;
	s->top1 = 0;
	s->top2 = s->capacity - 1;
	s->data = (DataType *)malloc(s->capacity*sizeof(DataType));
}
//扩容
void ExpandCapacity(sharedstack *s)
{
	DataType *Newnode = NULL;
	int newcapacity = 0;
	int i = 0;
	if (s->top1 <= s->top2)
	{
		//不用扩容，直接返回
		return ;
	}
	newcapacity = s->capacity * 2;
	Newnode = (DataType*)malloc(newcapacity*sizeof(DataType));
	if (Newnode == NULL)
	{
		printf("新空间开辟失败！\n");
		return ;
	}
	//搬移栈1元素
	for (i = 0; i < s->top1; i++)
	{
		Newnode[i] = s->data[i];
	}
	//搬移栈2元素
	for (i = s->capacity - 1; i>s->top2; i--)
	{
		Newnode[i+s->capacity]=s->data[i];
	}
	//改变栈2的栈顶和容量
	s->top2 = s->top2 + s->capacity;
	s->capacity = newcapacity;

	//释放之前的空间
	free(s->data);
	s->data = Newnode;
}
//入栈
void PushSharedStack(sharedstack *s, DataType d, int which)
{
	assert(s);
	ExpandCapacity(s);
	if (which == 1)
	{
		s->data[s->top1++] = d;
	}
	else
	{
		s->data[s->top2--] = d;
	}
}
//出栈
void PopSharedStack(sharedstack *s, int which)
{
	assert(s);
	if (which == 1)
	{
		if (s->top1 == 0)
		{
			printf("栈1空！\n");
			return;
		}
		else
		{
			s->top1--;
		}
	}
	else
	{
		if (s->top2 == s->capacity - 1)
		{
			printf("栈2空！\n");
			return;
		}
		else
		{
			s->top2++;
		}
	}
}
//栈顶元素
DataType SharedStackTop(sharedstack *s, int which)
{
	assert(s);
	if (which == 1)
	{
		if (s->top1 == 0)
		{
			printf("栈1空！\n");
			return -1;
		}
		else
			return s->data[s->top1 - 1];
	}
	else
	{
		if (s->top2 == s->capacity - 1)
		{
			printf("栈2空！\n");
			return -1;
		}
		else
			return s->data[s->top2 + 1];
	}
}
//栈长短
int SharedStackSize(sharedstack *s, int which)
{
	assert(s);
	if (which == 1)
	{
		return s->top1;
	}
	else
		return s->capacity - s->top2 - 1;
}
