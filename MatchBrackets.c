#include"MatchBrackets.h"


//��ʼ��
void StackInit(stack *s)
{
	assert(s);
	s->top = 0;
	memset(s->data,0, 20 * sizeof(DataType));
}

//ѹջ
void PushStack(stack *s,DataType d)
{
	assert(s);
	if (s->top >= Max)
	{
		printf("ջ������\n");
		return;
	}
	//��ջ
	s->data[s->top] = d;
	//ջ����
	s->top++;
}

//ջ��Ԫ�صĸ���
int LengthStack(stack *s)
{
	assert(s);
	return s->top;
}

//ջ��Ԫ��
DataType TopStack(stack *s)
{
	assert(s);
	return s->data[s->top - 1];
}

//��ջ
void PopStack(stack *s)
{
	assert(s);
	s->top--;
}

//ջ�Ƿ�Ϊ��
int EmptyStack(stack *s)
{
	assert(s);
	return s->top == 0;
}


int IsMatch(char ch)
{
	if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']')
		return 1;
	else
		return 0;
} 


//����ƥ��
void MatchBrackets(stack *s,char arr[])
{
	int i = 0;
	int len = strlen(arr);
	char top;
	//��ʼ��ջ
	StackInit(s);
	for (i = 0; i < len; i++)
	{
		//�ж��Ƿ�������
		if (IsMatch(arr[i]))
		{
			//�ж�����Ϊ�����Ż���������
			if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
			{
				//ջΪ�գ������Ŷ���������
				if (EmptyStack(s))
				{
					printf("�����Ŷ��������ţ�\n");
					return;
				}
				//��Ϊ�գ�ȡջ��Ԫ�أ��ж��Ƿ�ƥ��
				else
				{
					top = TopStack(s);
					if (!((arr[i] == ')'&&top == '(') || (arr[i] == ']'&&top == '[') || (arr[i] == '}'&&top == '{')))
					{
						printf("�������Ŵ���ƥ��\n");
						return;
					}
					else
						PopStack(s);
				}
			}
			else
			{
				//������
				PushStack(s, arr[i]);
			}
		}
	}
	if (EmptyStack(s))
	{
		printf("����������ȷƥ��!\n");
		return;
	}
	else
	{
		printf("�����Ŷ��������ţ�\n");
		return;
	}
}