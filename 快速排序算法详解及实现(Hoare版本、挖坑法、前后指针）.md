<font color="#dd0000">快速排序的思想：</font><br />&emsp;&emsp;快速排序是Hoare于1962年提出的一种二叉树结构的交换排序方法，其基本思想为：任取待排序元素序列中的某元素作为基准值 ，按照该基准值将待排序集合分割成两个子序列，左子序列中的所有元素小于基准值，右子序列中所有元素均大于基准值，然后对左右子序列重复该过程，知道所有的元素都排列在相应位置上为止。
<font color="#dd0000">将区间按照基准值划分为左右两部分的常见方法有：</font><br /> 

 - [ ] Hoare版本
![在这里插入图片描述](https://img-blog.csdn.net/20180924113906494?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3poYW9fbWlhbw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
 - [ ] 挖坑法
![在这里插入图片描述](https://img-blog.csdn.net/20180924113947696?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3poYW9fbWlhbw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
 - [ ] 前后指针法
![在这里插入图片描述](https://img-blog.csdn.net/20180924153133823?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3poYW9fbWlhbw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

<font color="#0000dd">&emsp;&emsp;若待排序的序列较长，使用递归的方法一层一层调用极易造成栈溢出，由于当待排序的序列长度逐渐减小时，元素已经接近有序，使用插入排序会更加快捷。</font><br /> 

代码实现：

```c
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


void Print(int *arr,int size);
//快速排序1
void quickSort(int *arr, int left, int right);



////////////////////////////////////////////////////////

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
		//左右指针
	    //position = qs1(arr, left, right - 1);
		//挖坑法
		position = qs2(arr, left, right - 1);
		//快速排序基准值左侧
		quickSort(arr, 0, position);
		//快速排序基准值右侧
		quickSort(arr, position + 1, right);
	}
}
```
测试

```c
#include"quickSort.h"

void TestquickSort()
{
	int array[] = {2,5,4,9,3,6,8,7,1,0};
	//打印
	printf("排序前: ");
	Print(array, sizeof(array) / sizeof(array[0]));
	//快速排序1
	quickSort(array,0, sizeof(array) / sizeof(array[0]));
	//quickSortNor(array, sizeof(array) / sizeof(array[0]));
	printf("排序后: ");
	Print(array, sizeof(array) / sizeof(array[0]));

}
int main()
{
	TestquickSort();
	system("pause");
	return 0;
}
```

![在这里插入图片描述](https://img-blog.csdn.net/20180924114030813?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3poYW9fbWlhbw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
**算法的平均时间复杂度：** o(nlogn)
**算法的空间复杂度：** o(1)
**算法的稳定性：** 稳定
**使用场景：** 数据量大，数据越随机越合适
 

