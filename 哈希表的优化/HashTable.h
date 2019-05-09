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
	int size; //哈希表中有效元素个数
	int del;  //哈希表被删除元素的个数
}Size;
typedef struct HashTable
{
	Elem *data;
	int capacity;
	Size size;
	SDTINT Fun;
}HashTable;
//初始化哈希表
void InitHashTable(HashTable *hashtable);
//插入哈希表
void InsertHashTable(HashTable *hashtable, DataType data);
//删除哈希表
int  DeleteHashTable(HashTable *hashtable, DataType data);
//查找
int FindHashTable(HashTable *hashtable, DataType data);
//判空
int EmptyHashTable(HashTable *hashtable);
//哈希表元素个数
int SizeHashTable(HashTable *hashtable);
//打印哈希表
void print(HashTable *hashtable);
//销毁哈希表
void DestroyHashTable(HashTable *hashtable);
