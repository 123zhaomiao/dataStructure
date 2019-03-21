#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
void Print(int *arr,int size);
//�鲢
void Merge_sortNor(int *arr, int size, int*temp);
//�鲢
void Merge_sort(int *arr, int left, int right, int*temp);
//��������1
void quickSort(int *arr, int left, int right);
//��������1
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
	//Ҫ�����λ�õ�ǰһ��λ��
	int pos = 0;
	int k = 0;
	//ѭ����Ҫsize-1��
	for (i = 1; i < size; i++)
	{
		//�ӱ������Ԫ�ص�ǰһ��Ԫ�ؿ�ʼ�Ƚ�
		pos = i - 1;
		//��¼Ҫ�����Ԫ��
		k = array[i];
		//����������Ԫ�ر�ǰһ��Ԫ��С����Ԫ�����ƣ�Ȼ���ǰһ��Ԫ�رȽ�
		//����������Ԫ�ر�ǰһ��Ԫ�ش���ֱ�Ӳ���
		while (k < array[pos] && pos >= 0)
		{
			//˵����Ԫ��kҪ����pos��ǰ�棬����pos����
			array[pos + 1] = array[pos];
			pos--;
		}
		//��
		array[pos + 1] = k;
	}
}
//��ӡ����
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
  Hoare����
  ��������1
  ���������һ��Ԫ����Ϊ��׼key����������ָ��bengin��end
  bengin��ǰ�����ƶ������Ȼ�׼key���ֹͣ
  end�Ӻ���ǰ�ƶ������Ȼ�׼keyС��ֹͣ
  bengin��end����Ӧ�����ݽ���
  �ظ�ֱ��bengin==end
*/
int qs1(int *arr, int begin, int end)
{
	//�һ�׼
	/*
	����ÿ�ι滮ȡ�����ֵ����Сֵ�ĸ���
	���ǳ��ߣ���������ʹ����ɵ�֧�������Բ�������ȡ�з�
	������ȡ����ֵ�ĸ���
	*/
	int index = MiddleNumber(arr, begin, end);
	if (index != end)
	{
		swap(&arr[index], &arr[end]);
	}
	int key = arr[end];


	//��׼ֵ���±�
	int k = end;
	//����ָ�롢begin��0��ʼ��end��size-1��ʼ
	while (begin != end)
	{
		//begin����ƶ����ұȻ�׼k���Ԫ��,��begin���ܴ���end
		//���arr[begin]��keyС����begin++
		while (arr[begin] <= key && (begin < end))
		{
			begin++;
		}

		//end��ǰ�ƶ����ұȻ�׼keyС��Ԫ�أ���end����С��begin
		//���arr[end]��key����end--
		while (arr[end] >= key && (begin < end))
		{
			end--;
		}

		//���begin��end��Ӧ��ֵ����ȣ��򽻻�
		if (begin != end)
		{
			//����bengin��end����Ӧ��ֵ
			swap(&arr[begin], &arr[end]);
		}
	}
	//���begin������λ�þ��ǻ�׼��λ�����ý���
	if (begin != k)
	{
		//����׼ֵŲ����Ӧ��λ����
		swap(&arr[begin], &arr[k]);
	}
	return begin;
}
/*
  �ڿӷ�
  �Ƚ����һ��Ԫ�ر������Ϊ��һ����
  ��������ָ��begin��end
  begin����߿�ʼ�ұȹؼ��ִ��Ԫ�ؽ�����ӣ�begin����λ�ñ�Ϊ��
  end���ұ߿�ʼ�ұȹؼ���С��Ԫ�ؽ������,end����λ�ñ�Ϊ��
  ֪��begin==end����ǵĵ�һ��Ԫ�����
*/
int qs2(int *arr, int begin, int end)
{
	//�һ�׼
	/*
	����ÿ�ι滮ȡ�����ֵ����Сֵ�ĸ���
	���ǳ��ߣ���������ʹ����ɵ�֧�������Բ�������ȡ�з�
	������ȡ����ֵ�ĸ���
	*/
	int index = MiddleNumber(arr, begin, end);
	if (index != end)
	{
		swap(&arr[index], &arr[end]);
	}

	//��һ����
	int key = arr[end];
	int k = end;
	while (begin != end)
	{
		/*begin����߿�ʼ�ұȹؼ��ִ��Ԫ�ؽ������
		��begin����λ�ñ�Ϊ��*/
		while (arr[begin] <= key&&begin < end)
		{
			begin++;
		}
		if (begin != end)
		{
			arr[end] = arr[begin];
			end--;
		}
		/*end���ҿ�ʼ�ұȹؼ���С��Ԫ�ؽ�����begin��*/
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
	ǰ��ָ�뷨
	cur�ڴ��������е������
	perv=cur-1
	���arr[cur]<key,��prevһֱ����cur�ĺ���
	���arr[cur]>key,��prevֹͣ��cur��ǰ�ߣ�ֱ��arr[cur]<key
	cur��prev��Ӧ��Ԫ�ؽ������ظ���ֱ��cur�������������еĳ���
	prev��cur�м��ǱȻ�׼ֵ���Ԫ��
*/
int qs3(int *arr, int begin, int end)
{
	//�һ�׼
	/*
	����ÿ�ι滮ȡ�����ֵ����Сֵ�ĸ���
	���ǳ��ߣ���������ʹ����ɵ�֧�������Բ�������ȡ�з�
	������ȡ����ֵ�ĸ���
	*/
	int index = MiddleNumber(arr, begin, end);
	int cur = begin;
	int prev = begin - 1;
	if (index != end)
	{
		swap(&arr[index], &arr[end]);
	}
	int key = arr[end];
	//cur���ܳ������г���
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
	���ڿ��������ǵݹ���ã����ײ���ջ���
	���ǿ��������ŵ����Ԫ��Ҳ�ӽ���������ò�������
	*/
	if (right - left<2)
	{
		InsertSort(arr + left, right - left);
	}
	else                             
	{
		//Hoare
	   // position = qs1(arr, left, right - 1);
		//�ڿӷ�
		//position = qs2(arr, left, right - 1);
		//ǰ��ָ��
		position = qs3(arr, left, right - 1);
		//���������׼ֵ���
		quickSort(arr, 0, position);
		//���������׼ֵ�Ҳ�
		quickSort(arr, position + 1, right);
	}
}



//��������1
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
		//�ȿ��Ż�׼��࣬���Ƚ������±���ջ
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

//�鲢
void Merge_sortNor(int *arr,int size, int*temp)
{
	int left = 0;
	int right = size;
	int mid = left + ((right - left) >> 1);
	merge(arr, temp, left, mid, right);
	memcpy(arr, temp, 10 * sizeof(int));
}