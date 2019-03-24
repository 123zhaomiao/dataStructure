#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef struct BitMap
{
	int *Bit;
	int capacity;//����λ���ܸ���
	int size;//����λΪ1�ĸ���
}BitMap;

//��ʼ������λ
void InitBitMap(BitMap *bit,int total);
//��1
void SetBitMap(BitMap *bit, int which);
//Ϊ1�ĸ���
int SizeBitMap(BitMap *bit);
//��0
void ResetBitMap(BitMap *bit, int which);
//�жϱ���λ�Ƿ�Ϊ1
int TestSetMap(BitMap *bit, int which);






/////////////////////////////////////////////////////////////////////////////////
//��ʼ������λ
void InitBitMap(BitMap *bit, int total)
{
	//totalΪ�����ı���λ����
	assert(bit);
	//����λ������
	bit->capacity = total;
	bit->Bit = (int *)malloc(((total / 32) + 1)*sizeof(int));
	if (bit->Bit == NULL)
	{
		assert(0);
		return;
	}
	//��0
	memset(bit->Bit, 0, ((total / 32) + 1)*sizeof(int));
	bit->size = 0;
}
//��1
void SetBitMap(BitMap *bit, int which)
{
	int index = 0;
	int pos = 0;
	assert(bit);
	//ȷ�����ĸ��ֽ�
	index = which >> 5;
	//ȷ��λ��
	pos = which % 32;
	//��1
	bit->Bit[index] = bit->Bit[index] | (1 << pos);
	bit->size++;
}
//Ϊ1�ĸ���
int SizeBitMap(BitMap *bit)
{
	assert(bit);
	return bit->size;
}

//�жϱ���λ�Ƿ�Ϊ1
int TestSetMap(BitMap *bit, int which)
{
	assert(bit);
	int index = 0;
	int pos = 0;
	assert(bit);
	//ȷ�����ĸ��ֽ�
	index = which >> 5;
	//ȷ��λ��
	pos = which % 32;

	//�ñ���λΪ1����1�����򷵻�0
	bit->Bit[index] = bit->Bit[index] & (1 << pos);
	return bit->Bit[index];
}
//��0
void ResetBitMap(BitMap *bit, int which)
{
	int index = 0;
	int pos = 0;
	assert(bit);
	//ȷ�����ĸ��ֽ�
	index = which >> 5;
	//ȷ��λ��
	pos = which % 32;
	//�������λ��1������0 size--
	if (TestSetMap(bit, which))
	{
		//��0
		bit->Bit[index] = bit->Bit[index] & (~(1 << pos));
		bit->size--;
	}	
}   