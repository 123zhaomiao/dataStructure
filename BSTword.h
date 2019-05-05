#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>


typedef char* key;
typedef char* value;

typedef struct BSTree
{
	struct BSTree *_pleft;
	struct BSTree *_pright;
	key  _k;
	value _v;
}BSWordTree;

//初始化
void InitBSWordTree(BSWordTree **BSTree);
//插入
int InsertBSWordTree(BSWordTree **BSTree, key  _k, value _v);
//查找
char *  FindBSWordTree(BSWordTree *BStree, key  _k);
//销毁
void DestroyBSWordTree(BSWordTree **BStree);