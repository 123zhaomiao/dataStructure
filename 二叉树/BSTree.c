#include"BSTree.h"


//初始化
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
		//若开辟空间失败，则打印出错误，不进行后面的代码
		assert(0);
		return NULL;
	}
	newnode->_data = d;
	newnode->_pleft = NULL;
	newnode->_pright = NULL;

	return newnode;
}
////插入
//int InsertBSTree(BSTree **BStree, BSDataType data)
//{
//	BSTree *cur  = NULL;
//	BSTree *parent = NULL;
//
//	assert(BStree);
//	cur = *BStree;
//	//1.若二叉树为空
//	if (NULL == *BStree)    
//	{
//		*BStree = BuyNode(data);
//	}
//	//2.若二叉树不为空  
//	else
//	{
//		
//		//①.寻找插入的位置
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
//		//②.建立新结点
//		cur = BuyNode(data);
//		//③.data若比双亲大，则插右边，若比双亲小，则插左边
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
//递归插入
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
//中序遍历   左-->根-->右
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



////删除
//int  DeleteBSTree(BSTree **BStree, BSDataType data)
//{
//	BSTree *cur = NULL;
//	BSTree *del = NULL;      //要删除的结点
//	BSTree *parent = NULL;   //要删除结点的双亲结点
//	assert(BStree);
//	cur = *BStree;
//	if (*BStree == NULL)
//	{
//		return 0;
//	}
//	//寻找要删除的点
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
//		//证明要删除的元素不在二叉搜索树内
//		return 0;
//	}
//	//只有右孩子或者叶子
//	if (cur->_pleft == NULL)
//	{
//		//如果是根节点，让根节点指向它的右子树
//		if (cur == *BStree)
//		{
//			*BStree = (*BStree)->_pright;
//		}
//		else
//		{
//			//判断cur是双亲的左孩子还是右孩子
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
//	//只有左孩子
//	else if (cur->_pright == NULL)
//	{
//		//如果是根节点，让根节点指向它的左子树
//		if (cur == *BStree)
//		{
//			*BStree = (*BStree)->_pleft;
//		}
//		else
//		{
//			//判断cur是双亲的左孩子还是右孩子
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
//	//左右孩子均存在
//	else
//	{
//		del = cur->_pright;
//		parent = cur;
//		//找到右子树里面最小的一个
//		while (del->_pleft)
//		{
//			parent = del;
//			del = del->_pleft;
//		}
//		//将找到的结点的值赋给要删除的结点
//		cur->_data = del->_data;
//		//删除replace 
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


//递归删除
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
//查找
int  FindBSTree(BSTree *BStree, BSDataType data)
{
	BSTree *cur = BStree;
	//根节点为空，即二叉树为空，返回0
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
	//cur==NULL即没有找到元素和data相等，返回0
	return 0;
}

////递归查找
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

//销毁二叉树
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
