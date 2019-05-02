#include"Heap.h"


//��ʼ����
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
	//��array��size*sizeof(HDataType)���ֽڿ�����hp->data
	memcpy(hp->data, array, size*sizeof(HDataType));
}

void Swap(HDataType *x, HDataType *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//���µ���
void AdjustDown(Heap *hp, int parent)
{
	//���i������Ϊ��2*i+1
	int child = (parent << 1) + 1;
	while (child < hp->size)
	{
		//�ȱ�֤���Һ���,Ȼ���ȡ����ӵ���Сֵ
		if (child+1 < hp->size && hp->data[child] > hp->data[child + 1])
		{
			child = child + 1;
		}
		//����ӵ���Сֵ��˫�ױȽϣ���˫�״��������Һ��ӵ���Сֵ����
		if (hp->data[parent] > hp->data[child])
		{
			//����
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
//������
void CreateHeap(Heap *hp, int *array, int size)
{
	//�ӵ�һ����Ҷ�ӽ�㿪ʼ����
	//���i��˫��Ϊ�� i-1/2��
	int root = (size - 2) >> 1;
	for (root; root >= 0; root--)
	{
		//���µ���
		AdjustDown(hp, root);
	}
}
//��������
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

//���ϵ���
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
//�����
void InsertHeap(Heap *hp, HDataType data)
{
	assert(hp);
	int root = 0;
	CheckCapacity(hp);
	hp->data[hp->size++] = data;
	root = (hp->size - 2) >> 1;
	//���ϵ���
	AdjustUp(hp, root);
}


//ɾ��
void DeleteHeap(Heap *hp)
{
	assert(hp);
	//�Ѷ�Ԫ�غ����һ��Ԫ�ؽ���
	Swap(&hp->data[0], &hp->data[hp->size-1]);
	hp->size--;
	//���µ���
	AdjustDown(hp, 0);
}
//��ӡ��
void PrintHeap(Heap *hp)
{
	int i = 0;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
	}
	printf("\n");
}

//������
void SortHeap(Heap *hp)
{
	int i = 0;
	int count = 0;
	assert(hp);
	count = hp->size;
	for (i = 0; i < count - 1; i++)
	{
		//��һ��Ԫ�������һ������
		Swap(&hp->data[0], &hp->data[hp->size - 1]);
		hp->size--;
		//���µ�������С��
		AdjustDown(hp, 0);
	}
	hp->size = count;
}
//���ٶ�
void DestroyHeap(Heap *hp)
{
	assert(hp);
	free(hp->data);
	hp->data = NULL;
	hp->capacity = 0;
	hp->size = 0;
}