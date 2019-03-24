#include"BitMap.h"


//����һ������ָ�롢������������Ϊint������Ϊ�ַ���
typedef int(*STRTOINT)(const char *);
typedef struct BloomFilter{
	BitMap _bmp;
	int size;
	STRTOINT HashFun[5];
}BloomFilter;


//��ʼ��
void InitBloomFilter(BloomFilter *BloomFilter, int total, STRTOINT *hashfun);
//����
void InsertBloomFilter(BloomFilter *BloomFilter, char *str);
//��С
int SizeBloomFilter(BloomFilter *BloomFilter);
//��ѯ
int FindBloomFilter(BloomFilter* BloomFilter, char *str);
//ɾ��
void DeleteBloomFilter(BloomFilter *BloomFilter, char *str);








///////////////////////////////////////////////////////////////////////////
//5���ַ���ת���εķ���
int HashFun1(const char *str)
{
	unsigned int hash = 0;

	while (*str)
	{
		// equivalent to: hash = 65599*hash + (*str++);
		hash = (*str++) + (hash << 6) + (hash << 16) - hash;
	}

	return (hash & 0x7FFFFFFF);
}

// RS Hash Function
int HashFun2(const char *str)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;

	while (*str)
	{
		hash = hash * a + (*str++);
		a *= b;
	}

	return (hash & 0x7FFFFFFF);
}

// JS Hash Function
int HashFun3(const char *str)
{
	unsigned int hash = 1315423911;

	while (*str)
	{
		hash ^= ((hash << 5) + (*str++) + (hash >> 2));
	}

	return (hash & 0x7FFFFFFF);
}

// P. J. Weinberger Hash Function
int HashFun4(const char *str)
{
	unsigned int BitsInUnignedInt = (unsigned int)(sizeof(unsigned int)* 8);
	unsigned int ThreeQuarters = (unsigned int)((BitsInUnignedInt * 3) / 4);
	unsigned int OneEighth = (unsigned int)(BitsInUnignedInt / 8);
	unsigned int HighBits = (unsigned int)(0xFFFFFFFF) << (BitsInUnignedInt - OneEighth);
	unsigned int hash = 0;
	unsigned int test = 0;

	while (*str)
	{
		hash = (hash << OneEighth) + (*str++);
		if ((test = hash & HighBits) != 0)
		{
			hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
		}
	}

	return (hash & 0x7FFFFFFF);
}

// ELF Hash Function
int HashFun5(const char *str)
{
	unsigned int hash = 0;
	unsigned int x = 0;

	while (*str)
	{
		hash = (hash << 4) + (*str++);
		if ((x = hash & 0xF0000000L) != 0)
		{
			hash ^= (x >> 24);
			hash &= ~x;
		}
	}

	return (hash & 0x7FFFFFFF);
}
/////////////////////////////////////////////////////////////////////////////////////


//��ʼ��
void InitBloomFilter(BloomFilter *BloomFilter, int total, STRTOINT *hashfun)
{
	int i = 0;
	assert(BloomFilter);
	//��ʼ������λ
	InitBitMap(&BloomFilter->_bmp, 5 * total);
	for (i = 0; i < 5; i++)
	{
		BloomFilter->HashFun[i] = hashfun[i];
	}
	BloomFilter->size = 0;
}
//����
void InsertBloomFilter(BloomFilter *BloomFilter, char *str)
{
	int Hash1 = 0;
	int Hash2 = 0;
	int Hash3 = 0;
	int Hash4 = 0;
	int Hash5 = 0;
	assert(BloomFilter);
	Hash1 = BloomFilter->HashFun[0](str) % BloomFilter->_bmp.capacity;
	Hash2 = BloomFilter->HashFun[1](str) % BloomFilter->_bmp.capacity;
	Hash3 = BloomFilter->HashFun[2](str) % BloomFilter->_bmp.capacity;
	Hash4 = BloomFilter->HashFun[3](str) % BloomFilter->_bmp.capacity;
	Hash5 = BloomFilter->HashFun[4](str) % BloomFilter->_bmp.capacity;

	SetBitMap(&BloomFilter->_bmp, Hash1);
	SetBitMap(&BloomFilter->_bmp, Hash2);
	SetBitMap(&BloomFilter->_bmp, Hash3);
	SetBitMap(&BloomFilter->_bmp, Hash4);

	SetBitMap(&BloomFilter->_bmp, Hash5);
	BloomFilter->size++;
}
//��С
int SizeBloomFilter(BloomFilter *BloomFilter)
{
	assert(BloomFilter);
	return BloomFilter->size;
}
//��ѯ
int FindBloomFilter(BloomFilter* BloomFilter, char *str)
{
	int Hash1 = 0;
	int Hash2 = 0;
	int Hash3 = 0;
	int Hash4 = 0;
	int Hash5 = 0;
	assert(BloomFilter);
	Hash1 = BloomFilter->HashFun[0](str) % BloomFilter->_bmp.capacity;
	Hash2 = BloomFilter->HashFun[1](str) % BloomFilter->_bmp.capacity;
	Hash3 = BloomFilter->HashFun[2](str) % BloomFilter->_bmp.capacity;
	Hash4 = BloomFilter->HashFun[3](str) % BloomFilter->_bmp.capacity;
	Hash5 = BloomFilter->HashFun[4](str) % BloomFilter->_bmp.capacity;

	if (!TestSetMap(&BloomFilter->_bmp, Hash1))
	{
		return 0;
	}
	if (!TestSetMap(&BloomFilter->_bmp, Hash2))
	{
		return 0;
	}
	if (!TestSetMap(&BloomFilter->_bmp, Hash3))
	{
		return 0;
	}
	if (!TestSetMap(&BloomFilter->_bmp, Hash4))
	{
		return 0;
	}
	if (!TestSetMap(&BloomFilter->_bmp,Hash5))
	{
		return 0;
	}
	return 1;
}
