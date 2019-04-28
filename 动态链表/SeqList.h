#ifndef __SeqList_H__
#define __SeqList_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define DataType int
typedef struct SeqList
{
	DataType *data; //存放的数据
	int sz;			//有效元素的个数
	int capacity;	//容量
}SeqList,*qSeqList;

//初始化函数
void InitSeqList(qSeqList seq);
//打印函数
void PrintSeqList(qSeqList seq);

//尾部插入
void PushBackSeqList(qSeqList seq, DataType data);
//尾部删除
void PopBackSeqList(qSeqList seq);

//头部插入
void PushFrontSeqList(qSeqList seq, DataType data);
//头部删除
void PopFrontSeqList(qSeqList seq);

//查找指定元素
int FindSeqList(qSeqList seq, DataType data);
//指定位置插入
void Insert(qSeqList seq, int pos, DataType data);
//指定位置删除
void Erase(qSeqList seq, int pos);


//删除指定元素
void Remove(qSeqList seq, DataType data);
//删除全部指定元素
void RemoveAll(qSeqList seq, DataType data);

//返回顺序表的大小
int sizeSeqList(qSeqList seq);

//判断顺序表是否为空
int EmptySeqList(qSeqList seq);

//冒泡排序
void Bubblesort(qSeqList seq);

//选择排序
void SelectSort(qSeqList seq);

//选择排序的优化
void SelectSort_OP(qSeqList seq);

//二分查找
int  BinarySearch(qSeqList seq, DataType data);

//二分查找递归
int  BinarySearch_R(qSeqList seq,int left,int right, DataType data);
#endif  //__SeqList_H__
