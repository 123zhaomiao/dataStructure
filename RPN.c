#include"RPN.h"

//ջ��ʼ��
void StackInit(stack *s)
{
	assert(s);
	s->top = 0;
	memset(s->arr, 0, MAX*sizeof(int));
}


//������ջ
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

//ջ��Ԫ��
int TopStack(stack *s)
{
	assert(s);
	return s->arr[s->top - 1];
}

//��ջ
void PopStack(stack *s)
{
	assert(s);
	s->top--; 
}


//�沨�����ʽ�����
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
			//������ջ
			PushStack(s,cal->_data);
		}
		else
		{
			ch = cal->op;
			//ջ��Ԫ��
			right = TopStack(s);
			//��ջ
			PopStack(s);
			left = TopStack(s);
			//��ջ
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
					printf("����Ϊ0���Ƿ�������\n");
					return 0;
				}
				else
				{
	               PushStack(s, left / right);
				}
				break;
			default:printf("�������Ƿ�����\n"); break;
			}
		}
		cal++;
	}
	return TopStack(s);
}