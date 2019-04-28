&emsp;&emsp;给两个文件，分别有100亿个字符串，我们只要1g的内存，如何找到两个文件的交集？分别给出精确算法和近似算法？
<font color="#dd0000">精确算法：</font><br /> &emsp;&emsp;我们可以创建1000个文件，运用哈希函数先将文件1的字符串保存在对应的文件中，之后再文件2中取元素，通过哈希函数计算出哈希地址，去对应的文件里面找是否有与之相同的字符串。
<font color="#dd0000">近似算法：</font><br /> &emsp;&emsp;我们可以使用位图的方法，通过一个函数将一个元素映射成一个位矩阵中的一个点，这样一来，我们只要看看这个点是不是1就知道集合里有没有它了。 但是有可能两个字符串对应的整数是一样的，对于这种情况我们可以设置更多的哈希函数，对应更多的地址，这样更加精确。
![这里写图片描述](https://img-blog.csdn.net/20180915125243825?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3poYW9fbWlhbw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
[位图相关问题](https://blog.csdn.net/zhao_miao/article/details/82708277)

----------
**代码实现：**
BloomFilter.h

```c
#include"BitMap.h"


//定义一个函数指针、函数返回类型为int、参数为字符串
typedef int(*STRTOINT)(const char *);
typedef struct BloomFilter{
	BitMap _bmp;
	int size;
	STRTOINT HashFun[5];
}BloomFilter;


//初始化
void InitBloomFilter(BloomFilter *BloomFilter, int total, STRTOINT *hashfun);
//插入
void InsertBloomFilter(BloomFilter *BloomFilter, char *str);
//大小
int SizeBloomFilter(BloomFilter *BloomFilter);
//查询
int FindBloomFilter(BloomFilter* BloomFilter, char *str);
//删除
void DeleteBloomFilter(BloomFilter *BloomFilter, char *str);








///////////////////////////////////////////////////////////////////////////
//5种字符串转整形的方法
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


//初始化
void InitBloomFilter(BloomFilter *BloomFilter, int total, STRTOINT *hashfun)
{
	int i = 0;
	assert(BloomFilter);
	//初始化比特位
	InitBitMap(&BloomFilter->_bmp, 5 * total);
	for (i = 0; i < 5; i++)
	{
		BloomFilter->HashFun[i] = hashfun[i];
	}
	BloomFilter->size = 0;
}
//插入
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
//大小
int SizeBloomFilter(BloomFilter *BloomFilter)
{
	assert(BloomFilter);
	return BloomFilter->size;
}
//查询
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

```
BitMap.h

```c
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef struct BitMap
{
	int *Bit;
	int capacity;//比特位的总个数
	int size;//比特位为1的个数
}BitMap;

//初始化比特位
void InitBitMap(BitMap *bit,int total);
//置1
void SetBitMap(BitMap *bit, int which);
//为1的个数
int SizeBitMap(BitMap *bit);
//置0
void ResetBitMap(BitMap *bit, int which);
//判断比特位是否为1
int TestSetMap(BitMap *bit, int which);






/////////////////////////////////////////////////////////////////////////////////
//初始化比特位
void InitBitMap(BitMap *bit, int total)
{
	//total为创建的比特位个数
	assert(bit);
	//比特位的容量
	bit->capacity = total;
	bit->Bit = (int *)malloc(((total / 32) + 1)*sizeof(int));
	if (bit->Bit == NULL)
	{
		assert(0);
		return;
	}
	//置0
	memset(bit->Bit, 0, ((total / 32) + 1)*sizeof(int));
	bit->size = 0;
}
//置1
void SetBitMap(BitMap *bit, int which)
{
	int index = 0;
	int pos = 0;
	assert(bit);
	//确定在哪个字节
	index = which >> 5;
	//确定位置
	pos = which % 32;
	//置1
	bit->Bit[index] = bit->Bit[index] | (1 << pos);
	bit->size++;
}
//为1的个数
int SizeBitMap(BitMap *bit)
{
	assert(bit);
	return bit->size;
}

//判断比特位是否为1
int TestSetMap(BitMap *bit, int which)
{
	assert(bit);
	int index = 0;
	int pos = 0;
	assert(bit);
	//确定在哪个字节
	index = which >> 5;
	//确定位置
	pos = which % 32;

	//该比特位为1返回1，否则返回0
	bit->Bit[index] = bit->Bit[index] & (1 << pos);
	return bit->Bit[index];
}
//置0
void ResetBitMap(BitMap *bit, int which)
{
	int index = 0;
	int pos = 0;
	assert(bit);
	//确定在哪个字节
	index = which >> 5;
	//确定位置
	pos = which % 32;
	//如果比特位是1，就置0 size--
	if (TestSetMap(bit, which))
	{
		//置0
		bit->Bit[index] = bit->Bit[index] & (~(1 << pos));
		bit->size--;
	}	
}   
```
测试

```c
#include"BloomFilter.h"

void Test()
{
	BloomFilter  BloomFilter;
	STRTOINT hanshfun[5] = { HashFun1, HashFun2,HashFun3,HashFun4,HashFun5 };
	//初始化
	InitBloomFilter(&BloomFilter, 100, hanshfun);
	//插入
	InsertBloomFilter(&BloomFilter, "pig");
	InsertBloomFilter(&BloomFilter, "dog");
	InsertBloomFilter(&BloomFilter, "cat");
	InsertBloomFilter(&BloomFilter, "apple");
	InsertBloomFilter(&BloomFilter, "banana");
	printf("Size = %d\n", SizeBloomFilter(&BloomFilter));
	//查询
	if (FindBloomFilter(&BloomFilter, "pig"))
	{
		printf("\"pig\" is BloomFilter!\n");
	}
	else
	{
		printf("\"pig\" not is BloomFilter!\n");
	}

	if (FindBloomFilter(&BloomFilter, "orange"))
	{
		printf("\"orange\" is BloomFilter!\n");
	}
	else
	{
		printf("\"orange\" not is BloomFilter!\n");
	}
}
int main()
{
	Test();
	system("pause");
	return 0;
}
```
![这里写图片描述](https://img-blog.csdn.net/20180915125842786?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3poYW9fbWlhbw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
