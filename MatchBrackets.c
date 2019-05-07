#include"MatchBrackets.h"


//≥ı ºªØ
void StackInit(stack *s)
{
	assert(s);
	s->top = 0;
	memset(s->data,0, 20 * sizeof(DataType));
}

//—π’ª
void PushStack(stack *s,DataType d)
{
	assert(s);
	if (s->top >= Max)
	{
		printf("’ª“—¬˙£°\n");
		return;
	}
	//»Î’ª
	s->data[s->top] = d;
	//’ª»›¡ø
	s->top++;
}

//’ª÷–‘™Àÿµƒ∏ˆ ˝
int LengthStack(stack *s)
{
	assert(s);
	return s->top;
}

//’ª∂•‘™Àÿ
DataType TopStack(stack *s)
{
	assert(s);
	return s->data[s->top - 1];
}

//≥ˆ’ª
void PopStack(stack *s)
{
	assert(s);
	s->top--;
}

//’ª «∑ÒŒ™ø’
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


//¿®∫≈∆•≈‰
void MatchBrackets(stack *s,char arr[])
{
	int i = 0;
	int len = strlen(arr);
	char top;
	//≥ı ºªØ’ª
	StackInit(s);
	for (i = 0; i < len; i++)
	{
		//≈–∂œ «∑Ò «¿®∫≈
		if (IsMatch(arr[i]))
		{
			//≈–∂œ¿®∫≈Œ™◊Û¿®∫≈ªπ «”“¿®∫≈
			if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
			{
				//’ªŒ™ø’£¨”“¿®∫≈∂‡”⁄◊Û¿®∫≈
				if (EmptyStack(s))
				{
					printf("”“¿®∫≈∂‡”⁄◊Û¿®∫≈£°\n");
					return;
				}
				//≤ªŒ™ø’£¨»°’ª∂•‘™Àÿ£¨≈–∂œ «∑Ò∆•≈‰
				else
				{
					top = TopStack(s);
					if (!((arr[i] == ')'&&top == '(') || (arr[i] == ']'&&top == '[') || (arr[i] == '}'&&top == '{')))
					{
						printf("◊Û”“¿®∫≈¥Œ–Ú≤ª∆•≈‰\n");
						return;
					}
					else
						PopStack(s);
				}
			}
			else
			{
				//◊Û¿®∫≈
				PushStack(s, arr[i]);
			}
		}
	}
	if (EmptyStack(s))
	{
		printf("◊Û”“¿®∫≈’˝»∑∆•≈‰!\n");
		return;
	}
	else
	{
		printf("◊Û¿®∫≈∂‡”⁄”“¿®∫≈£°\n");
		return;
	}
}