#include"Stack.h"

int main()
{
	stack s;
	stack mins;
	DataType min = 0;
	InitStack(&s);
	InitStack(&mins);

	PushStack(&s, &mins, 1);
	PushStack(&s, &mins, 2);
	PushStack(&s, &mins, 3);
	PushStack(&s, &mins, 4);
	PushStack(&s, &mins, 1);

	min = MinStack(&mins);
	printf("栈中最小值 = %d\n", min);

	PopStack(&s,&mins);
	PopStack(&s, &mins);
	PopStack(&s, &mins);
	PopStack(&s, &mins);
	PopStack(&s, &mins);
	system("pause");
	return 0;

}