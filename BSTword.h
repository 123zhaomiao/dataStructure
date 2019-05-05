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

//��ʼ��
void InitBSWordTree(BSWordTree **BSTree);
//����
int InsertBSWordTree(BSWordTree **BSTree, key  _k, value _v);
//����
char *  FindBSWordTree(BSWordTree *BStree, key  _k);
//����
void DestroyBSWordTree(BSWordTree **BStree);