#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef int HDataType;
typedef struct Heap
{
	HDataType *data;
	int size; //有效元素的个数
	int capacity; //容量
}Heap;

//初始化堆
void InitHeap(Heap *hp, int *array, int size);
//创建堆
void CreateHeap(Heap *hp, int *array, int size);
//插入堆
void InsertHeap(Heap *hp, HDataType data);
//删除
void DeleteHeap(Heap *hp);
//打印堆
void PrintHeap(Heap *hp);
//堆排序
void SortHeap(Heap *hp);
//销毁堆
void DestroyHeap(Heap *hp);
