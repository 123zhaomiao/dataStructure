#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>




typedef struct BSTipadd
{
	struct BSTipadd *_pleft;
	struct BSTipadd *_pright;
	int v;
	int num;
}BSIpTree;




//初始化
void InitBSIpTree(BSIpTree **BSTree);
//插入
int InsertBSIpTree(BSIpTree **BSTree, char *add,int num);
//查找
char *  FindBSIpTree(BSIpTree *BStree, int v);
//中序遍历
void InOrder(BSIpTree *BStree);
//删除
int DeleteBSWordTree(BSIpTree **BStree, int v);
//销毁
void DestroyBSIpTree(BSIpTree **BStree);
