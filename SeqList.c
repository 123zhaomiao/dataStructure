#include"SeqList.h"

//��ʼ������
void SeqListInit(qSeqList seq)
{
	assert(seq);
	//��ʼ����������
	memset(seq->data,0, MAX*sizeof(DataType));
	//��ʼ��sz
	seq->sz = 0;
}


//β�巨
void PushBack(qSeqList seq, DataType data)
{
	assert(seq);
	//�ж��Ƿ���Բ��뼴�ж������Ƿ�С��MAX
	if (seq->sz >= MAX)
	{
		printf("�����������޷����룡\n");
		return;
	}
	//�����ݲ��뵽��seq->sz��λ����
	seq->data[seq->sz] = data;
	//����++
	seq->sz++;
}


//��ӡ
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

//β��ɾ��
void PopBack(qSeqList seq)
{
	assert(seq);
   //�ж��Ƿ����ɾ��
	if (seq->sz == 0)
	{
		printf("����Ϊ�գ�������ɾ��!");
		return;
	}
	//����--
	seq->sz--;
}

//ͷ������
void PushFront(qSeqList seq, DataType data)
{
	int i;
	assert(seq);
	//�ж��Ƿ���Բ���
	if (seq->sz >= MAX)
	{
		printf("�������������ܲ��룡\n");
		return;
	}
	//Ԫ��ȫ������
	for (i = seq->sz - 1 ; i >= 0; i--)
	{
		seq->data[i + 1] = seq->data[i];
	}
	//����
	seq->data[0] = data;
	//����++
	seq->sz++;
}

//ͷ��ɾ��
void PopFront(qSeqList seq)
{
	int i = 0;
	assert(seq);
	//�ж��Ƿ����ɾ��
	if (seq->sz == 0)
	{
		printf("����Ϊ�գ�����ɾ��!\n");
		return;
	}
	//ǰ��
	for (i = 1; i < seq->sz; i++)
	{
		seq->data[i - 1] = seq->data[i];
	}
	//����--
	seq->sz--;
}

//����ָ��Ԫ�ط����±�
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

//ָ��λ�ò���
void Insert(qSeqList seq, int pos, DataType data)
{
	int i = 0;
	assert(seq);
	//�ж��Ƿ���Բ���
	if (seq->sz >= MAX)
	{
		printf("�������������ܲ��룡\n");
		return;
	}
	//ָ��λ���Լ�֮���Ԫ�غ���
	for (i = seq->sz - 1; i >= pos; i--)
	{
		seq->data[i + 1] = seq->data[i];
	}
	//ָ��λ�ò���
	seq->data[pos] = data;
	//����++
	seq->sz++;
}

//ָ��λ��ɾ��
void Erase(qSeqList seq, int pos)
{
	int i = 0;
	assert(seq);
	//�ж��Ƿ����ɾ��
	if (seq->sz == 0)
	{
		printf("����Ϊ�գ����ܱ�ɾ����\n");
		return;
	}
	//ָ��λ��֮�������Ԫ��ǰ��
	for (i = pos + 1; i < seq->sz; i++)
	{
		seq->data[i - 1] = seq->data[i];
	}
	//����--
	seq->sz--;
}


//ɾ��ָ��Ԫ��
void Remove(qSeqList seq, DataType data)
{

	int i = 0;
	assert(seq);
	for (i = 0; i < seq->sz; i++)
	{
		if (seq->data[i] == data)
		{
			break;     //����ѭ����i��Ϊָ��λ��
		}
	}
	if (i < seq->sz)   //��i��Ч
	{
		int j = 0;
		for (j = i + 1; j < seq->sz ; j++)               // i�±꼴Ϊɾ���Ķ���
		{
			seq->data[j - 1] = seq->data[j];           //ָ��Ԫ��֮�������Ԫ��ǰ��
		}
		//����--
		seq->sz--;
	}
}


//ɾ��ȫ��ָ��Ԫ��
void Removeall(qSeqList seq, DataType data)
{
	int i = 0;
	assert(seq);
	for (i = 0; i < seq->sz; i++)
	{
		if (seq->data[i] == data)       // i�±꼴Ϊɾ�������λ��
		{
			int j = 0;
			for (j = i + 1; j < seq->sz; j++)    //ָ��Ԫ��֮�������Ԫ��ǰ�� 
			{
				seq->data[j - 1] = seq->data[j];          
			}
			//����--
			seq->sz--;
		}
	}
}


//����˳���Ĵ�С
int size(qSeqList seq)
{
	assert(seq);
	return seq->sz;
}

//�жϽṹ���Ƿ�Ϊ��
int Empty(qSeqList seq)
{
	assert(seq);
	return seq->sz == 0;//��ʽ����������(1)
}

static swap(DataType * px, DataType * py)
{
	DataType tmp = 0;
	tmp = *px;
	*px = *py;
	*py = tmp;
}
//ð������
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
				swap(seq->data + j, seq->data + j + 1); //����
				flag = 1;     //���ڽ�Լʱ�䣬���flag���ı䣬֤���ô����򣬲��ý����´�
			}
		}
		if (flag == 0)   //ѭ��һ�κ��ж�flag�Ƿ�Ϊ0�����Ϊ0��������ֱ�ӷ���
			return;
	}
}

//ѡ������
void Selectsort(qSeqList seq)
{
	int maxpos = 0;//���ֵ���±�
	int i = 0;
	int j = 0;
	assert(seq);
	for (i = 0; i < seq->sz-1; i++)
	{
		maxpos = 0;
		//Ѱ�����ֵ
		for (j = 1; j < seq->sz-i ; j++)
		{
			if (seq->data[j] > seq->data[maxpos])
				maxpos = j ;             
		}
		//�����ֵ�������һ��Ԫ�أ������ֵ�����һ��Ԫ�ؽ���
		if (maxpos != j-1)
		{
			swap(seq->data + maxpos, seq->data +j-1);
		}	
	}
}

//ѡ��������Ż�
void SelectsortOp(qSeqList seq)
{
	int left = 0;
	int right = seq->sz - 1;
	int i = 0;
	int maxpos = 0;  //���ֵ�±�
	int minpos = 0;  //��Сֵ�±�
	assert(seq);
	while (left <= right)
	{
		maxpos = left;
		minpos = left;
		for (i = left+1; i <= right; i++)     //�ҳ����ֵ����Сֵ
		{
			if (seq->data[i]>seq->data[maxpos])
				maxpos = i;
			if (seq->data[i] < seq->data[minpos])
				minpos = i;
		}
		if (maxpos != right)
		{
			swap(seq->data + maxpos, seq->data + right);  //���ֵ�������ұ�
		}
		//�����Сֵ��rightָ���λ�ã�����rightָ���λ���Ѿ���������ֵ
		//����Ӧ���޸���Сֵ���±꣬ʹ���䵽ԭ�����ֵ�ĵط�
		if (minpos == right)
		{
			minpos = maxpos;   
		}
		if (minpos != left)
		{
			swap(seq->data + minpos, seq->data + left);    //��Сֵ���������
		}
		left++;
		right--;
	}
}

//���ֲ���
int BinarySearch(qSeqList seq, DataType data)
{
	int left = 0;
	int right = seq->sz - 1;
	int mid = 0;
	assert(seq);
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (seq->data[mid] > data) //Ҫ�ҵ�������mid���
		{
			right = mid - 1;
		}
		else if (seq->data[mid] < data)//Ҫ�ҵ�������mid���
		{
			left = mid + 1;
		}
		else 
		{
			return mid;
		}
	}
	return -1;  //û�ҵ�
}

//���ֲ��ҵĵݹ�
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