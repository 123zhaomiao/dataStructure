#include"share.h"

void TestSharedStack()
{

	sharedstack s;
	//π≤œÌ’ª≥ı ºªØ
	InitShared(&s);

	//’ª1»Î’ª
	PushSharedStack(&s, 1, 1);
	PushSharedStack(&s, 2, 1);
	PushSharedStack(&s, 3, 1);
	PushSharedStack(&s, 4, 1);

	//’ª2»Î’ª
	PushSharedStack(&s, 5, 2);
	PushSharedStack(&s, 6, 2);
	PushSharedStack(&s, 7, 2);
	PushSharedStack(&s, 8, 2);

	//’ª1’ª∂•
	printf("’ª1’ª∂•=%d\n", SharedStackTop(&s, 1));
	//’ª2’ª∂•
	printf("’ª2’ª∂•=%d\n", SharedStackTop(&s, 2));
	//’ª1≥§∂Ã
	printf("’ª1≥§=%d\n", SharedStackSize(&s, 1));
	//’ª2≥§∂Ã
	printf("’ª2≥§=%d\n", SharedStackSize(&s, 2));


	//’ª1≥ˆ’ª
	PopSharedStack(&s, 1);
	PopSharedStack(&s, 1);
	//’ª2≥ˆ’ª
	PopSharedStack(&s, 2);

	//’ª1’ª∂•
	printf("’ª1’ª∂•=%d\n", SharedStackTop(&s, 1));
	//’ª2’ª∂•
	printf("’ª2’ª∂•=%d\n", SharedStackTop(&s, 2));
	//’ª1≥§∂Ã
	printf("’ª1≥§=%d\n", SharedStackSize(&s, 1));
	//’ª2≥§∂Ã
	printf("’ª2≥§=%d\n", SharedStackSize(&s, 2));
}
int main()
{
	TestSharedStack();
	system("pause");
	return 0;
}