#include"BSTree.h"

void TestBSTree()
{
	BSTree *BStree;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	int i = 0;
	//初始化二叉搜索树
	InitBSTree(&BStree);
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		//插入
		InsertBSTree(&BStree, a[i]);
	}
	//插入
	InsertBSTree(&BStree, 10);
	//中序遍历
	InOrder(BStree);
	printf("\n");
	//查找
	if (FindBSTree(BStree, 1))
	{
		printf("找到了！\n");
	}
	else
	{
		printf("没找到!\n");
	}
	//查找
	if (FindBSTree(BStree, -1))
	{
		printf("找到了！\n");
	}
	else
	{
		printf("没找到!\n");
	}
	//删除
	DeleteBSTree(&BStree, 5);
	//删除
	DeleteBSTree(&BStree, 3);
	//中序遍历
	InOrder(BStree);
	printf("\n");
	//摧毁
	DestroyBSTree(&BStree);
}

int main()
{
	TestBSTree();
	system("pause");
	return 0;
}
