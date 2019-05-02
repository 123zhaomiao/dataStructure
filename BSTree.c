#include"BSTree.h"


//��ʼ��
void InitBSTree(BSTree **BSTree)
{
	assert(BSTree);
	*BSTree = NULL;
}


BSTree* BuyNode(BSDataType d)
{
	BSTree *newnode = (BSTree *)malloc(sizeof(BSTree));
	if (NULL == newnode)
	{
		//�����ٿռ�ʧ�ܣ����ӡ�����󣬲����к���Ĵ���
		assert(0);
		return NULL;
	}
	newnode->_data = d;
	newnode->_pleft = NULL;
	newnode->_pright = NULL;

	return newnode;
}
////����
//int InsertBSTree(BSTree **BStree, BSDataType data)
//{
//	BSTree *cur  = NULL;
//	BSTree *parent = NULL;
//
//	assert(BStree);
//	cur = *BStree;
//	//1.��������Ϊ��
//	if (NULL == *BStree)    
//	{
//		*BStree = BuyNode(data);
//	}
//	//2.����������Ϊ��  
//	else
//	{
//		
//		//��.Ѱ�Ҳ����λ��
//		while (cur != NULL)
//		{
//			parent = cur;
//			if (data < cur->_data)
//			{         
//				cur = cur->_pleft;
//			}
//			else if (data > cur->_data)
//			{
//				cur = cur->_pright;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//		//��.�����½��
//		cur = BuyNode(data);
//		//��.data����˫�״�����ұߣ�����˫��С��������
//		if (data < parent->_data)
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
int InsertBSTree(BSTree **BStree, BSDataType data)
{
	BSTree *cur = NULL;
	BSTree *parent = NULL;
	assert(BStree);
	cur = *BStree;
	if (NULL == *BStree)
	{
		*BStree = BuyNode(data);
	}
	else
	{
		if (data > cur->_data)
		{
			return InsertBSTree(&(*BStree)->_pright, data);
		}
		else if (data < cur->_data)
		{
			return InsertBSTree(&(*BStree)->_pleft, data);
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
//�������   ��-->��-->��
void InOrder(BSTree *BStree)
{
	if (BStree == NULL)
	{
		return;
	}
	InOrder(BStree->_pleft);
	printf("%d ", BStree->_data);
	InOrder(BStree->_pright);
}



////ɾ��
//int  DeleteBSTree(BSTree **BStree, BSDataType data)
//{
//	BSTree *cur = NULL;
//	BSTree *del = NULL;      //Ҫɾ���Ľ��
//	BSTree *parent = NULL;   //Ҫɾ������˫�׽��
//	assert(BStree);
//	cur = *BStree;
//	if (*BStree == NULL)
//	{
//		return 0;
//	}
//	//Ѱ��Ҫɾ���ĵ�
//	while (cur != NULL)
//	{
//		if (cur->_data == data)
//		{
//			break;
//		}
//		else if (data < cur->_data)
//		{
//			parent = cur;
//			cur = cur->_pleft;
//		}
//		else
//		{
//			parent = cur;
//			cur = cur->_pright;
//		}
//	}
//	if (cur == NULL)
//	{
//		//֤��Ҫɾ����Ԫ�ز��ڶ�����������
//		return 0;
//	}
//	//ֻ���Һ��ӻ���Ҷ��
//	if (cur->_pleft == NULL)
//	{
//		//����Ǹ��ڵ㣬�ø��ڵ�ָ������������
//		if (cur == *BStree)
//		{
//			*BStree = (*BStree)->_pright;
//		}
//		else
//		{
//			//�ж�cur��˫�׵����ӻ����Һ���
//			if (parent->_pleft == cur)
//			{
//				parent->_pleft = cur->_pright;
//			}
//			else
//			{
//				parent->_pright = cur->_pright;
//			}
//		}
//	}
//	//ֻ������
//	else if (cur->_pright == NULL)
//	{
//		//����Ǹ��ڵ㣬�ø��ڵ�ָ������������
//		if (cur == *BStree)
//		{
//			*BStree = (*BStree)->_pleft;
//		}
//		else
//		{
//			//�ж�cur��˫�׵����ӻ����Һ���
//			if (parent->_pleft == cur)
//			{
//				parent->_pleft = cur->_pleft;
//			}
//			else
//			{
//				parent->_pright = cur->_pleft;
//			}
//
//		}
//	}
//	//���Һ��Ӿ�����
//	else
//	{
//		del = cur->_pright;
//		parent = cur;
//		//�ҵ�������������С��һ��
//		while (del->_pleft)
//		{
//			parent = del;
//			del = del->_pleft;
//		}
//		//���ҵ��Ľ���ֵ����Ҫɾ���Ľ��
//		cur->_data = del->_data;
//		//ɾ��replace 
//		if (parent->_pleft == del)
//		{
//			parent->_pleft = NULL;
//			cur = del;
//		}
//		else
//		{
//			parent->_pright = NULL;
//			cur = del;
//		}
//	}
//	free(cur);
//	cur = NULL;
//	return 1;
//} 


//�ݹ�ɾ��
int DeleteBSTree(BSTree **BStree, BSDataType data)
{
	BSTree *del = NULL;
	BSTree *cur = NULL;

	assert(BStree);
	if ((*BStree) == NULL)
	{
		return 0;
	}
	if (data < (*BStree)->_data )
	{
		return DeleteBSTree(&(*BStree)->_pleft,data);
	}
	else if (data > (*BStree)->_data )
	{
		return DeleteBSTree(&(*BStree)->_pright, data);
	}
	else
	{
		cur = *BStree;
		if ((*BStree)->_pleft == NULL)
		{
			*BStree = (*BStree)->_pright;
			free(cur);
			cur = NULL;
		}
		else if ((*BStree)->_pright == NULL)
		{
			*BStree = (*BStree)->_pleft;
			free(cur);
			cur = NULL;
		}
		else
		{
			del = (*BStree)->_pright;
			while (del->_pleft) 
			{
				del = del->_pleft;
			}
			(*BStree)->_data = del->_data;
			return DeleteBSTree(&(*BStree)->_pright, del->_data);
		}
	}
	return 1;
}
//����
int  FindBSTree(BSTree *BStree, BSDataType data)
{
	BSTree *cur = BStree;
	//���ڵ�Ϊ�գ���������Ϊ�գ�����0
	if (BStree == NULL)
	{
		return 0;
	}
	while (cur != NULL)
	{
		if (cur->_data == data)
		{
			return 1;
		}
		else if (cur->_data > data)
		{
			cur = cur->_pleft;
		}
		else
			cur = cur->_pright;
	}
	//cur==NULL��û���ҵ�Ԫ�غ�data��ȣ�����0
	return 0;
}

////�ݹ����
//int  FindBSTree(BSTree *BStree, BSDataType data)
//{
//	BSTree *cur = BStree;
//	if (BStree == NULL)
//	{
//		return 0;
//	}
//	if (cur->_data == data)
//	{
//		return 1;
//	}
//	else if (cur->_data > data)   
//	{
//		return FindBSTree(BStree->_pleft,data);
//	}
//	else
//	{
//		return FindBSTree(BStree->_pright, data);
//	}
//}

//���ٶ�����
void DestroyBSTree(BSTree **BStree)
{
	assert(BStree);
	if (*BStree == NULL)
	{
		return;
	}
	DestroyBSTree(&(*BStree)->_pleft);
	DestroyBSTree(&(*BStree)->_pright);
	free(*BStree);
	*BStree = NULL;
}