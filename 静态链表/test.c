#include"SeqList.h"


//尾部测试
testBack()
{
	//定义一个结构体seq
	SeqList seq;
	//初始化结构体
	SeqListInit(&seq);
	//尾插法
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	//打印
	PrintSeqList(&seq);
	//尾部删除
	PopBack(&seq);
	//打印
	PrintSeqList(&seq);
}

//头部测试
testFront()
{
	//定义一个结构体seq
	SeqList seq;
	//初始化结构体
	SeqListInit(&seq);
	//头部插入
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	//打印
	PrintSeqList(&seq);
	//头部删除
	PopFront(&seq);
	//打印
	PrintSeqList(&seq);
}

//查找
void testFind()
{
	//定义一个结构体seq
	SeqList seq;
	int pos = 0;
	//初始化结构体
	SeqListInit(&seq);
	//插入
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	//查找指定元素
	pos = Front(&seq, 1);
	if (pos == -1)
	{
		printf("找不到！\n");
		return;
	}
	else
	{
		printf("下标为：%d\n", pos);
	}
}


//指定位置插入
void testInsert()
{
	//定义一个结构体seq
	SeqList seq;
	int pos = 0;
	//初始化结构体
	SeqListInit(&seq);
	//插入
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	//查找指定元素
	pos = Front(&seq, 1);
	if (pos == -1)
	{
		printf("找不到指定位置！\n");
		return;
	}
	else
	{
		//指定位置插入
		Insert(&seq, pos, 5);
		//打印
		PrintSeqList(&seq);
	}
}

//指定位置删除
void testErase()
{
	//定义一个结构体seq
	SeqList seq;
	int pos = 0;
	//初始化结构体
	SeqListInit(&seq);
	//插入
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	//查找指定元素
	pos = Front(&seq, 3);
	if (pos == -1)
	{
		printf("找不到指定位置！\n");
		return;
	}
	else
	{
		//指定位置删除
		Erase(&seq, pos);
		//打印
		PrintSeqList(&seq);
	}
}

//删除指定元素
void testRemove()
{
	//定义一个结构体seq
	SeqList seq;
	//初始化结构体
	SeqListInit(&seq);
	//插入
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	Remove(&seq, 1);
	//打印
	PrintSeqList(&seq);
}


//删除全部指定元素
void testRemoveall()
{
	//定义一个结构体seq
	SeqList seq;
	//初始化结构体
	SeqListInit(&seq);
	//插入
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	Removeall(&seq, 1);
	//打印
	PrintSeqList(&seq);
}

//返回顺序表的大小
void testsize()
{
	//定义一个结构体seq
	SeqList seq;
	int l = 0;
	//初始化结构体
	SeqListInit(&seq);
	//插入
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	l = size(&seq);
	printf("size=%d \n", l);
}

//判断顺序表是否为空
void testEmpty()
{
	//定义一个结构体seq
	SeqList seq;
	int s = 0;
	//初始化结构体
	SeqListInit(&seq);
	//插入
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	s = Empty(&seq);
	if (s == 1)
	{
		printf("结构体为空！\n");
		return;
	}
	else
		printf("结构体不为空！\n");
}
//冒泡排序
void testBubble()
{
	//定义一个结构体seq
	SeqList seq;
	//初始化结构体
	SeqListInit(&seq);
	//插入
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	//打印
	PrintSeqList(&seq);
	Bubble(&seq);
	//打印
	PrintSeqList(&seq);
}
//选择排序
testSelectsort()
{
	//定义一个结构体seq
	SeqList seq;
	//初始化结构体
	SeqListInit(&seq);
	//插入
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	//打印
	PrintSeqList(&seq);
	Selectsort(&seq);
	//打印
	PrintSeqList(&seq);
}


//选择排序的优化
void testSelectsortOp()
{
	//定义一个结构体seq
	SeqList seq;
	//初始化结构体
	SeqListInit(&seq);
	//插入
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	//打印
	PrintSeqList(&seq);
	SelectsortOp(&seq);
	//打印
	PrintSeqList(&seq);
}

//二分查找
void testBinarySearch()
{
	//定义一个结构体seq
	SeqList seq;
	int pos = 0;
	//初始化结构体
	SeqListInit(&seq);
	//插入
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	//打印
	PrintSeqList(&seq);
	pos = BinarySearch(&seq,4);
	if (pos == -1)
	{
		printf("找不到该元素！\n");
		return;
	}
	else
	{
		printf("下标为：%d\n", pos);
		return;
	}
}
//二分查找的递归
void testBinarySearch_R()
{
	//定义一个结构体seq
	SeqList seq;
	int pos = 0;
	//初始化结构体
	SeqListInit(&seq);
	//插入
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	//打印
	PrintSeqList(&seq);
	pos = BinarySearch_R(&seq, 0,seq.sz-1,2);
	if (pos ==-1 )
	{
		printf("找不到该元素！\n");
		return;
	}
	else
	{
		printf("下标为：%d\n", pos);
		return;
	}
}
void test()
{
	
	//testBack();
	//testFront();
	//查找指定元素
	//testFind();
	//指定位置插入
	//testInsert();
	//指定位置删除
	//testErase();
	//删除指定元素
	//testRemove();
	//删除全部指定元素
	//testRemoveall();
	//返回顺序表的大小
	//testsize();
	//判断顺序表是否为空
	//testEmpty();
	//冒泡排序
	//testBubble();
	//选择排序
	//testSelectsort();
	//选择排序优化
	//testSelectsortOp();
	//二分查找
	//testBinarySearch();
	//二分查找的递归
	testBinarySearch_R();
}
int main()
{
	test();
	system("pause");
	return 0;
}
