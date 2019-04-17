#include"SharedStack.h"
void TestSharedStack()
{

	sharedstack s;
	//共享栈初始化
	InitShared(&s);

	//栈1入栈
	PushSharedStack(&s, 1, 1);
	PushSharedStack(&s, 2, 1);
	PushSharedStack(&s, 3, 1);
	PushSharedStack(&s, 4, 1);

	//栈2入栈
	PushSharedStack(&s, 5, 2);
	PushSharedStack(&s, 6, 2);
	PushSharedStack(&s, 7, 2);
	PushSharedStack(&s, 8, 2);

	//栈1栈顶
	printf("栈1栈顶=%d\n", SharedStackTop(&s,1));
	//栈2栈顶
	printf("栈2栈顶=%d\n", SharedStackTop(&s, 2));
	//栈1长短
	printf("栈1长=%d\n", SharedStackSize(&s, 1));
	//栈2长短
	printf("栈2长=%d\n", SharedStackSize(&s, 2));


	//栈1出栈
	PopSharedStack(&s, 1);
	PopSharedStack(&s, 1);
	//栈2出栈
	PopSharedStack(&s, 2);
	//栈1栈顶
	printf("栈1栈顶=%d\n", SharedStackTop(&s, 1));
	//栈2栈顶
	printf("栈2栈顶=%d\n", SharedStackTop(&s, 2));
	//栈1长短
	printf("栈1长=%d\n", SharedStackSize(&s, 1));
	//栈2长短
	printf("栈2长=%d\n", SharedStackSize(&s, 2));
}
int main()
{
	TestSharedStack();
	system("pause");
	return 0;
}
