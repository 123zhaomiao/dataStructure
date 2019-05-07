#include"MatchBrackets.h"


//初始化
void StackInit(stack *s)
{
	assert(s);
	s->top = 0;
	memset(s->data,0, 20 * sizeof(DataType));
}

//压栈
void PushStack(stack *s,DataType d)
{
	assert(s);
	if (s->top >= Max)
	{
		printf("栈已满！\n");
		return;
	}
	//入栈
	s->data[s->top] = d;
	//栈容量
	s->top++;
}

//栈中元素的个数
int LengthStack(stack *s)
{
	assert(s);
	return s->top;
}

//栈顶元素
DataType TopStack(stack *s)
{
	assert(s);
	return s->data[s->top - 1];
}

//出栈
void PopStack(stack *s)
{
	assert(s);
	s->top--;
}

//栈是否为空
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


//括号匹配
void MatchBrackets(stack *s,char arr[])
{
	int i = 0;
	int len = strlen(arr);
	char top;
	//初始化栈
	StackInit(s);
	for (i = 0; i < len; i++)
	{
		//判断是否是括号
		if (IsMatch(arr[i]))
		{
			//判断括号为左括号还是右括号
			if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
			{
				//栈为空，右括号多于左括号
				if (EmptyStack(s))
				{
					printf("右括号多于左括号！\n");
					return;
				}
				//不为空，取栈顶元素，判断是否匹配
				else
				{
					top = TopStack(s);
					if (!((arr[i] == ')'&&top == '(') || (arr[i] == ']'&&top == '[') || (arr[i] == '}'&&top == '{')))
					{
						printf("左右括号次序不匹配\n");
						return;
					}
					else
						PopStack(s);
				}
			}
			else
			{
				//左括号
				PushStack(s, arr[i]);
			}
		}
	}
	if (EmptyStack(s))
	{
		printf("左右括号正确匹配!\n");
		return;
	}
	else
	{
		printf("左括号多于右括号！\n");
		return;
	}
}
