#include"SeqList.h"


//β������
testBack()
{
	//����һ���ṹ��seq
	SeqList seq;
	//��ʼ���ṹ��
	SeqListInit(&seq);
	//β�巨
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	//��ӡ
	PrintSeqList(&seq);
	//β��ɾ��
	PopBack(&seq);
	//��ӡ
	PrintSeqList(&seq);
}

//ͷ������
testFront()
{
	//����һ���ṹ��seq
	SeqList seq;
	//��ʼ���ṹ��
	SeqListInit(&seq);
	//ͷ������
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	//��ӡ
	PrintSeqList(&seq);
	//ͷ��ɾ��
	PopFront(&seq);
	//��ӡ
	PrintSeqList(&seq);
}

//����
void testFind()
{
	//����һ���ṹ��seq
	SeqList seq;
	int pos = 0;
	//��ʼ���ṹ��
	SeqListInit(&seq);
	//����
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	//����ָ��Ԫ��
	pos = Front(&seq, 1);
	if (pos == -1)
	{
		printf("�Ҳ�����\n");
		return;
	}
	else
	{
		printf("�±�Ϊ��%d\n", pos);
	}
}


//ָ��λ�ò���
void testInsert()
{
	//����һ���ṹ��seq
	SeqList seq;
	int pos = 0;
	//��ʼ���ṹ��
	SeqListInit(&seq);
	//����
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	//����ָ��Ԫ��
	pos = Front(&seq, 1);
	if (pos == -1)
	{
		printf("�Ҳ���ָ��λ�ã�\n");
		return;
	}
	else
	{
		//ָ��λ�ò���
		Insert(&seq, pos, 5);
		//��ӡ
		PrintSeqList(&seq);
	}
}

//ָ��λ��ɾ��
void testErase()
{
	//����һ���ṹ��seq
	SeqList seq;
	int pos = 0;
	//��ʼ���ṹ��
	SeqListInit(&seq);
	//����
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	//����ָ��Ԫ��
	pos = Front(&seq, 3);
	if (pos == -1)
	{
		printf("�Ҳ���ָ��λ�ã�\n");
		return;
	}
	else
	{
		//ָ��λ��ɾ��
		Erase(&seq, pos);
		//��ӡ
		PrintSeqList(&seq);
	}
}

//ɾ��ָ��Ԫ��
void testRemove()
{
	//����һ���ṹ��seq
	SeqList seq;
	//��ʼ���ṹ��
	SeqListInit(&seq);
	//����
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	Remove(&seq, 1);
	//��ӡ
	PrintSeqList(&seq);
}


//ɾ��ȫ��ָ��Ԫ��
void testRemoveall()
{
	//����һ���ṹ��seq
	SeqList seq;
	//��ʼ���ṹ��
	SeqListInit(&seq);
	//����
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	Removeall(&seq, 1);
	//��ӡ
	PrintSeqList(&seq);
}

//����˳���Ĵ�С
void testsize()
{
	//����һ���ṹ��seq
	SeqList seq;
	int l = 0;
	//��ʼ���ṹ��
	SeqListInit(&seq);
	//����
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	l = size(&seq);
	printf("size=%d \n", l);
}

//�ж�˳����Ƿ�Ϊ��
void testEmpty()
{
	//����һ���ṹ��seq
	SeqList seq;
	int s = 0;
	//��ʼ���ṹ��
	SeqListInit(&seq);
	//����
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	s = Empty(&seq);
	if (s == 1)
	{
		printf("�ṹ��Ϊ�գ�\n");
		return;
	}
	else
		printf("�ṹ�岻Ϊ�գ�\n");
}
//ð������
void testBubble()
{
	//����һ���ṹ��seq
	SeqList seq;
	//��ʼ���ṹ��
	SeqListInit(&seq);
	//����
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	//��ӡ
	PrintSeqList(&seq);
	Bubble(&seq);
	//��ӡ
	PrintSeqList(&seq);
}
//ѡ������
testSelectsort()
{
	//����һ���ṹ��seq
	SeqList seq;
	//��ʼ���ṹ��
	SeqListInit(&seq);
	//����
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	//��ӡ
	PrintSeqList(&seq);
	Selectsort(&seq);
	//��ӡ
	PrintSeqList(&seq);
}


//ѡ��������Ż�
void testSelectsortOp()
{
	//����һ���ṹ��seq
	SeqList seq;
	//��ʼ���ṹ��
	SeqListInit(&seq);
	//����
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	//��ӡ
	PrintSeqList(&seq);
	SelectsortOp(&seq);
	//��ӡ
	PrintSeqList(&seq);
}

//���ֲ���
void testBinarySearch()
{
	//����һ���ṹ��seq
	SeqList seq;
	int pos = 0;
	//��ʼ���ṹ��
	SeqListInit(&seq);
	//����
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	//��ӡ
	PrintSeqList(&seq);
	pos = BinarySearch(&seq,4);
	if (pos == -1)
	{
		printf("�Ҳ�����Ԫ�أ�\n");
		return;
	}
	else
	{
		printf("�±�Ϊ��%d\n", pos);
		return;
	}
}
//���ֲ��ҵĵݹ�
void testBinarySearch_R()
{
	//����һ���ṹ��seq
	SeqList seq;
	int pos = 0;
	//��ʼ���ṹ��
	SeqListInit(&seq);
	//����
	PushFront(&seq, 4);
	PushFront(&seq, 3);
	PushFront(&seq, 2);
	PushFront(&seq, 1);
	//��ӡ
	PrintSeqList(&seq);
	pos = BinarySearch_R(&seq, 0,seq.sz-1,2);
	if (pos ==-1 )
	{
		printf("�Ҳ�����Ԫ�أ�\n");
		return;
	}
	else
	{
		printf("�±�Ϊ��%d\n", pos);
		return;
	}
}
void test()
{
	
	//testBack();
	//testFront();
	//����ָ��Ԫ��
	//testFind();
	//ָ��λ�ò���
	//testInsert();
	//ָ��λ��ɾ��
	//testErase();
	//ɾ��ָ��Ԫ��
	//testRemove();
	//ɾ��ȫ��ָ��Ԫ��
	//testRemoveall();
	//����˳���Ĵ�С
	//testsize();
	//�ж�˳����Ƿ�Ϊ��
	//testEmpty();
	//ð������
	//testBubble();
	//ѡ������
	//testSelectsort();
	//ѡ�������Ż�
	//testSelectsortOp();
	//���ֲ���
	//testBinarySearch();
	//���ֲ��ҵĵݹ�
	testBinarySearch_R();
}
int main()
{
	test();
	system("pause");
	return 0;
}