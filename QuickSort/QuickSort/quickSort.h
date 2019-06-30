#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>

void Print(int *arr,int size);
//归并
void Merge_sortNor(int *arr, int size, int*temp);
//归并
void Merge_sort(int *arr, int left, int right, int*temp);
//快速排序1
void quickSort(int *arr, int left, int right);
//快速排序1
void quickSortNor(int *arr, int size);
typedef struct Stack{
	int *data;
	int size;
	
}stack;

////////////////////////////////////////////////////////
void  InitStack(stack *s)
{
	int *data = (int*)malloc(20 * sizeof(int));
	if (data == NULL)
	{
		assert(0);
		return;
	}
	s->data = data;
	s->size = 0;
}
void PushStack(stack *s,int d)
{
	assert(s);
	if (s->size > 20)
	{
		return;
	}
	else
		s->data[s->size++] = d;
}
void PopStack(stack *s)
{
	assert(s);
	if (s->size == 0)
	{
		return;
	}
	else
		s->size--;
}
int TopStack(stack *s)
{
	assert(s);
	return s->data[s->size-1];
		
}
int EmptyStack(stack *s)
{
	assert(s);
	return s->size == 0;
}
void InsertSort(int *array, int size)
{
	int i = 0;
	//要插入的位置的前一个位置
	int pos = 0;
	int k = 0;
	//循环需要size-1次
	for (i = 1; i < size; i++)
	{
		//从被插入的元素的前一个元素开始比较
		pos = i - 1;
		//记录要插入的元素
		k = array[i];
		//如果被插入的元素比前一个元素小，则将元素右移，然后和前一个元素比较
		//如果被插入的元素比前一个元素大，则直接插入
		while (k < array[pos] && pos >= 0)
		{
			//说明该元素k要插在pos的前面，所以pos后移
			array[pos + 1] = array[pos];
			pos--;
		}
		//插
		array[pos + 1] = k;
	}
}
//打印函数
void Print(int *arr, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int *x, int *y)

{
	/*int tmp = *x;
	*x = *y;
	*y = tmp;*/
	*x = ((*x) ^ (*y));
	*y = ((*x) ^ (*y));
	*x = ((*x) ^ (*y));
}
int MiddleNumber(int *arr, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (arr[begin] > arr[mid])
	{
		if (arr[begin] > arr[end])
		{
			if (arr[mid] > arr[end])
			{
				return mid;
			}
			else
				return end;
		}
		else
			return begin;
	}
	else
	{
		if (arr[mid] > arr[end])
		{
			if (arr[begin] > arr[end])
			{
				return begin;
			}
			else
			{
				return end;
			}
		}
		else
			return mid;
	}
	
}
/*
  Hoare方法
  快速排序1
  以数组最后一个元素作为基准key、设置两个指针bengin、end
  bengin从前往后移动遇到比基准key大的停止
  end从后往前移动遇到比基准key小的停止
  bengin和end所对应的数据交换
  重复直至bengin==end
*/
int qs1(int *arr, int begin, int end)
{
	//找基准
	/*
	由于每次规划取到最大值或最小值的概率
	都非常高，这样容易使树变成单支树，所以采用三数取中法
	来降低取到最值的概率
	*/
	int index = MiddleNumber(arr, begin, end);
	if (index != end)
	{
		swap(&arr[index], &arr[end]);
	}
	int key = arr[end];


	//基准值的下标
	int k = end;
	//两个指针、begin从0开始、end从size-1开始
	while (begin != end)
	{
		//begin向后移动，找比基准k大的元素,且begin不能大于end
		//如果arr[begin]比key小，则begin++
		while (arr[begin] <= key && (begin < end))
		{
			begin++;
		}

		//end向前移动，找比基准key小的元素，且end不能小于begin
		//如果arr[end]比key大，则end--
		while (arr[end] >= key && (begin < end))
		{
			end--;
		}

		//如果begin和end对应的值不相等，则交换
		if (begin != end)
		{
			//交换bengin和end所对应的值
			swap(&arr[begin], &arr[end]);
		}
	}
	//如果begin的最终位置就是基准的位置则不用交换
	if (begin != k)
	{
		//将基准值挪到相应的位置上
		swap(&arr[begin], &arr[k]);
	}
	return begin;
}

