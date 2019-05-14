
#include"BSTipadd.h"
void TestBSIpadd()
{
	BSIpTree *BSTree;
	InitBSIpTree(&BSTree);
	InsertBSIpTree(&BSTree, "192.168.0.224", 1);
}
int main()
{
	TestBSIpadd();
	system("pause");
	return 0;
}
