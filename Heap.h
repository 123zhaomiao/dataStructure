#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef int HDataType;
typedef struct Heap
{
	HDataType *data;
	int size; //��ЧԪ�صĸ���
	int capacity; //����
}Heap;

//��ʼ����
void InitHeap(Heap *hp, int *array, int size);
//������
void CreateHeap(Heap *hp, int *array, int size);
//�����
void InsertHeap(Heap *hp, HDataType data);
//ɾ��
void DeleteHeap(Heap *hp);
//��ӡ��
void PrintHeap(Heap *hp);
//������
void SortHeap(Heap *hp);
//���ٶ�
void DestroyHeap(Heap *hp);