#include"Heap.h"

void Test()
{
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	Heap hp;
	//��ʼ����
	InitHeap(&hp, array, sizeof(array) / sizeof(array[0]));
	//������
	CreateHeap(&hp, array, sizeof(array) / sizeof(array[0]));
	//�����
	InsertHeap(&hp, 4);
	//��ӡ��
	PrintHeap(&hp);
	//ɾ���Ѷ�
	DeleteHeap(&hp);
	//��ӡ��
	PrintHeap(&hp);
	//������
	SortHeap(&hp);
	//��ӡ��
	PrintHeap(&hp);
	//���ٶ�
	DestroyHeap(&hp);
}
int main()
{
	Test();
	system("pause");
	return 0;
}