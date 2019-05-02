#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//二叉树的结构
typedef int BSDataType;
typedef struct BSTree
{
	struct BSTree *_pleft;
	struct BSTree *_pright;
	BSDataType _data;
}BSTree;
//初始化
void InitBSTree(BSTree **BSTree);
//插入
int InsertBSTree(BSTree **BSTree, BSDataType data);
//中序遍历
void InOrder(BSTree *BStree);
//删除
int DeleteBSTree(BSTree **BStree, BSDataType data);
//查找
int  FindBSTree(BSTree *BStree, BSDataType data);
//销毁
void DestroyBSTree(BSTree **BStree);




