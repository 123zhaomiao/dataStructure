#include"TwoStack_Queeue.h"

void Test2StackToQueue()
{
	queue q;
	InitQueue(&q);

	PushQueue(&q, 1);
	PushQueue(&q, 2);
	PushQueue(&q, 3);
	PushQueue(&q, 4);
	PushQueue(&q, 5);
	printf("%d\n", SizeQueue(&q));
	printf("队尾 = %d\n", QueueBack(&q));
	printf("队头 = %d\n", QueueFront(&q));

	PopQueue(&q);
	PushQueue(&q, 5);
	PushQueue(&q, 6);
	printf("%d\n", SizeQueue(&q));
	printf("队尾 = %d\n", QueueBack(&q));
	printf("队头 = %d\n", QueueFront(&q));

}
int main()
{
	Test2StackToQueue();
	system("pause");
	return 0;
}