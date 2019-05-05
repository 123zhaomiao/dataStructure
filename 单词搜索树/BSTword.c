#include"BSTword.h"


//初始化
void InitBSWordTree(BSWordTree **BSTree)
{
	assert(BSTree);
	*BSTree = NULL;

}


BSWordTree* BuyNode(key  k, value v)
{
	BSWordTree *newnode = (BSWordTree *)malloc(sizeof(BSWordTree));
	if (NULL == newnode)
	{
		//若开辟空间失败，则打印出错误，不进行后面的代码
		assert(0);
		return NULL;
	}
	newnode->_k = k;
	newnode->_v = v;
	newnode->_pleft = NULL;
	newnode->_pright = NULL;

	return newnode;
}
////非递归插入
//int InsertBSWordTree(BSWordTree **BStree, key  k, value v)
//{
//	BSWordTree *cur = NULL;
//	BSWordTree *parent = NULL;
//
//	assert(BStree);
//	cur = *BStree;
//	//1.若二叉树为空
//	if (NULL == *BStree)    
//	{
//		*BStree = BuyNode(k,v);
//	}
//	//2.若二叉树不为空  
//	else
//	{
//		
//		//①.寻找插入的位置
//		while (cur != NULL)
//		{
//			parent = cur;
//			if (strcmp(cur->_k,k) > 0)
//			{         
//				cur = cur->_pleft;
//			}
//			else if (strcmp(cur->_k, k) < 0)
//			{
//				cur = cur->_pright;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//		//②.建立新结点
//		cur = BuyNode(k, v);
//		//③.data若比双亲大，则插右边，若比双亲小，则插左边
//		if (strcmp(parent->_k, k) > 0)
//		{
//			parent->_pleft = cur;
//		}
//		else
//		{
//			parent->_pright = cur;
//		}
//	}
//	return 1;
//}
//递归插入
int InsertBSWordTree(BSWordTree **BStree, key  k, value v)
{
	BSWordTree *cur = NULL;
	BSWordTree *parent = NULL;
	assert(BStree);
	if (NULL == *BStree)
	{
    	*BStree = BuyNode(k, v);
	}
	if (strcmp((*BStree)->_k, k) > 0)
	{
		return InsertBSWordTree(&(*BStree)->_pleft, k, v);
	}
	else if (strcmp((*BStree)->_k, k) < 0)
	{
		return InsertBSWordTree(&(*BStree)->_pright, k, v);
	}
	else
	{
		return 0;
	}
}




////非递归查找
//char *  FindBSWordTree(BSWordTree *BStree, key  _k)
//{
//	BSWordTree *cur = BStree;
//	//根节点为空，即二叉树为空，返回0
//	if (BStree == NULL)
//	{
//		return NULL;
//	}
//	while (cur != NULL)
//	{
//		if (strcmp (cur->_k, _k) == 0)
//		{
//			return cur->_v;
//		}
//		else if (strcmp(cur->_k, _k) > 0)
//		{
//			cur = cur->_pleft;
//		}
//		else
//		{
//			cur = cur->_pright;
//		}
//	}
//	//cur==NULL即没有找到元素和data相等，返回null
//	return NULL;
//}

//递归查找
char * FindBSWordTree(BSWordTree *BStree, key  _k)
{
	BSWordTree *cur = BStree;
	//根节点为空，即二叉树为空，返回0
	if (BStree == NULL)
	{
		return NULL;
	}
	if (strcmp(cur->_k, _k) == 0)
	{
		return cur->_v;
	}
	else if (strcmp(cur->_k, _k) > 0)
	{
		return  FindBSWordTree(BStree->_pleft, _k);
	}
	else
	{
		return  FindBSWordTree(BStree->_pright, _k);
	}
}
//销毁二叉树
void DestroyBSWordTree(BSWordTree **BStree)
{
	assert(BStree);
	if (*BStree == NULL)
	{
		return;
	}
	DestroyBSWordTree(&(*BStree)->_pleft);
	DestroyBSWordTree(&(*BStree)->_pright);
	free(*BStree);
	*BStree = NULL;
}