/*
  挖坑法
  先将最后一个元素标记设置为第一个坑
  设置两个指针begin、end
  begin从左边开始找比关键字大的元素将其入坑，begin所在位置变为坑
  end从右边开始找比关键字小的元素将其入坑,end所在位置变为坑
  知道begin==end将标记的第一个元素入坑
*/
int qs2(int *arr, int begin, int end)
{
	//找基准
	/*
	由于每次规划取到最大值或最小值的概率
	都非常高，这样容易使树变成单支树，所以采用三数取中法
	来降低取到最值的概率
	*/
	int index = MiddleNumber(arr, begin, end);
	if (index != end)
	{
		swap(&arr[index], &arr[end]);
	}
	//第一个坑
	int key = arr[end];
	int k = end;
	while (begin != end)
	{
		/*begin从左边开始找比关键字大的元素将其入坑
		，begin所在位置变为坑*/
		while (arr[begin] <= key&&begin < end)
		{
			begin++;
		}
		if (begin != end)
		{
			arr[end] = arr[begin];
			end--;
		}
		/*end从右开始找比关键字小的元素将其入begin坑*/
		while (arr[end] >= key&&begin < end)
		{
			end--;
		}
		if (begin != end)
		{
			arr[begin] = arr[end];
			begin++;
		}
	}
	if (begin != k)
	{
		arr[begin] = key;
	}
	return begin;
}
/*
	前后指针法
	cur在待排序序列的最左侧
	perv=cur-1
	如果arr[cur]<key,则prev一直跟在cur的后面
	如果arr[cur]>key,则prev停止，cur向前走，直至arr[cur]<key
	cur与prev对应的元素交换；重复，直至cur超过待排序序列的长度
	prev和cur中间是比基准值大的元素
*/
int qs3(int *arr, int begin, int end)
{
	//找基准
	/*
	由于每次规划取到最大值或最小值的概率
	都非常高，这样容易使树变成单支树，所以采用三数取中法
	来降低取到最值的概率
	*/
	int index = MiddleNumber(arr, begin, end);
	int cur = begin;
	int prev = begin - 1;
	if (index != end)
	{
		swap(&arr[index], &arr[end]);
	}
	int key = arr[end];
	//cur不能超过序列长度
	while (cur <= end)
	{
		if (arr[cur] <= key&&++prev != cur)
		{
			swap(&arr[cur], &arr[prev]);
		}
		cur++;
	}
		return prev;
}
void quickSort(int *arr, int left,int right)
{
	int position ;
	/*
	由于快速排序是递归调用，容易产生栈溢出
	但是快速排序排到最后元素也接近有序，则采用插入排序
	*/
	if (right - left<2)
	{
		InsertSort(arr + left, right - left);
	}
	else                             
	{
		//Hoare
	   // position = qs1(arr, left, right - 1);
		//挖坑法
		//position = qs2(arr, left, right - 1);
		//前后指针
		position = qs3(arr, left, right - 1);
		//快速排序基准值左侧
		quickSort(arr, 0, position);
		//快速排序基准值右侧
		quickSort(arr, position + 1, right);
	}
}



//快速排序1
void quickSortNor(int *arr, int size)
{
	stack s;
	int position;
	int left = 0;
	int right = 0;
	InitStack(&s);
	PushStack(&s, 0);
	PushStack(&s, size);
	while (!EmptyStack(&s))
	{
		right = TopStack(&s);
		PopStack(&s);
		left=TopStack(&s);
		PopStack(&s);
		position = qs2(arr, left, right - 1);
		//先快排基准左侧，则先将后侧的下标入栈
		if ((right - left) > position + 1)
		{
			PushStack(&s, position + 1);
			PushStack(&s, right - left);
		}
		if (position > 0)
		{
			PushStack(&s, 0);
			PushStack(&s, position);
		}
	}
}
void merge(int *arr, int *temp, int left, int mid, int right)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid+1;
	int end2 = right;
	int index = left;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
		{
			temp[index] = arr[begin1];
			index++;
			begin1++;
		}
		else
		{
			temp[index] = arr[begin2];
			index++;
			begin2++;
		}
	}
	while (begin1 <= end1)
	{
		temp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[index++] = arr[begin2++];
	}

}
void Merge_sort(int *arr, int left, int right,int*temp)
{

	if (right - left < 2)
	{
		InsertSort(arr + left, right - left+1);
		return;
	}
	int mid = left + ((right - left) >> 1);
	
	Merge_sort(arr, left, mid, temp);
	Merge_sort(arr, mid+1, right, temp);
	merge(arr,temp,left,mid,right);
	memcpy(arr, temp, 10*sizeof(int));
}

//归并
void Merge_sortNor(int *arr,int size, int*temp)
{

	int left = 0;
	int right = size;
	int mid = left + ((right - left) >> 1);
	merge(arr, temp, left, mid, right);
	memcpy(arr, temp, 10 * sizeof(int));
}
