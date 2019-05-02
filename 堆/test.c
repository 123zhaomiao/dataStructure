#include"Heap.h"

void Test()
{
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	Heap hp;
	//³õÊ¼»¯¶Ñ
	InitHeap(&hp, array, sizeof(array) / sizeof(array[0]));
	//´´½¨¶Ñ
	CreateHeap(&hp, array, sizeof(array) / sizeof(array[0]));
	//²åÈë¶Ñ
	InsertHeap(&hp, 4);
	//´òÓ¡¶Ñ
	PrintHeap(&hp);
	//É¾³ý¶Ñ¶¥
	DeleteHeap(&hp);
	//´òÓ¡¶Ñ
	PrintHeap(&hp);
	//¶ÑÅÅÐò
	SortHeap(&hp);
	//´òÓ¡¶Ñ
	PrintHeap(&hp);
	//Ïú»Ù¶Ñ
	DestroyHeap(&hp);
}
int main()
{
	Test();
	system("pause");
	return 0;
}
