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




//��ʼ��
void InitBSIpTree(BSIpTree **BSTree);
//����
int InsertBSIpTree(BSIpTree **BSTree, char *add,int num);
//����
char *  FindBSIpTree(BSIpTree *BStree, int v);
//�������
void InOrder(BSIpTree *BStree);
//ɾ��
int DeleteBSWordTree(BSIpTree **BStree, int v);
//����
void DestroyBSIpTree(BSIpTree **BStree);