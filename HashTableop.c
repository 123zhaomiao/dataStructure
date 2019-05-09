#include"HashTable.h"

//������
#define primesize 28
unsigned long int _PrimeList[primesize] = {
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 39324ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	60331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};
//�ַ���ת����
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

//����
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
//��ʼ����ϣ��
void InitHashTable(HashTable *hashtable)
{
	int i = 0;
	int capacity;
	assert(hashtable);
	//��ʼ������
	capacity = 10;
	//Ѱ���������������������
	hashtable->capacity = Prime(capacity);
	//��ʼ��data
	hashtable->data = (Elem*)malloc(hashtable->capacity*sizeof(Elem));
	if (hashtable->data == NULL)
	{
		assert(0);
		return;
	}
	//��ʼ������(״̬Ϊ�գ���ֵΪ0)
	for (i = 0; i < hashtable->capacity; i++)
	{
		hashtable->data[i]._data = 0;
		hashtable->data[i]._state = EMPTY;
	}

	//��ʼ����ЧԪ��
	hashtable->size.size = 0;
	//��ʼ����ɾ����Ԫ��
	hashtable->size.del = 0;
	//��ʼ������
	hashtable->Fun = StrToInt;
}


//��ϣ����
int HashFun(HashTable* hashtable, DataType data)
{
	assert(hashtable);
	return (hashtable->Fun(data)) % hashtable->capacity;
}
//�ж��Ƿ���Ҫ����
Elem * ExpandCapacity(HashTable *hashtable)
{
	int i = 0;
	int addr = 0;
	int newcapacity = 0;
	int oldcapacity = hashtable->capacity;
	Elem *new = NULL;
	//������
	newcapacity = Prime(hashtable->capacity);
	//�����¿ռ�
	new = (Elem *)malloc(newcapacity*sizeof(Elem));
	if (new == NULL)
	{
		assert(0);
		return NULL;
	}

	//��ʼ���¿ռ�
	for (i = 0; i < newcapacity; i++)
	{
		new[i]._data = 0;
		new[i]._state = EMPTY;
	}

	hashtable->capacity = newcapacity;
	//��Ԫ��
	for (i = 0; i < oldcapacity; i++)
	{
		if (hashtable->data[i]._state == EXIST)
		{
			//�¹�ϣ��ַ
			addr = HashFun(hashtable, hashtable->data[i]._data);
			//�����±�
			while (new[addr]._state != EMPTY)
			{
#if 0
				//����̽��
				addr++;
				if (addr == hashtable->capacity)
				{
					addr = 0;
				}
#else
				//����̽��
				//����̽��
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
//�����ϣ��
void InsertHashTable(HashTable *hashtable, DataType data)
{
	int i = 0;
	int Add = 0;
	assert(hashtable);
	//�ж��Ƿ����ݣ�������еĸ��������Լ��Ĺ�ϣ���ӣ�����Ҫ����
	if ((hashtable->size.del + hashtable->size.size) * 10 / hashtable->capacity >= 7)
	{
		ExpandCapacity(hashtable);
	}
	//�����ϣ��ַ
	Add = HashFun(hashtable, data);

	//��ϣ��ַ��Ӧ�Ŀռ�Ϊ����ֱ�Ӳ��룬��Ϊ����������
	while (hashtable->data[Add]._state != EMPTY)
	{
		//�������data��ͬ�Ľ���򲻲���
		if (hashtable->data[Add]._state == EXIST&&
			hashtable->data[Add]._data == data)
		{
			return;
		}
#if 0
		//����̽��
		Add++;
		if (Add == hashtable->capacity)
		{
			Add = 0;
		}
#else
		//����̽��
		i++;
		Add = Add + 2 * i + 1;
		Add = Add % hashtable->capacity;
	}
#endif
	hashtable->data[Add]._data = data;
	hashtable->data[Add]._state = EXIST;
	hashtable->size.size++;
}

//ɾ����ϣ��
int  DeleteHashTable(HashTable *hashtable, DataType data)
{
	int Add = 0;
	int i = 0;
	assert(hashtable);
	if (hashtable->size.size == 0)
	{
		//��ϣ��Ϊ�գ��޷�ɾ��
		printf("�޷�ɾ��\n");
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
				//��ɾ����Ԫ��+1
				hashtable->size.del++;
				//��ЧԪ��-1
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
				//����̽��
				i++;
				Add = Add + 2 * i + 1;
				Add = Add % hashtable->capacity;
#endif
			}
		}
		//û���ҵ�Ԫ�أ��޷�ɾ��
		return -1;
	}
}

//����
int FindHashTable(HashTable *hashtable, DataType data)
{
	int Add = 0;
	int i = 0;
	assert(hashtable);
	if (hashtable->size.size == 0)
	{
		printf("��ϣ��Ϊ��!\n");
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
			//����̽��
			i++;
			Add = Add + 2 * i + 1;
			Add = Add % hashtable->capacity;
#endif
		}
		return -1;
	}
}

//�п�
int EmptyHashTable(HashTable *hashtable)
{
	assert(hashtable);
	return hashtable->size.size == 0;
}
//��ϣ��Ԫ�ظ���
int SizeHashTable(HashTable *hashtable)
{
	assert(hashtable);
	return hashtable->size.size;
}

//��ӡ��ϣ��
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

//���ٹ�ϣ��
void DestroyHashTable(HashTable *hashtable)
{
	assert(hashtable);
	free(hashtable->data);
	hashtable->data = NULL;
	hashtable->size.del = 0;
	hashtable->size.size = 0;
}