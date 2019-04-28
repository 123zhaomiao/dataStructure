
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
typedef int DataType;
typedef struct LinkList
{
	DataType _d;
	struct LinkList *next;
}linklist;
#define MAX 10
typedef struct HashBucket
{
	linklist *data[MAX];
	int size;
}HashBucket;
//初始化哈希桶
void InitHashBucket(HashBucket *hashbucket);
//插入
void InsertHashBucket(HashBucket *hashbucket,  DataType d);
//删除
void DeleteHashBucket(HashBucket *hashbucket, DataType d);
//查找
int FindHashBucket(HashBucket *hashbucket, DataType d);
int SizeHashBucket(HashBucket* hashbucket);

////////////////////////////////////////////////////////////////////////////////
//初始化哈希桶
void InitHashBucket(HashBucket *hashbucket)
{
	assert(hashbucket);
	int i = 0;
	for (i = 0; i < MAX; i++)
	{
		hashbucket->data[i] = NULL;
	}
	hashbucket->size = 0;
}
//哈希函数
int HashFun( DataType d)
{
	return d % MAX;
}
linklist *BuyNode(DataType d)
{
	linklist *node = (linklist *)malloc(sizeof(linklist));
	if (node == NULL)
	{
		assert(0);
		return NULL;
	}
	node->_d = d;
	node->next = NULL;
	return node;
}
//插入
void InsertHashBucket(HashBucket *hashbucket , DataType d)
{
	int addr = 0;
	linklist *node = NULL;
	assert(hashbucket);
	addr = HashFun(d);
	node = BuyNode(d);
	if (hashbucket->data[addr] == NULL)
	{
		//头插法
		hashbucket->data[addr] = node;
		hashbucket->size++;
	}
	else
	{
		node->next = hashbucket->data[addr];
		hashbucket->data[addr] = node;
		hashbucket->size++;
	}
}

//删除
void DeleteHashBucket(HashBucket *hashbucket, DataType d)
{
	int addr = 0;
	//被删除的结点的结点
	linklist *del = NULL;
	//被删除结点的上一个结点
	linklist *cur = NULL;
	assert(hashbucket);
	addr = HashFun(d);
	del = hashbucket->data[addr];
	//无结点
	if (del == NULL)
	{
		printf("找不到该元素!\n");
		return;
	}
	else if (del->_d == d)
	{
		//删除头结点
		hashbucket->data[addr] = hashbucket->data[addr]->next;
		hashbucket->size--;
		free(del);
		del = NULL;
		return;
	}
	else
	{
		while (del->next!=NULL)
		{
			cur = del;
			del = del->next;
			if (del->_d == d)
			{
				cur->next = del->next;
				hashbucket->size--;
				free(del);
				del = NULL;
				return;
			}
		}
		printf("找不到该元素!\n");
		return;
	}
}

//查找
int FindHashBucket(HashBucket *hashbucket, DataType d)
{
	int addr = 0;
	linklist *find = NULL;
	assert(hashbucket);
	addr = HashFun(d);
	find = hashbucket->data[addr];
	//无结点
	if (hashbucket->data[addr] == NULL)
	{
		return 0;
	}
	while (find != NULL)
	{
		if (find->_d == d)
		{
			return 1;
		}
		find = find->next;
	}
	return 0;
}

int SizeHashBucket(HashBucket* hashbucket)
{
	assert(hashbucket);
	return hashbucket->size;
}
