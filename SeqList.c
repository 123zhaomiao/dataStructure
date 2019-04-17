#include"SeqList.h"

//��ʼ������
void InitSeqList(qSeqList seq)
{
	assert(seq);
	//��ʼ��sz
	seq->sz = 0;
	//��ʼ��capacity
	seq->capacity = 10;
	//��ʼ��data
	seq->data = (DataType *)malloc(seq->capacity*sizeof(DataType));
	if (seq->data == NULL)
	{
		printf("�ռ俪��ʧ�ܣ�\n");
		return;
	}
}

//��ӡ����
void PrintSeqList(qSeqList seq)
{
	assert(seq);
	int i = 0; //ѭ������
	for (i = 0; i < seq->sz; i++)
	{
		printf("%d ", seq->data[i]);
	}
	printf("\n");
}


//�������
static int Check_Capacity(qSeqList seq)
{
	DataType *seqnew = NULL;     //�¿ռ�ĵ�ַ
	int Newcapacity = 0;            
	//�����Ч�������ڵ�������������
	if (seq->sz >= seq->capacity)
	{
		Newcapacity = seq->capacity + 5;
		seqnew = realloc(seq->data, Newcapacity*sizeof(DataType));
		if (seq == NULL)
		{
			printf("�ռ俪��ʧ�ܣ�\n");
			return -1;
		}
		else
		{
			seq->data = seqnew;                 //�¿ռ�ĵ�ַ����ԭ�ռ�ĵ�ַ
			seq->capacity = Newcapacity;        //��������
			return 1;
		}
	}
	//�����Ч����С������ֱ�ӷ���
	else
		return 1;
}


//β������
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
//β��ɾ��
void PopBackSeqList(qSeqList seq)
{
	if (seq->sz == 0)
	{
		printf("û�п���ɾ���������ˣ�\n");
		return;
	}
	else
		seq->sz--;
}


//ͷ������
void PushFrontSeqList(qSeqList seq, DataType data)
{
	assert(seq);
	int ret = Check_Capacity(seq); //�ж��Ƿ���Բ���
	int i = 0;
	if (ret == 1)
	{
		for (i = seq->sz - 1; i >= 0; i--)   //Ԫ�غ���
		{
			seq->data[i+1] = seq->data[i];
		}
		seq->data[0] = data;
		seq->sz++;
	}
}
//ͷ��ɾ��
void PopFrontSeqList(qSeqList seq)
{
	int i = 0;
	if (seq->sz == 0)
	{
		printf("û�п���ɾ���������ˣ�\n");
		return;
	}
	else
	{
		for (i = 1; i < seq->sz; i++)  //Ԫ��ǰ��
		{
			seq->data[i-1] = seq->data[i];
		}
		seq->sz--;  //����--
	}
}

//����ָ��Ԫ��
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
//ָ��λ�ò���
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
		seq->sz++;                   //����++
	}
}
//ָ��λ��ɾ��
void Erase(qSeqList seq, int pos)
{
	int i = 0;
	assert(seq);
	if (seq->sz == 0)
	{
		printf("û�п���ɾ�������ݣ�\n");
		return;
	}
	for (i = pos + 1;i < seq->sz; i++)
	{
		seq->data[i - 1] = seq->data[i];
	}
	seq->sz--;   //����--
}

//ɾ��ָ��Ԫ��
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
		//Ԫ���ƶ�
		for (j = i + 1; j < seq->sz; j++)
		{
			seq->data[j - 1] = seq->data[j];
		}
		seq->sz--;//����--
	}
	else
		printf("û�и�Ԫ�أ�\n");
}

//ɾ��ȫ��ָ��Ԫ��
void RemoveAll(qSeqList seq, DataType data)
{
	int i = 0;
	int j = 0;
	assert(seq);
	for (i = 0; i < seq->sz; i++)
	{
		if (seq->data[i] == data)
		{
			//Ԫ���ƶ�
			for (j = i + 1; j < seq->sz; j++)
			{
				seq->data[j - 1] = seq->data[j];
			}
			seq->sz--;//����--
		}
	}
}

//����˳���Ĵ�С
int sizeSeqList(qSeqList seq)
{
	return seq->sz;
}


//�ж�˳����Ƿ�Ϊ��
int EmptySeqList(qSeqList seq)
{
	if (seq->sz == 0)
	{
		return -1;
	}
	return 0;
}

//����
static void swap(DataType *x, DataType *y)
{
	DataType tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
//ð������
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
				//����
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

//ѡ������
void SelectSort(qSeqList seq)
{
	int maxpos = 0;    //���ֵ�±�
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

//ѡ��������Ż�
void SelectSort_OP(qSeqList seq)
{
	int left = 0;    
	int right = seq->sz - 1;
	int maxpos = 0;   //���ֵ�±�
	int minpos = 0;   //��Сֵ�±�
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

//���ֲ���
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
		
		{
			return mid;
		}
	}
	return -1;
}