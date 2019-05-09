#include"HashTable.h"


void Test()
{
	HashTable hashtable;
	//初始化哈希表
	InitHashTable(&hashtable);
	//插入哈希表
	InsertHashTable(&hashtable, "喵喵");
	InsertHashTable(&hashtable, "旺旺");
	InsertHashTable(&hashtable, "吼吼");
	InsertHashTable(&hashtable, "嘿嘿");
	InsertHashTable(&hashtable, "喵喵喵");
	//删除哈希表
	DeleteHashTable(&hashtable, "旺旺");


	InsertHashTable(&hashtable, "恐龙");
	InsertHashTable(&hashtable, "abc");
	InsertHashTable(&hashtable, "def");
	InsertHashTable(&hashtable, "acd");

	//删除哈希表
	DeleteHashTable(&hashtable, "def");


	//查找
	if (FindHashTable(&hashtable, "abc") != -1)
	{
		printf("abc 的哈希地址为：%d\n", FindHashTable(&hashtable, "abc"));
	}
	else
	{
		printf("没有找到!\n");
	}
	printf("哈希表元素个数：%d\n", SizeHashTable(&hashtable));

	//判空
	if (EmptyHashTable(&hashtable))
	{
		printf("哈希表为空!\n");
	}
	else
	{
		printf("哈希表不为空!\n");
	}
	print(&hashtable);
	//销毁哈希表
	DestroyHashTable(&hashtable);

}
int main()
{
	Test();
	system("pause");
	return 0;
}
