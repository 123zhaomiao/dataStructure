#include"BSTword.h"


//��ʼ��
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
		//�����ٿռ�ʧ�ܣ����ӡ�����󣬲����к���Ĵ���
		assert(0);
		return NULL;
	}
	newnode->_k = k;
	newnode->_v = v;
	newnode->_pleft = NULL;
	newnode->_pright = NULL;

	return newnode;
}
////�ǵݹ����
//int InsertBSWordTree(BSWordTree **BStree, key  k, value v)
//{
//	BSWordTree *cur = NULL;
//	BSWordTree *parent = NULL;
//
//	assert(BStree);
//	cur = *BStree;
//	//1.��������Ϊ��
//	if (NULL == *BStree)    
//	{
//		*BStree = BuyNode(k,v);
//	}
//	//2.����������Ϊ��  
//	else
//	{
//		
//		//��.Ѱ�Ҳ����λ��
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
//		//��.�����½��
//		cur = BuyNode(k, v);
//		//��.data����˫�״�����ұߣ�����˫��С��������
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
//�ݹ����
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




////�ǵݹ����
//char *  FindBSWordTree(BSWordTree *BStree, key  _k)
//{
//	BSWordTree *cur = BStree;
//	//���ڵ�Ϊ�գ���������Ϊ�գ�����0
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
//	//cur==NULL��û���ҵ�Ԫ�غ�data��ȣ�����null
//	return NULL;
//}

//�ݹ����
char * FindBSWordTree(BSWordTree *BStree, key  _k)
{
	BSWordTree *cur = BStree;
	//���ڵ�Ϊ�գ���������Ϊ�գ�����0
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
//���ٶ�����
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