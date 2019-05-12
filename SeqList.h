#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define MAX 10                    //������������
typedef int DataType;             //��int������ΪDataType
typedef struct SeqList
{
	DataType data[MAX];           //MAX=10;
	int sz;                       //����(�Ѿ�������ٸ���ЧԪ��)
}SeqList,*qSeqList;
   
void SeqListInit(qSeqList seq);                    //��ʼ������
void PushBack(qSeqList seq, DataType data);        //β�巨
void PopBack(qSeqList seq);                        //β��ɾ��    
void PushFront(qSeqList seq, DataType data);       //ͷ�巨
void PopFront(qSeqList seq);                       //ͷ��ɾ��
int  Front(qSeqList seq, DataType data);           //����ָ��Ԫ��
void Insert(qSeqList seq, int pos, DataType data); //ָ��λ�ò���
void Erase(qSeqList seq, int pos);                 //ɾ��ָ��λ��Ԫ��
void Removeall(qSeqList seq, DataType data);       //ɾ��ȫ��ָ��Ԫ��
void Remove(qSeqList seq, DataType data);          //ɾ��ָ��Ԫ��
int size(qSeqList seq);                            //����˳���Ĵ�С
int Empty(qSeqList seq);                           //�жϽṹ���Ƿ�Ϊ��
void Bubble(qSeqList seq);                         //ð������
void Selectsort(qSeqList seq);                     //ѡ������
void SelectsortOp(qSeqList seq);                   //ѡ��������Ż�
int BinarySearch(qSeqList seq, DataType data);    // ���ֲ���
int BinarySearch_R(qSeqList seq, int left, int right, DataType data); //���ֲ��ҵݹ�
void PrintSeqList(qSeqList seq);                   //��ӡ  

#endif  //__SEQLIST_H__