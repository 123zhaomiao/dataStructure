#include"HashTable.h"


void Test()
{
	HashTable hashtable;
	//��ʼ����ϣ��
	InitHashTable(&hashtable);
	//�����ϣ��
	InsertHashTable(&hashtable, "����");
	InsertHashTable(&hashtable, "����");
	InsertHashTable(&hashtable, "���");
	InsertHashTable(&hashtable, "�ٺ�");
	InsertHashTable(&hashtable, "������");
	//ɾ����ϣ��
	DeleteHashTable(&hashtable, "����");


	InsertHashTable(&hashtable, "����");
	InsertHashTable(&hashtable, "abc");
	InsertHashTable(&hashtable, "def");
	InsertHashTable(&hashtable, "acd");

	//ɾ����ϣ��
	DeleteHashTable(&hashtable, "def");


	//����
	if (FindHashTable(&hashtable, "abc") != -1)
	{
		printf("abc �Ĺ�ϣ��ַΪ��%d\n", FindHashTable(&hashtable, "abc"));
	}
	else
	{
		printf("û���ҵ�!\n");
	}
	printf("��ϣ��Ԫ�ظ�����%d\n", SizeHashTable(&hashtable));

	//�п�
	if (EmptyHashTable(&hashtable))
	{
		printf("��ϣ��Ϊ��!\n");
	}
	else
	{
		printf("��ϣ��Ϊ��!\n");
	}
	print(&hashtable);
	//���ٹ�ϣ��
	DestroyHashTable(&hashtable);

}
int main()
{
	Test();
	system("pause");
	return 0;
}