#include"SeqList.h"

//初始化函数
void InitSeqList(qSeqList seq)
{
	assert(seq);
	//初始化sz
	seq->sz = 0;
	//初始化capacity
	seq->capacity = 10;
	//初始化data
	seq->data = (DataType *)malloc(seq->capacity*sizeof(DataType));
	if (seq->data == NULL)
	{
		printf("空间开辟失败！\n");
		return;
	}
}

//打印函数
void PrintSeqList(qSeqList seq)
{
	assert(seq);
	int i = 0; //循环变量
	for (i = 0; i < seq->sz; i++)
	{
		printf("%d ", seq->data[i]);
	}
	printf("\n");
}


//检查容量
static int Check_Capacity(qSeqList seq)
{
	DataType *seqnew = NULL;     //新空间的地址
	int Newcapacity = 0;            
	//如果有效个数大于等于容量则增容
	if (seq->sz >= seq->capacity)
	{
		Newcapacity = seq->capacity + 5;
		seqnew = realloc(seq->data, Newcapacity*sizeof(DataType));
		if (seq == NULL)
		{
			printf("空间开辟失败！\n");
			return -1;
		}
		else
		{
			seq->data = seqnew;                 //新空间的地址交给原空间的地址
			seq->capacity = Newcapacity;        //容量更新
			return 1;
		}
	}
	//如果有效个数小容量则直接返回
	else
		return 1;
}


//尾部插入
void PushBackSeqList(qSeqList seq, DataType data)
{
	assert(seq);
	int ret = Check_Capacity(seq);
	if (ret == 1)
	{
		seq->data[seq->sz] = data;
		seq->sz++;
	}
}
//尾部删除
void PopBackSeqList(qSeqList seq)
{
	if (seq->sz == 0)
	{
		printf("没有可以删除的数据了！\n");
		return;
	}
	else
		seq->sz--;
}


//头部插入
void PushFrontSeqList(qSeqList seq, DataType data)
{
	assert(seq);
	int ret = Check_Capacity(seq); //判断是否可以插入
	int i = 0;
	if (ret == 1)
	{
		for (i = seq->sz - 1; i >= 0; i--)   //元素后移
		{
			seq->data[i+1] = seq->data[i];
		}
		seq->data[0] = data;
		seq->sz++;
	}
}
//头部删除
void PopFrontSeqList(qSeqList seq)
{
	int i = 0;
	if (seq->sz == 0)
	{
		printf("没有可以删除的数据了！\n");
		return;
	}
	else
	{
		for (i = 1; i < seq->sz; i++)  //元素前移
		{
			seq->data[i-1] = seq->data[i];
		}
		seq->sz--;  //容量--
	}
}

//查找指定元素
int FindSeqList(qSeqList seq, DataType data)
{
	int i = 0;
	assert(seq);
	for (i = 0; i < seq->sz; i++)
	{
		if (seq->data[i] == data)
			return i;
	}
	return -1;
}
//指定位置插入
void Insert(qSeqList seq, int pos, DataType data)
{
	int i = 0;
	assert(seq);
	int ret = Check_Capacity(seq);
	if (ret == 1)
	{
		for (i = seq->sz - 1;i>=pos; i--)
		{
			seq->data[i+1] = seq->data[i];
		}
		seq->data[pos] = data;
		seq->sz++;                   //容量++
	}
}
//指定位置删除
void Erase(qSeqList seq, int pos)
{
	int i = 0;
	assert(seq);
	if (seq->sz == 0)
	{
		printf("没有可以删除的数据！\n");
		return;
	}
	for (i = pos + 1;i < seq->sz; i++)
	{
		seq->data[i - 1] = seq->data[i];
	}
	seq->sz--;   //容量--
}

//删除指定元素
void Remove(qSeqList seq, DataType data)
{
	int i = 0;
	int j = 0;
	assert(seq);
	for (i = 0; i < seq->sz; i++)
	{
		if (seq->data[i] == data)
			break;
	}
	if (i < seq->sz)
	{
		//元素移动
		for (j = i + 1; j < seq->sz; j++)
		{
			seq->data[j - 1] = seq->data[j];
		}
		seq->sz--;//容量--
	}
	else
		printf("没有该元素！\n");
}

//删除全部指定元素
void RemoveAll(qSeqList seq, DataType data)
{
	int i = 0;
	int j = 0;
	assert(seq);
	for (i = 0; i < seq->sz; i++)
	{
		if (seq->data[i] == data)
		{
			//元素移动
			for (j = i + 1; j < seq->sz; j++)
			{
				seq->data[j - 1] = seq->data[j];
			}
			seq->sz--;//容量--
		}
	}
}

//返回顺序表的大小
int sizeSeqList(qSeqList seq)
{
	return seq->sz;
}


//判断顺序表是否为空
int EmptySeqList(qSeqList seq)
{
	if (seq->sz == 0)
	{
		return -1;
	}
	return 0;
}

//交换
static void swap(DataType *x, DataType *y)
{
	DataType tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
//冒泡排序
void Bubblesort(qSeqList seq)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	assert(seq);
	for (i = 0; i < seq->sz - 1; i++)
	{
		flag = 0;
		for (j = 0; j < seq->sz - i-1; j++)
		{
			if (seq->data[j]>seq->data[j + 1])
			{
				//交换
				swap(seq->data + j, seq->data + j + 1);
				flag = 1;
			}
		}
		if (flag = 0)
		{
			return;
		}
	}
}

//选择排序
void SelectSort(qSeqList seq)
{
	int maxpos = 0;    //最大值下标
	int i = 0;
	int j = 0;
	assert(seq);
	for (i = 0; i < seq->sz; i++)
	{
		maxpos = 0;
		for (j = 1; j < seq->sz - i; j++)
		{
			if (seq->data[j]>seq->data[maxpos])
				maxpos = j;
		}
		if (maxpos != j - 1)
		{
			swap(seq->data + maxpos, seq->data + j - 1);
		}
	}
}

//选择排序的优化
void SelectSort_OP(qSeqList seq)
{
	int left = 0;    
	int right = seq->sz - 1;
	int maxpos = 0;   //最大值下标
	int minpos = 0;   //最小值下标
	int i = 0;
	assert(seq);
	while (left <= right)
	{
		maxpos = left;
		minpos = left;
		for (i = left + 1; i <= right; i++)
		{
			if (seq->data[i]>seq->data[maxpos])
				maxpos = i;

			if (seq->data[i]<seq->data[minpos])
				minpos = i;
		}
		if (maxpos != right)
			swap(seq->data + maxpos, seq->data + right);
		if (minpos == right)
			minpos = maxpos;
		if (minpos != left)
			swap(seq->data + left, seq->data + minpos);
		left++;
		right--;
	}
}

//二分查找
int  BinarySearch(qSeqList seq, DataType data)
{
	int left = 0;
	int right = seq->sz - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (seq->data[mid] > data)
		{
			right = mid - 1;
		}
		else if (seq->data[mid] < data)
		{
			left = mid + 1;
		}
		else
			return mid;
	}
	return -1;
}


//二分查找的递归
int BinarySearch_R(qSeqList seq, int left, int right, DataType data)
{
	int mid = left + (right - left) / 2;
	assert(seq);
	if (left <= right)
	{
		if (seq->data[mid] > data)
		{
			return BinarySearch_R(seq, left, mid - 1, data);
		}
		else if (seq->data[mid] < data)
		{
			return BinarySearch_R(seq, mid + 1, right, data);
		}
		
		{
			return mid;
		}
	}
	return -1;
}