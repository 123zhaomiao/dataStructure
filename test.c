#include"share.h"

void TestSharedStack()
{

	sharedstack s;
	//����ջ��ʼ��
	InitShared(&s);

	//ջ1��ջ
	PushSharedStack(&s, 1, 1);
	PushSharedStack(&s, 2, 1);
	PushSharedStack(&s, 3, 1);
	PushSharedStack(&s, 4, 1);

	//ջ2��ջ
	PushSharedStack(&s, 5, 2);
	PushSharedStack(&s, 6, 2);
	PushSharedStack(&s, 7, 2);
	PushSharedStack(&s, 8, 2);

	//ջ1ջ��
	printf("ջ1ջ��=%d\n", SharedStackTop(&s, 1));
	//ջ2ջ��
	printf("ջ2ջ��=%d\n", SharedStackTop(&s, 2));
	//ջ1����
	printf("ջ1��=%d\n", SharedStackSize(&s, 1));
	//ջ2����
	printf("ջ2��=%d\n", SharedStackSize(&s, 2));


	//ջ1��ջ
	PopSharedStack(&s, 1);
	PopSharedStack(&s, 1);
	//ջ2��ջ
	PopSharedStack(&s, 2);

	//ջ1ջ��
	printf("ջ1ջ��=%d\n", SharedStackTop(&s, 1));
	//ջ2ջ��
	printf("ջ2ջ��=%d\n", SharedStackTop(&s, 2));
	//ջ1����
	printf("ջ1��=%d\n", SharedStackSize(&s, 1));
	//ջ2����
	printf("ջ2��=%d\n", SharedStackSize(&s, 2));
}
int main()
{
	TestSharedStack();
	system("pause");
	return 0;
}