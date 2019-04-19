#include"HashBucket.h"

void Test()
{
	HashBucket hashbucket;
	//初始化
	InitHashBucket(&hashbucket);
	//插入
	InsertHashBucket(&hashbucket, 5);
	InsertHashBucket(&hashbucket, 12);
	InsertHashBucket(&hashbucket, 2);
	InsertHashBucket(&hashbucket, 6);
	InsertHashBucket(&hashbucket, 22);
	InsertHashBucket(&hashbucket, 16);
	InsertHashBucket(&hashbucket, 3);
	//删除
	DeleteHashBucket(&hashbucket, 2);
	//查找
	if (FindHashBucket(&hashbucket, 22))
	{
		printf("该元素存在!\n");
	}
	else
	{
		printf("找不到该元素!\n");
	}
	printf("Size=%d\n", SizeHashBucket(&hashbucket));
}
int main()
{
	Test();
	system("pause");
	return 0;
}
