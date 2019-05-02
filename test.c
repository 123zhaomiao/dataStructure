#include"BSTree.h"

void TestBSTree()
{
	BSTree *BStree;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	int i = 0;
	//��ʼ������������
	InitBSTree(&BStree);
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		//����
		InsertBSTree(&BStree, a[i]);
	}
	//����
	InsertBSTree(&BStree, 10);
	//�������
	InOrder(BStree);
	printf("\n");
	//����
	if (FindBSTree(BStree, 1))
	{
		printf("�ҵ��ˣ�\n");
	}
	else
	{
		printf("û�ҵ�!\n");
	}
	//����
	if (FindBSTree(BStree, -1))
	{
		printf("�ҵ��ˣ�\n");
	}
	else
	{
		printf("û�ҵ�!\n");
	}
	//ɾ��
	DeleteBSTree(&BStree, 5);
	//ɾ��
	DeleteBSTree(&BStree, 3);
	//�������
	InOrder(BStree);
	printf("\n");
	//�ݻ�
	DestroyBSTree(&BStree);
}

int main()
{
	TestBSTree();
	system("pause");
	return 0;
}