#include"MatchBrackets.h"





void Test()
{
	
	int ret = 0;
	stack s;
	StackInit(&s);
	PushStack(&s, 1);
	PushStack(&s, 2);
	PushStack(&s, 3);
	PushStack(&s, 4);
	printf("length=%d\n", LengthStack(&s));
	printf("ջ��Ԫ��Ϊ��%d\n", TopStack(&s));
	PopStack(&s);
	PopStack(&s);
	PopStack(&s);
	printf("length=%d\n", LengthStack(&s));
	ret = EmptyStack(&s);
	if (ret == 1)
	{
		printf("ջ�գ�\n");
	}
	else
	{
		printf("ջ����!\n");
	}
}


//����ƥ��
void TestMatchBrackets()
{
	stack s;
	StackInit(&s);
	char a[] = "(())abc{[(])}";
	char b[] = "(()))abc{[]}";
	char c[] = "(()()abc{[]}";
	char d[] = "(())abc{[]()}";
	MatchBrackets(&s, a);
	MatchBrackets(&s, b);
	MatchBrackets(&s, c);
	MatchBrackets(&s, d);
}
int main()
{
	//Test();
	//TestMatchBrackets();
	system("pause");
	return 0;
}