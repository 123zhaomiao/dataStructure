#include"Heap.h"

void Test()
{
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	Heap hp;
	//≥ı ºªØ∂—
	InitHeap(&hp, array, sizeof(array) / sizeof(array[0]));
	//¥¥Ω®∂—
	CreateHeap(&hp, array, sizeof(array) / sizeof(array[0]));
	//≤Â»Î∂—
	InsertHeap(&hp, 4);
	//¥Ú”°∂—
	PrintHeap(&hp);
	//…æ≥˝∂—∂•
	DeleteHeap(&hp);
	//¥Ú”°∂—
	PrintHeap(&hp);
	//∂—≈≈–Ú
	SortHeap(&hp);
	//¥Ú”°∂—
	PrintHeap(&hp);
	//œ˙ªŸ∂—
	DestroyHeap(&hp);
}
int main()
{
	Test();
	system("pause");
	return 0;
}