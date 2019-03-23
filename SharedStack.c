#include"SharedStack.h"
//¹²ÏíÕ»³õÊ¼»¯
void InitShared(sharedstack *s)
{
	assert(s);
	s->top1 = 0;
	s->top2 = Max - 1;
	memset(s->data, 0, Max*sizeof(DataType));
}
//ÈëÕ»
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
			printf("Õ»ÒÑÂú£¡\n");
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
			printf("Õ»ÒÑÂú£¡\n");
			return;
		}
	}
}

//Õ»¶¥
DataType SharedStackTop(sharedstack *s, int which)
{
	assert(s);
	if (which == 1)
	{
		if (s->top1 == 0)
		{
			printf("Õ»¿Õ£¡\n");
			return -1;
		}
		else
			return s->data[s->top1 - 1];
	}
	else
	{
		if (s->top2 == Max-1)
		{
			printf("Õ»¿Õ£¡\n");
			return -1;
		}
		else
			return s->data[s->top2 + 1];
	}
}

//Õ»³¤¶Ì
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

//³öÕ»
void PopSharedStack(sharedstack *s, int which)
{
	assert(s); 
	if (which == 1)
	{
		if (s->top1 == 0)
		{
			printf("Õ»¿Õ£¡\n");
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
			printf("Õ»¿Õ£¡\n");
			return;
		}
		else
		{
			s->top2++;
		}
	}
}