#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//�������Ľṹ
typedef int BSDataType;
typedef struct BSTree
{
	struct BSTree *_pleft;
	struct BSTree *_pright;
	BSDataType _data;
}BSTree;
//��ʼ��
void InitBSTree(BSTree **BSTree);
//����
int InsertBSTree(BSTree **BSTree, BSDataType data);
//�������
void InOrder(BSTree *BStree);
//ɾ��
int DeleteBSTree(BSTree **BStree, BSDataType data);
//����
int  FindBSTree(BSTree *BStree, BSDataType data);
//����
void DestroyBSTree(BSTree **BStree);




