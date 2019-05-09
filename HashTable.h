#include<assert.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include<stdio.h>
typedef (*SDTINT)(const char *src);
typedef enum state
{
	EMPTY,
	EXIST,
	DELETE,
}state;
#define DataType char*
typedef struct Elem
{
	DataType _data;
	enum state _state;
}Elem;

typedef struct Size
{
	int size; //��ϣ������ЧԪ�ظ���
	int del;  //��ϣ��ɾ��Ԫ�صĸ���
}Size;
typedef struct HashTable
{
	Elem *data;
	int capacity;
	Size size;
	SDTINT Fun;
}HashTable;
//��ʼ����ϣ��
void InitHashTable(HashTable *hashtable);
//�����ϣ��
void InsertHashTable(HashTable *hashtable, DataType data);
//ɾ����ϣ��
int  DeleteHashTable(HashTable *hashtable, DataType data);
//����
int FindHashTable(HashTable *hashtable, DataType data);
//�п�
int EmptyHashTable(HashTable *hashtable);
//��ϣ��Ԫ�ظ���
int SizeHashTable(HashTable *hashtable);
//��ӡ��ϣ��
void print(HashTable *hashtable);
//���ٹ�ϣ��
void DestroyHashTable(HashTable *hashtable);
