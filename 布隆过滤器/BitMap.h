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
