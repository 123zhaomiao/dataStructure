#ifndef __SeqList_H__
#define __SeqList_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define DataType int
typedef struct SeqList
{
	DataType *data; //��ŵ�����
	int sz;			//��ЧԪ�صĸ���
	int capacity;	//����
}SeqList,*qSeqList;

//��ʼ������
void InitSeqList(qSeqList seq);
//��ӡ����
void PrintSeqList(qSeqList seq);

//β������
void PushBackSeqList(qSeqList seq, DataType data);
//β��ɾ��
void PopBackSeqList(qSeqList seq);

//ͷ������
void PushFrontSeqList(qSeqList seq, DataType data);
//ͷ��ɾ��
void PopFrontSeqList(qSeqList seq);

//����ָ��Ԫ��
int FindSeqList(qSeqList seq, DataType data);
//ָ��λ�ò���
void Insert(qSeqList seq, int pos, DataType data);
//ָ��λ��ɾ��
void Erase(qSeqList seq, int pos);


//ɾ��ָ��Ԫ��
void Remove(qSeqList seq, DataType data);
//ɾ��ȫ��ָ��Ԫ��
void RemoveAll(qSeqList seq, DataType data);

//����˳���Ĵ�С
int sizeSeqList(qSeqList seq);

//�ж�˳����Ƿ�Ϊ��
int EmptySeqList(qSeqList seq);

//ð������
void Bubblesort(qSeqList seq);

//ѡ������
void SelectSort(qSeqList seq);

//ѡ��������Ż�
void SelectSort_OP(qSeqList seq);

//���ֲ���
int  BinarySearch(qSeqList seq, DataType data);

//���ֲ��ҵݹ�
int  BinarySearch_R(qSeqList seq,int left,int right, DataType data);
#endif  //__SeqList_H__