#include"Heap.h"


//初始化堆
void InitHeap(Heap *hp, int *array, int size)
{
	assert(hp);
	hp->size = size;
	hp->capacity = 9;
	hp->data = (HDataType *)malloc(hp->capacity*sizeof(HDataType));
	if (hp->data == NULL)
	{
		assert(0);
		return;
	}
	//将array中size*sizeof(HDataType)个字节拷贝到hp->data
	memcpy(hp->data, array, size*sizeof(HDataType));
}

void Swap(HDataType *x, HDataType *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//向下调整
void AdjustDown(Heap *hp, int parent)
{
	//结点i的左孩子为：2*i+1
	int child = (parent << 1) + 1;
	while (child < hp->size)
	{
		//先保证有右孩子,然后获取左后孩子的最小值
		if (child+1 < hp->size && hp->data[child] > hp->data[child + 1])
		{
			child = child + 1;
		}
		//左后孩子的最小值和双亲比较，若双亲大，则与左右孩子的最小值交换
		if (hp->data[parent] > hp->data[child])
		{
			//交换
			Swap(&hp->data[child], &hp->data[parent]);
			parent = child;
			child = (parent << 1) + 1;
		}
		else
		{
			return;
		}
	}
}
//创建堆
void CreateHeap(Heap *hp, int *array, int size)
{
	//从第一个非叶子结点开始调整
	//结点i的双亲为： i-1/2；
	int root = (size - 2) >> 1;
	for (root; root >= 0; root--)
	{
		//向下调整
		AdjustDown(hp, root);
	}
}
//检验容量
void CheckCapacity(Heap *hp)
{
	int newcapacity = 0;
	HDataType *new = NULL;

	assert(hp);

	if (hp->size == hp->capacity)
	{
		newcapacity = hp->capacity * 2;
		new = (HDataType*)realloc(hp->data,newcapacity*sizeof(HDataType));
		if (new == NULL)
		{
			assert(0);
			return ;
		}
		hp->capacity = newcapacity;
		hp->data = new;
	}
}

//向上调整
void AdjustUp(Heap *hp, int parent)
{
	int child = 0;
	assert(hp);
	child = (parent << 1) + 1;
	while (child > 0)
	{
		if (hp->data[parent] > hp->data[child])
		{
			Swap(&hp->data[parent], &hp->data[child]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
		{
			return;
		}
	}
}
//插入堆
void InsertHeap(Heap *hp, HDataType data)
{
	assert(hp);
	int root = 0;
	CheckCapacity(hp);
	hp->data[hp->size++] = data;
	root = (hp->size - 2) >> 1;
	//向上调整
	AdjustUp(hp, root);
}


//删除
void DeleteHeap(Heap *hp)
{
	assert(hp);
	//堆顶元素和最后一个元素交换
	Swap(&hp->data[0], &hp->data[hp->size-1]);
	hp->size--;
	//向下调整
	AdjustDown(hp, 0);
}
//打印堆
void PrintHeap(Heap *hp)
{
	int i = 0;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
	}
	printf("\n");
}

//堆排序
void SortHeap(Heap *hp)
{
	int i = 0;
	int count = 0;
	assert(hp);
	count = hp->size;
	for (i = 0; i < count - 1; i++)
	{
		//第一个元素与最后一个交换
		Swap(&hp->data[0], &hp->data[hp->size - 1]);
		hp->size--;
		//向下调整成最小堆
		AdjustDown(hp, 0);
	}
	hp->size = count;
}
//销毁堆
void DestroyHeap(Heap *hp)
{
	assert(hp);
	free(hp->data);
	hp->data = NULL;
	hp->capacity = 0;
	hp->size = 0;
}
