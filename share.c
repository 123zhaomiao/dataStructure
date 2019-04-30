#include"share.h"


//����ջ��ʼ��
void InitShared(sharedstack *s)
{
	assert(s);
	s->capacity = 5;
	s->top1 = 0;
	s->top2 = s->capacity - 1;
	s->data = (DataType *)malloc(s->capacity*sizeof(DataType));
}
//����
void ExpandCapacity(sharedstack *s)
{
	DataType *Newnode = NULL;
	int newcapacity = 0;
	int i = 0;
	if (s->top1 <= s->top2)
	{
		//�������ݣ�ֱ�ӷ���
		return ;
	}
	newcapacity = s->capacity * 2;
	Newnode = (DataType*)malloc(newcapacity*sizeof(DataType));
	if (Newnode == NULL)
	{
		printf("�¿ռ俪��ʧ�ܣ�\n");
		return ;
	}
	//����ջ1Ԫ��
	for (i = 0; i < s->top1; i++)
	{
		Newnode[i] = s->data[i];
	}
	//����ջ2Ԫ��
	for (i = s->capacity - 1; i>s->top2; i--)
	{
		Newnode[i+s->capacity]=s->data[i];
	}
	//�ı�ջ2��ջ��������
	s->top2 = s->top2 + s->capacity;
	s->capacity = newcapacity;

	//�ͷ�֮ǰ�Ŀռ�
	free(s->data);
	s->data = Newnode;
}
//��ջ
void PushSharedStack(sharedstack *s, DataType d, int which)
{
	assert(s);
	ExpandCapacity(s);
	if (which == 1)
	{
		s->data[s->top1++] = d;
	}
	else
	{
		s->data[s->top2--] = d;
	}
}
//��ջ
void PopSharedStack(sharedstack *s, int which)
{
	assert(s);
	if (which == 1)
	{
		if (s->top1 == 0)
		{
			printf("ջ1�գ�\n");
			return;
		}
		else
		{
			s->top1--;
		}
	}
	else
	{
		if (s->top2 == s->capacity - 1)
		{
			printf("ջ2�գ�\n");
			return;
		}
		else
		{
			s->top2++;
		}
	}
}
//ջ��Ԫ��
DataType SharedStackTop(sharedstack *s, int which)
{
	assert(s);
	if (which == 1)
	{
		if (s->top1 == 0)
		{
			printf("ջ1�գ�\n");
			return -1;
		}
		else
			return s->data[s->top1 - 1];
	}
	else
	{
		if (s->top2 == s->capacity - 1)
		{
			printf("ջ2�գ�\n");
			return -1;
		}
		else
			return s->data[s->top2 + 1];
	}
}
//ջ����
int SharedStackSize(sharedstack *s, int which)
{
	assert(s);
	if (which == 1)
	{
		return s->top1;
	}
	else
		return s->capacity - s->top2 - 1;
}