#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define MAX 10                    //链表的最大容量
typedef int DataType;             //将int重命名为DataType
typedef struct SeqList
{
	DataType data[MAX];           //MAX=10;
	int sz;                       //容量(已经存入多少个有效元素)
}SeqList,*qSeqList;
   
void SeqListInit(qSeqList seq);                    //初始化函数
void PushBack(qSeqList seq, DataType data);        //尾插法
void PopBack(qSeqList seq);                        //尾部删除    
void PushFront(qSeqList seq, DataType data);       //头插法
void PopFront(qSeqList seq);                       //头部删除
int  Front(qSeqList seq, DataType data);           //查找指定元素
void Insert(qSeqList seq, int pos, DataType data); //指定位置插入
void Erase(qSeqList seq, int pos);                 //删除指定位置元素
void Removeall(qSeqList seq, DataType data);       //删除全部指定元素
void Remove(qSeqList seq, DataType data);          //删除指定元素
int size(qSeqList seq);                            //返回顺序表的大小
int Empty(qSeqList seq);                           //判断结构体是否为空
void Bubble(qSeqList seq);                         //冒泡排序
void Selectsort(qSeqList seq);                     //选择排序
void SelectsortOp(qSeqList seq);                   //选择排序的优化
int BinarySearch(qSeqList seq, DataType data);    // 二分查找
int BinarySearch_R(qSeqList seq, int left, int right, DataType data); //二分查找递归
void PrintSeqList(qSeqList seq);                   //打印  

#endif  //__SEQLIST_H__