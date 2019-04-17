#include"SeqList.h"
SeqList seq;    //����һ��ȫ�ֱ���seq

//����β�������β��ɾ��
void TestBack()
{
	//��ʼ��
	InitSeqList(&seq);
	//β������
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 3);
	//��ӡ
	PrintSeqList(&seq);
	//β��ɾ��
	PopBackSeqList(&seq);
	PopBackSeqList(&seq);
	//��ӡ
	PrintSeqList(&seq);
}


//����ͷ�������β��ɾ��
void TestFront()
{

	//��ʼ��
	InitSeqList(&seq);
	//ͷ������
	PushFrontSeqList(&seq, 3);
	PushFrontSeqList(&seq, 2);
	PushFrontSeqList(&seq, 1);
	//��ӡ
	PrintSeqList(&seq);
	//ͷ��ɾ��
	PopFrontSeqList(&seq);
	PopFrontSeqList(&seq);
	//��ӡ
	PrintSeqList(&seq);
}


//���Բ���ָ��Ԫ��
void TestFind()
{
	int pos = 0;
	//��ʼ��
	InitSeqList(&seq);
	//β������
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 3);
	//��ӡ
	PrintSeqList(&seq);
	//����ָ��Ԫ��
	pos = FindSeqList(&seq, 2);
	if (pos == -1)
	{
		printf("û���ҵ���\n");
		return;
	}
	else
	{
		printf("�±��ǣ�%d\n", pos);
		//ָ��λ�ò���
		Insert(&seq, pos, 4);
		//��ӡ
		PrintSeqList(&seq);
		//ָ��λ��ɾ��
		Erase(&seq, pos);
		//��ӡ
		PrintSeqList(&seq);
	}
	
}


//����ɾ��ָ��Ԫ��
void TestRemove()
{
	//��ʼ��
	InitSeqList(&seq);
	//β������
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 3);
	//��ӡ
	PrintSeqList(&seq);
	//ɾ��ָ��Ԫ��
	Remove(&seq, 3);
	//��ӡ
	PrintSeqList(&seq);
}

//����ɾ�����е�ָ��Ԫ��
void TestRemoveAll()
{
	//��ʼ��
	InitSeqList(&seq);
	//β������
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 3);
	//��ӡ
	PrintSeqList(&seq);
	//ɾ��ָ��Ԫ��
	RemoveAll(&seq, 3);
	//��ӡ
	PrintSeqList(&seq);
}

//����˳���Ĵ�С
void TestSize()
{
	int sz = 0;
	//��ʼ��
	InitSeqList(&seq);
	//β������
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 3);
	//��ӡ
	PrintSeqList(&seq);
	sz = sizeSeqList(&seq);
	printf("sz=%d\n", sz);
}

//�ж�˳����Ƿ�Ϊ��
void TestEmpty()
{
	int sz = 0;
	//��ʼ��
	InitSeqList(&seq);
	//β������
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 3);
	//��ӡ
	PrintSeqList(&seq);
	sz = EmptySeqList(&seq);
	if (sz == -1)
	{
		printf("˳���Ϊ�գ�\n");
	}
	else
	{
		printf("˳���Ϊ�գ�\n");
	}
}

//����ð������
void TestBubble()
{
	//��ʼ��
	InitSeqList(&seq);
	//β������
	PushBackSeqList(&seq, 6);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 4);
	//��ӡ
	PrintSeqList(&seq);
	Bubblesort(&seq);
	//��ӡ
	PrintSeqList(&seq);
}

//����ѡ������
void TestSelectSort()
{
	//��ʼ��
	InitSeqList(&seq);
	//β������
	PushBackSeqList(&seq, 6);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 4);
	PushBackSeqList(&seq, 1);
	//��ӡ
	PrintSeqList(&seq);
	SelectSort(&seq);
	//��ӡ
	PrintSeqList(&seq);
}

//����ѡ��������Ż�
void  TestSelectSort_OP()
{
	//��ʼ��
	InitSeqList(&seq);
	//β������
	PushBackSeqList(&seq, 6);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 4);
	PushBackSeqList(&seq, 1);
	//��ӡ
	PrintSeqList(&seq);
	SelectSort_OP(&seq);
	//��ӡ
	PrintSeqList(&seq);
}

//���ֲ���
void TestBinarySearch()
{
	int pos = 0;
	//��ʼ��
	InitSeqList(&seq);
	//β������
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 3);
	//��ӡ
	PrintSeqList(&seq);
	pos = BinarySearch(&seq, 1
		);
	if (pos == -1)
	{
		printf("û���ҵ���\n");
		return;
	}
	else
	{
		printf("�±�Ϊ��%d\n", pos);
	}
}

//���ֲ��ҵݹ�
void TestBinarySearch_R()
{
	int pos = 0;
	//��ʼ��
	InitSeqList(&seq);
	//β������
	PushBackSeqList(&seq, 1);
	PushBackSeqList(&seq, 2);
	PushBackSeqList(&seq, 3);
	PushBackSeqList(&seq, 4);
	//��ӡ
	PrintSeqList(&seq);
	pos = BinarySearch_R(&seq,0,seq.sz-1, 1);
	if (pos == -1)
	{
		printf("û���ҵ���\n");
		return;
	}
	else
	{
		printf("�±�Ϊ��%d\n", pos);
	}
}
void test()
{
	//����β�������β��ɾ��
	TestBack();
	//����ͷ�������β��ɾ��
	//TestFront();
	//���Բ���ָ��Ԫ���Լ�ָ��λ�ò����ָ��λ��ɾ��
	//TestFind();
	//����ɾ��ָ��Ԫ��
	//TestRemove();
	//����ɾ�����е�ָ��Ԫ��
	//TestRemoveAll();
	//����˳���Ĵ�С
	//TestSize();
	//�ж�˳����Ƿ�Ϊ��
	//TestEmpty();
	//����ð������
	//TestBubble();
	//����ѡ������
	//TestSelectSort();
	//����ѡ��������Ż�
	//TestSelectSort_OP();
	//���ֲ���
	//TestBinarySearch();
	//���ֲ��ҵݹ�
	//TestBinarySearch_R();
}
int main()
{
	test();
	system("pause");
	return 0;
}