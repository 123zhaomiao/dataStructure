#include"HashBucket.h"

void Test()
{
	HashBucket hashbucket;
	//��ʼ��
	InitHashBucket(&hashbucket);
	//����
	InsertHashBucket(&hashbucket, 5);
	InsertHashBucket(&hashbucket, 12);
	InsertHashBucket(&hashbucket, 2);
	InsertHashBucket(&hashbucket, 6);
	InsertHashBucket(&hashbucket, 22);
	InsertHashBucket(&hashbucket, 16);
	InsertHashBucket(&hashbucket, 3);
	//ɾ��
	DeleteHashBucket(&hashbucket, 2);
	//����
	if (FindHashBucket(&hashbucket, 22))
	{
		printf("��Ԫ�ش���!\n");
	}
	else
	{
		printf("�Ҳ�����Ԫ��!\n");
	}
	printf("Size=%d\n", SizeHashBucket(&hashbucket));
}
int main()
{
	Test();
	system("pause");
	return 0;
}