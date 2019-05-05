#include"BSTword.h"

void TestBSWordTree()
{
	BSWordTree *BSTree;
	char a[10] = { 0 };
	//初始化   sss
	InitBSWordTree(&BSTree);
	InsertBSWordTree(&BSTree,"love","爱");
	InsertBSWordTree(&BSTree, "hate", "讨厌");
	InsertBSWordTree(&BSTree, "learn", "学习");
	InsertBSWordTree(&BSTree, "english", "英语");
	InsertBSWordTree(&BSTree, "math", "数学");
	while (1)
	{
		printf("请输入想要查询的单词：");
		scanf("%s", &a);
		if (FindBSWordTree(BSTree, a))
		{
			printf("您查询的单词意思为：%s\n", FindBSWordTree(BSTree, a));
		}
		else
		{
			printf("没有找到!\n");
		}
	}
}
int main()
{
	TestBSWordTree();
	system("pause");
	return 0;
}