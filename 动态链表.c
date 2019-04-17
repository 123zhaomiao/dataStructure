#include"SeqList.h"
SeqList seq;    //定义一个全局变量seq

//测试尾部插入和尾部删除
void TestBack()
{
	//初始化
	InitSeqList(&seq);
	//尾部插入
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 3);
	//打印
	PrintSeqList(&seq);
	//尾部删除
	PopBackSeqList(&seq);
	PopBackSeqList(&seq);
	//打印
	PrintSeqList(&seq);
}


//测试头部插入和尾部删除
void TestFront()
{

	//初始化
	InitSeqList(&seq);
	//头部插入
	PushFrontSeqList(&seq, 3);
	PushFrontSeqList(&seq, 2);
	PushFrontSeqList(&seq, 1);
	//打印
	PrintSeqList(&seq);
	//头部删除
	PopFrontSeqList(&seq);
	PopFrontSeqList(&seq);
	//打印
	PrintSeqList(&seq);
}


//测试查找指定元素
void TestFind()
{
	int pos = 0;
	//初始化
	InitSeqList(&seq);
	//尾部插入
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 3);
	//打印
	PrintSeqList(&seq);
	//查找指定元素
	pos = FindSeqList(&seq, 2);
	if (pos == -1)
	{
		printf("没有找到！\n");
		return;
	}
	else
	{
		printf("下标是：%d\n", pos);
		//指定位置插入
		Insert(&seq, pos, 4);
		//打印
		PrintSeqList(&seq);
		//指定位置删除
		Erase(&seq, pos);
		//打印
		PrintSeqList(&seq);
	}
	
}


//测试删除指定元素
void TestRemove()
{
	//初始化
	InitSeqList(&seq);
	//尾部插入
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 3);
	//打印
	PrintSeqList(&seq);
	//删除指定元素
	Remove(&seq, 3);
	//打印
	PrintSeqList(&seq);
}

//测试删除所有的指定元素
void TestRemoveAll()
{
	//初始化
	InitSeqList(&seq);
	//尾部插入
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 3);
	//打印
	PrintSeqList(&seq);
	//删除指定元素
	RemoveAll(&seq, 3);
	//打印
	PrintSeqList(&seq);
}

//返回顺序表的大小
void TestSize()
{
	int sz = 0;
	//初始化
	InitSeqList(&seq);
	//尾部插入
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 3);
	//打印
	PrintSeqList(&seq);
	sz = sizeSeqList(&seq);
	printf("sz=%d\n", sz);
}

//判断顺序表是否为空
void TestEmpty()
{
	int sz = 0;
	//初始化
	InitSeqList(&seq);
	//尾部插入
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 3);
	//打印
	PrintSeqList(&seq);
	sz = EmptySeqList(&seq);
	if (sz == -1)
	{
		printf("顺序表为空！\n");
	}
	else
	{
		printf("顺序表不为空！\n");
	}
}

//测试冒泡排序
void TestBubble()
{
	//初始化
	InitSeqList(&seq);
	//尾部插入
	PushBackSeqList(&seq, 6);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 4);
	//打印
	PrintSeqList(&seq);
	Bubblesort(&seq);
	//打印
	PrintSeqList(&seq);
}

//测试选择排序
void TestSelectSort()
{
	//初始化
	InitSeqList(&seq);
	//尾部插入
	PushBackSeqList(&seq, 6);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 4);
	PushBackSeqList(&seq, 1);
	//打印
	PrintSeqList(&seq);
	SelectSort(&seq);
	//打印
	PrintSeqList(&seq);
}

//测试选择排序的优化
void  TestSelectSort_OP()
{
	//初始化
	InitSeqList(&seq);
	//尾部插入
	PushBackSeqList(&seq, 6);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 4);
	PushBackSeqList(&seq, 1);
	//打印
	PrintSeqList(&seq);
	SelectSort_OP(&seq);
	//打印
	PrintSeqList(&seq);
}

//二分查找
void TestBinarySearch()
{
	int pos = 0;
	//初始化
	InitSeqList(&seq);
	//尾部插入
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 3);
	//打印
	PrintSeqList(&seq);
	pos = BinarySearch(&seq, 1
		);
	if (pos == -1)
	{
		printf("没有找到！\n");
		return;
	}
	else
	{
		printf("下标为：%d\n", pos);
	}
}

//二分查找递归
void TestBinarySearch_R()
{
	int pos = 0;
	//初始化
	InitSeqList(&seq);
	//尾部插入
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 3);
	PushBackSeqList(&seq, 4);
	//打印
	PrintSeqList(&seq);
	pos = BinarySearch_R(&seq,0,seq.sz-1, 1);
	if (pos == -1)
	{
		printf("没有找到！\n");
		return;
	}
	else
	{
		printf("下标为：%d\n", pos);
	}
}
void test()
{
	//测试尾部插入和尾部删除
	TestBack();
	//测试头部插入和尾部删除
	//TestFront();
	//测试查找指定元素以及指定位置插入和指定位置删除
	//TestFind();
	//测试删除指定元素
	//TestRemove();
	//测试删除所有的指定元素
	//TestRemoveAll();
	//返回顺序表的大小
	//TestSize();
	//判断顺序表是否为空
	//TestEmpty();
	//测试冒泡排序
	//TestBubble();
	//测试选择排序
	//TestSelectSort();
	//测试选择排序的优化
	//TestSelectSort_OP();
	//二分查找
	//TestBinarySearch();
	//二分查找递归
	//TestBinarySearch_R();
}
int main()
{
	test();
	system("pause");
	return 0;
}
