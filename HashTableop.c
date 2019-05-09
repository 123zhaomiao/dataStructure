#include"HashTable.h"

//素数表
#define primesize 28
unsigned long int _PrimeList[primesize] = {
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 39324ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	60331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};
//字符串转整形
unsigned long StrToInt(const char *str)
{
	unsigned int seed = 131;
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash*seed + (*str++);
	}
	return (hash & 0x7FFFFFF);
}

//素数
int Prime(int capacity)
{
	int i = 0;
	for (i = 0; i < primesize; i++)
	{
		if ((int)_PrimeList[i] > capacity)
		{
			return _PrimeList[i];
		}
	}
	return _PrimeList[primesize - 1];
}
//初始化哈希表
void InitHashTable(HashTable *hashtable)
{
	int i = 0;
	int capacity;
	assert(hashtable);
	//初始化容量
	capacity = 10;
	//寻找与所给容量最近的素数
	hashtable->capacity = Prime(capacity);
	//初始化data
	hashtable->data = (Elem*)malloc(hashtable->capacity*sizeof(Elem));
	if (hashtable->data == NULL)
	{
		assert(0);
		return;
	}
	//初始化数组(状态为空，数值为0)
	for (i = 0; i < hashtable->capacity; i++)
	{
		hashtable->data[i]._data = 0;
		hashtable->data[i]._state = EMPTY;
	}

	//初始化有效元素
	hashtable->size.size = 0;
	//初始化被删除的元素
	hashtable->size.del = 0;
	//初始化函数
	hashtable->Fun = StrToInt;
}


//哈希函数
int HashFun(HashTable* hashtable, DataType data)
{
	assert(hashtable);
	return (hashtable->Fun(data)) % hashtable->capacity;
}
//判断是否需要扩容
Elem * ExpandCapacity(HashTable *hashtable)
{
	int i = 0;
	int addr = 0;
	int newcapacity = 0;
	int oldcapacity = hashtable->capacity;
	Elem *new = NULL;
	//扩容量
	newcapacity = Prime(hashtable->capacity);
	//开辟新空间
	new = (Elem *)malloc(newcapacity*sizeof(Elem));
	if (new == NULL)
	{
		assert(0);
		return NULL;
	}

	//初始化新空间
	for (i = 0; i < newcapacity; i++)
	{
		new[i]._data = 0;
		new[i]._state = EMPTY;
	}

	hashtable->capacity = newcapacity;
	//搬元素
	for (i = 0; i < oldcapacity; i++)
	{
		if (hashtable->data[i]._state == EXIST)
		{
			//新哈希地址
			addr = HashFun(hashtable, hashtable->data[i]._data);
			//插入新表
			while (new[addr]._state != EMPTY)
			{
#if 0
				//线性探测
				addr++;
				if (addr == hashtable->capacity)
				{
					addr = 0;
				}
#else
				//二次探测
				//二次探测
				i++;
				addr = addr + 2 * i + 1;
				addr = addr%hashtable->capacity;
			}
#endif
			new[addr]._data = hashtable->data[i]._data;
			new[addr]._state = EXIST;
		}
	}
	hashtable->size.del = 0;
	free(hashtable->data);
	hashtable->data = new;
	return new;
}
//插入哈希表
void InsertHashTable(HashTable *hashtable, DataType data)
{
	int i = 0;
	int Add = 0;
	assert(hashtable);
	//判断是否扩容，如果表中的个数超过自己的哈希因子，则需要扩容
	if ((hashtable->size.del + hashtable->size.size) * 10 / hashtable->capacity >= 7)
	{
		ExpandCapacity(hashtable);
	}
	//计算哈希地址
	Add = HashFun(hashtable, data);

	//哈希地址对应的空间为空则直接插入，不为空则向下找
	while (hashtable->data[Add]._state != EMPTY)
	{
		//如果有与data相同的结点则不插入
		if (hashtable->data[Add]._state == EXIST&&
			hashtable->data[Add]._data == data)
		{
			return;
		}
#if 0
		//线性探测
		Add++;
		if (Add == hashtable->capacity)
		{
			Add = 0;
		}
#else
		//二次探测
		i++;
		Add = Add + 2 * i + 1;
		Add = Add % hashtable->capacity;
	}
#endif
	hashtable->data[Add]._data = data;
	hashtable->data[Add]._state = EXIST;
	hashtable->size.size++;
}

//删除哈希表
int  DeleteHashTable(HashTable *hashtable, DataType data)
{
	int Add = 0;
	int i = 0;
	assert(hashtable);
	if (hashtable->size.size == 0)
	{
		//哈希表为空，无法删除
		printf("无法删除\n");
		return -1;
	}
	else
	{
		Add = HashFun(hashtable, data);
		while (hashtable->data[Add]._state != EMPTY)
		{
			if (hashtable->data[Add]._state == EXIST
				&&hashtable->data[Add]._data == data)
			{
				hashtable->data[Add]._state = DELETE;
				//被删除的元素+1
				hashtable->size.del++;
				//有效元素-1
				hashtable->size.size--;
				return 1;
			}
			else
			{
#if 0
				Add++;
				if (Add == hashtable->capacity)
				{
					Add = 0;
				}
#else
				//二次探测
				i++;
				Add = Add + 2 * i + 1;
				Add = Add % hashtable->capacity;
#endif
			}
		}
		//没有找到元素，无法删除
		return -1;
	}
}

//查找
int FindHashTable(HashTable *hashtable, DataType data)
{
	int Add = 0;
	int i = 0;
	assert(hashtable);
	if (hashtable->size.size == 0)
	{
		printf("哈希表为空!\n");
		return -1;
	}
	else
	{
		Add = HashFun(hashtable, data);
		while (hashtable->data[Add]._state != EMPTY && Add < hashtable->capacity)
		{
			if (hashtable->data[Add]._state == EXIST
				&&hashtable->data[Add]._data == data)
			{
				return Add;
			}
#if 0
			Add++;
			if (Add == hashtable->capacity)
			{
				Add = 0;
			}
#else
			//二次探测
			i++;
			Add = Add + 2 * i + 1;
			Add = Add % hashtable->capacity;
#endif
		}
		return -1;
	}
}

//判空
int EmptyHashTable(HashTable *hashtable)
{
	assert(hashtable);
	return hashtable->size.size == 0;
}
//哈希表元素个数
int SizeHashTable(HashTable *hashtable)
{
	assert(hashtable);
	return hashtable->size.size;
}

//打印哈希表
void print(HashTable *hashtable)
{
	int i = 0;
	for (i = 0; i < hashtable->capacity; i++)
	{
		if (hashtable->data[i]._state == EMPTY)
		{
			printf("add=%d EMPTY %s\n", i, hashtable->data[i]._data);
		}
		else if (hashtable->data[i]._state == DELETE)
		{
			printf("add=%d DELETE %s\n", i, hashtable->data[i]._data);
		}
		else
		{
			printf("add=%d EXIST %s\n", i, hashtable->data[i]._data);
		}
	}
}

//销毁哈希表
void DestroyHashTable(HashTable *hashtable)
{
	assert(hashtable);
	free(hashtable->data);
	hashtable->data = NULL;
	hashtable->size.del = 0;
	hashtable->size.size = 0;
}