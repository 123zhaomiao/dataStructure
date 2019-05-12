#include"SeqList.h"

//初始化函数
void SeqListInit(qSeqList seq)
{
	assert(seq);
	//初始化整个数组
	memset(seq->data,0, MAX*sizeof(DataType));
	//初始化sz
	seq->sz = 0;
}


//尾插法
void PushBack(qSeqList seq, DataType data)
{
	assert(seq);
	//判断是否可以插入即判断容量是否小于MAX
	if (seq->sz >= MAX)
	{
		printf("容量已满，无法插入！\n");
		return;
	}
	//将数据插入到第seq->sz的位置上
	seq->data[seq->sz] = data;
	//容量++
	seq->sz++;
}


//打印
void PrintSeqList(qSeqList seq)
{
	int i = 0;
	assert(seq);
	for (i = 0; i < seq->sz; i++)
	{
		printf("%d ", seq->data[i]);
	}
	printf("\n");
}

//尾部删除
void PopBack(qSeqList seq)
{
	assert(seq);
   //判断是否可以删除
	if (seq->sz == 0)
	{
		printf("数组为空，不可以删除!");
		return;
	}
	//容量--
	seq->sz--;
}

//头部插入
void PushFront(qSeqList seq, DataType data)
{
	int i;
	assert(seq);
	//判断是否可以插入
	if (seq->sz >= MAX)
	{
		printf("数组已满，不能插入！\n");
		return;
	}
	//元素全部后移
	for (i = seq->sz - 1 ; i >= 0; i--)
	{
		seq->data[i + 1] = seq->data[i];
	}
	//插入
	seq->data[0] = data;
	//容量++
	seq->sz++;
}

//头部删除
void PopFront(qSeqList seq)
{
	int i = 0;
	assert(seq);
	//判断是否可以删除
	if (seq->sz == 0)
	{
		printf("数组为空，不能删除!\n");
		return;
	}
	//前移
	for (i = 1; i < seq->sz; i++)
	{
		seq->data[i - 1] = seq->data[i];
	}
	//容量--
	seq->sz--;
}

//查找指定元素返回下标
int  Front(qSeqList seq, DataType data)
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
	//判断是否可以插入
	if (seq->sz >= MAX)
	{
		printf("数组已满，不能插入！\n");
		return;
	}
	//指定位置以及之后的元素后移
	for (i = seq->sz - 1; i >= pos; i--)
	{
		seq->data[i + 1] = seq->data[i];
	}
	//指定位置插入
	seq->data[pos] = data;
	//容量++
	seq->sz++;
}

//指定位置删除
void Erase(qSeqList seq, int pos)
{
	int i = 0;
	assert(seq);
	//判断是否可以删除
	if (seq->sz == 0)
	{
		printf("数组为空，不能被删除！\n");
		return;
	}
	//指定位置之后的所有元素前移
	for (i = pos + 1; i < seq->sz; i++)
	{
		seq->data[i - 1] = seq->data[i];
	}
	//容量--
	seq->sz--;
}


//删除指定元素
void Remove(qSeqList seq, DataType data)
{

	int i = 0;
	assert(seq);
	for (i = 0; i < seq->sz; i++)
	{
		if (seq->data[i] == data)
		{
			break;     //跳出循环，i即为指定位置
		}
	}
	if (i < seq->sz)   //若i有效
	{
		int j = 0;
		for (j = i + 1; j < seq->sz ; j++)               // i下标即为删除的对象
		{
			seq->data[j - 1] = seq->data[j];           //指定元素之后的所有元素前移
		}
		//容量--
		seq->sz--;
	}
}


//删除全部指定元素
void Removeall(qSeqList seq, DataType data)
{
	int i = 0;
	assert(seq);
	for (i = 0; i < seq->sz; i++)
	{
		if (seq->data[i] == data)       // i下标即为删除对象的位置
		{
			int j = 0;
			for (j = i + 1; j < seq->sz; j++)    //指定元素之后的所有元素前移 
			{
				seq->data[j - 1] = seq->data[j];          
			}
			//容量--
			seq->sz--;
		}
	}
}


//返回顺序表的大小
int size(qSeqList seq)
{
	assert(seq);
	return seq->sz;
}

//判断结构体是否为空
int Empty(qSeqList seq)
{
	assert(seq);
	return seq->sz == 0;//等式成立返回真(1)
}

static swap(DataType * px, DataType * py)
{
	DataType tmp = 0;
	tmp = *px;
	*px = *py;
	*py = tmp;
}
//冒泡排序
void Bubble(qSeqList seq)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	assert(seq);
	for (i = 0; i < seq->sz - 1; i++)
	{
		flag = 0;
		for (j = 0; j < seq->sz - 1- i; j++)
		{
			if (seq->data[j] < seq->data[j + 1])
			{
				swap(seq->data + j, seq->data + j + 1); //交换
				flag = 1;     //用于节约时间，如果flag不改变，证明该次有序，不用进行下次
			}
		}
		if (flag == 0)   //循环一次后判断flag是否为0，如果为0，即有序，直接返回
			return;
	}
}

//选择排序
void Selectsort(qSeqList seq)
{
	int maxpos = 0;//最大值的下标
	int i = 0;
	int j = 0;
	assert(seq);
	for (i = 0; i < seq->sz-1; i++)
	{
		maxpos = 0;
		//寻找最大值
		for (j = 1; j < seq->sz-i ; j++)
		{
			if (seq->data[j] > seq->data[maxpos])
				maxpos = j ;             
		}
		//若最大值不是最后一个元素，则将最大值和最后一个元素交换
		if (maxpos != j-1)
		{
			swap(seq->data + maxpos, seq->data +j-1);
		}	
	}
}

//选择排序的优化
void SelectsortOp(qSeqList seq)
{
	int left = 0;
	int right = seq->sz - 1;
	int i = 0;
	int maxpos = 0;  //最大值下标
	int minpos = 0;  //最小值下标
	assert(seq);
	while (left <= right)
	{
		maxpos = left;
		minpos = left;
		for (i = left+1; i <= right; i++)     //找出最大值和最小值
		{
			if (seq->data[i]>seq->data[maxpos])
				maxpos = i;
			if (seq->data[i] < seq->data[minpos])
				minpos = i;
		}
		if (maxpos != right)
		{
			swap(seq->data + maxpos, seq->data + right);  //最大值放在最右边
		}
		//如果最小值在right指向的位置，由于right指向的位置已经变成了最大值
		//所以应该修改最小值的下标，使得其到原来最大值的地方
		if (minpos == right)
		{
			minpos = maxpos;   
		}
		if (minpos != left)
		{
			swap(seq->data + minpos, seq->data + left);    //最小值放在最左边
		}
		left++;
		right--;
	}
}

//二分查找
int BinarySearch(qSeqList seq, DataType data)
{
	int left = 0;
	int right = seq->sz - 1;
	int mid = 0;
	assert(seq);
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (seq->data[mid] > data) //要找的数据在mid左边
		{
			right = mid - 1;
		}
		else if (seq->data[mid] < data)//要找的数据在mid左边
		{
			left = mid + 1;
		}
		else 
		{
			return mid;
		}
	}
	return -1;  //没找到
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
		else
		{
			return mid;
		}
		return -1;
	}
}