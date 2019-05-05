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

//³õÊ¼»¯
void InitBSWordTree(BSWordTree **BSTree);
//²åÈë
int InsertBSWordTree(BSWordTree **BSTree, key  _k, value _v);
//²éÕÒ
char *  FindBSWordTree(BSWordTree *BStree, key  _k);
//Ïú»Ù
void DestroyBSWordTree(BSWordTree **BStree);
