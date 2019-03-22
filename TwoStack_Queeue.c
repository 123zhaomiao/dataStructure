#include"TwoStack_Queeue.h"



//1.��ʼ��ջ
 void InitStack(stack *s)
{
	assert(s);
	s->top = 0;
	memset(s->data, 0, Max*sizeof(Datatype));
}
//1.��ʼ������
void InitQueue(queue *q)
{
	assert(q);
	InitStack(&q->s1);
	InitStack(&q->s2);
}



//��ջ1
void PushStack(stack *s, Datatype d)
{
	assert(s);
	if (s->top >= Max)
	{
		printf("��������!\n");
		return;
	}
	s->data[s->top++] = d;
}
//�����(��ջ1)
void PushQueue(queue *q, Datatype d)
{
	assert(q);
	//��ջ1
	PushStack(&q->s1, d);
}


//ջԪ�ظ���
int SizeStack(stack *s)
{
	assert(s);
	return s->top;
}
//����Ԫ�ظ���
int SizeQueue(queue *q)
{
	assert(q);
	return SizeStack(&q->s1) + SizeStack(&q->s2);
}


//ջ��
int EmptyStack(stack *s)
{
	assert(s);
	return 0 == s->top;
}
//���п�
int EmptyQueue(queue *q)
{
	assert(q);
	return EmptyStack(&q->s1) && EmptyStack(&q->s2);
}


//��ջ
 void PopStack(stack *s)
{
	assert(s);
	if (s->top == 0)
		return;
	s->top--;
}
//����ջ��Ԫ��
Datatype TopStack(stack *s)
{
	assert(s);
	return s->data[s->top - 1];
}
//������
void PopQueue(queue *q)
{
	assert(q);
	if (EmptyQueue(q))
	{
		printf("����Ϊ��!\n");
		return;
	}
	//���ջ2Ϊ�գ���ջ1�е�Ԫ������ջ2
	if (EmptyStack(&q->s2))
	{
		while (!EmptyStack(&q->s1))
		{
			PushStack(&q->s2, TopStack(&q->s1));
			PopStack(&q->s1);
		}
	}
	//ջ2��ջ��
	PopStack(&q->s2);
}


//����β ջ1��ջ��
Datatype QueueBack(queue *q)
{
		assert(q);
		if (EmptyQueue(q))
		{
			printf("����Ϊ��!\n");
			return -1;
		}
		//���ջ1Ϊ�գ���ջ2�е�Ԫ������ջ1
		if (EmptyStack(&q->s1))
		{
			while (!EmptyStack(&q->s2))
			{
				PushStack(&q->s1, TopStack(&q->s2));
				PopStack(&q->s2);
			}
		}
		//ջ1��ջ��
		return TopStack(&q->s1);
}


//����ͷ  ջ2��ջ��
Datatype QueueFront(queue *q)
{
	assert(q);
	if (EmptyQueue(q))
	{
		printf("����Ϊ��!\n");
		return -1;
	}
	//���ջ1Ϊ�գ���ջ2�е�Ԫ������ջ1
	if (EmptyStack(&q->s2))
	{
		while (!EmptyStack(&q->s1))
		{
			PushStack(&q->s2, TopStack(&q->s1));
			PopStack(&q->s1);
		}
	}
	//ջ2��ջ��
	return TopStack(&q->s2);
}