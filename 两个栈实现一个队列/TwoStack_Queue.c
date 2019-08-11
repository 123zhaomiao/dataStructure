#include"TwoStack_Queeue.h"
//1.初始化栈
 void InitStack(stack *s)
{
	assert(s);
	s->top = 0;
	memset(s->data, 0, Max*sizeof(Datatype));
}
//1.初始化队列
void InitQueue(queue *q)
{
	assert(q);
	InitStack(&q->s1);
	InitStack(&q->s2);
}



//入栈1
void PushStack(stack *s, Datatype d)
{
	assert(s);
	if (s->top >= Max)
	{
		printf("队列已满!\n");
		return;
	}
	s->data[s->top++] = d;
}
//入队列(入栈1)
void PushQueue(queue *q, Datatype d)
{
	assert(q);
	//入栈1
	PushStack(&q->s1, d);
}


//栈元素个数
int SizeStack(stack *s)
{
	assert(s);
	return s->top;
}
//队列元素个数
int SizeQueue(queue *q)
{
	assert(q);
	return SizeStack(&q->s1) + SizeStack(&q->s2);
}


//栈空
int EmptyStack(stack *s)
{
	assert(s);
	return 0 == s->top;
}
//队列空
int EmptyQueue(queue *q)
{
	assert(q);
	return EmptyStack(&q->s1) && EmptyStack(&q->s2);
}


//出栈
 void PopStack(stack *s)
{
	assert(s);
	if (s->top == 0)
		return;
	s->top--;
}
//返回栈顶元素
Datatype TopStack(stack *s)
{
	assert(s);
	return s->data[s->top - 1];
}
//出队列
void PopQueue(queue *q)
{
	assert(q);
	if (EmptyQueue(q))
	{
		printf("队列为空!\n");
		return;
	}
	//如果栈2为空，将栈1中的元素移入栈2
	if (EmptyStack(&q->s2))
	{
		while (!EmptyStack(&q->s1))
		{
			PushStack(&q->s2, TopStack(&q->s1));
			PopStack(&q->s1);
		}
	}
	//栈2的栈顶
	PopStack(&q->s2);
}


//队列尾 栈1的栈顶
Datatype QueueBack(queue *q)
{
		assert(q);
		if (EmptyQueue(q))
		{
			printf("队列为空!\n");
			return -1;
		}
		//如果栈1为空，将栈2中的元素移入栈1
		if (EmptyStack(&q->s1))
		{
			while (!EmptyStack(&q->s2))
			{
				PushStack(&q->s1, TopStack(&q->s2));
				PopStack(&q->s2);
			}
		}
		//栈1的栈顶
		return TopStack(&q->s1);
}
//队列头  栈2的栈顶
Datatype QueueFront(queue *q)
{
	assert(q);
	if (EmptyQueue(q))
	{
		printf("队列为空!\n");
		return -1;
	}
	//如果栈1为空，将栈2中的元素移入栈1
	if (EmptyStack(&q->s2))
	{
		while (!EmptyStack(&q->s1))
		{
			PushStack(&q->s2, TopStack(&q->s1));
			PopStack(&q->s1);
		}
	}
	//栈2的栈顶
	return TopStack(&q->s2);
}
