#include"BSTword.h"

void TestBSWordTree()
{
	BSWordTree *BSTree;
	char a[10] = { 0 };
	//��ʼ��   sss
	InitBSWordTree(&BSTree);
	InsertBSWordTree(&BSTree,"love","��");
	InsertBSWordTree(&BSTree, "hate", "����");
	InsertBSWordTree(&BSTree, "learn", "ѧϰ");
	InsertBSWordTree(&BSTree, "english", "Ӣ��");
	InsertBSWordTree(&BSTree, "math", "��ѧ");
	while (1)
	{
		printf("��������Ҫ��ѯ�ĵ��ʣ�");
		scanf("%s", &a);
		if (FindBSWordTree(BSTree, a))
		{
			printf("����ѯ�ĵ�����˼Ϊ��%s\n", FindBSWordTree(BSTree, a));
		}
		else
		{
			printf("û���ҵ�!\n");
		}
	}
}
int main()
{
	TestBSWordTree();
	system("pause");
	return 0;
}