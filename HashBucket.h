
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
//��ʼ����ϣͰ
void InitHashBucket(HashBucket *hashbucket);
//����
void InsertHashBucket(HashBucket *hashbucket,  DataType d);
//ɾ��
void DeleteHashBucket(HashBucket *hashbucket, DataType d);
//����
int FindHashBucket(HashBucket *hashbucket, DataType d);
int SizeHashBucket(HashBucket* hashbucket);

////////////////////////////////////////////////////////////////////////////////
//��ʼ����ϣͰ
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
//��ϣ����
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
//����
void InsertHashBucket(HashBucket *hashbucket , DataType d)
{
	int addr = 0;
	linklist *node = NULL;
	assert(hashbucket);
	addr = HashFun(d);
	node = BuyNode(d);
	if (hashbucket->data[addr] == NULL)
	{
		//ͷ�巨
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

//ɾ��
void DeleteHashBucket(HashBucket *hashbucket, DataType d)
{
	int addr = 0;
	//��ɾ���Ľ��Ľ��
	linklist *del = NULL;
	//��ɾ��������һ�����
	linklist *cur = NULL;
	assert(hashbucket);
	addr = HashFun(d);
	del = hashbucket->data[addr];
	//�޽��
	if (del == NULL)
	{
		printf("�Ҳ�����Ԫ��!\n");
		return;
	}
	else if (del->_d == d)
	{
		//ɾ��ͷ���
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
		printf("�Ҳ�����Ԫ��!\n");
		return;
	}
}

//����
int FindHashBucket(HashBucket *hashbucket, DataType d)
{
	int addr = 0;
	linklist *find = NULL;
	assert(hashbucket);
	addr = HashFun(d);
	find = hashbucket->data[addr];
	//�޽��
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