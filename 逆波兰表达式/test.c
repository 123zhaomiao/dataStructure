#include"RPN.h"

void TestRPN()
{
	int size = 0;
	int ret = 0;
	stack s;
	operate  cal[] = { { DATA, 12 }, { DATA, 3 }, { DATA, 4 }, { ADD, 0 }, { MUL, 0 },
	{ DATA, 6 }, { SUB, 0 }, { DATA, 8 }, { DATA, 2 }, { DIV, 0 }, { ADD, 0 } };
	size = sizeof(cal) / sizeof(cal[0]);
	//栈初始化
	StackInit(&s);
	//逆波兰表达式的求解
	ret = CalcRPN(cal,&s,size);
	printf("ret = %d\n", ret);
}

int main()
{

	TestRPN();
	system("pause");
	return 0;
}
