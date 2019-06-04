#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct S
{
	char name[20];
	char num[12];
	int age;
	char sex[2];
	struct S *next;
};
//����
void save(struct S ** head)
{
	FILE *fp = fopen("txl.txt", "w");
	struct S *cur = *head;
	if (fp == NULL)
	{
		perror("open file txl.db error");
		exit(1);
	}
	while (cur != NULL)
	{	//ʹ��ѭ��������Ա��Ϣһ��һ��װ���ļ���ȥ��ֱ��װ�꣬curָ��NULL
		fwrite(cur, sizeof(struct S), 1, fp);
		cur = cur->next;
	}
	//3.�ر��ļ�
	fclose(fp);	//ע�⣺fopen�����fcloseͬʱʹ��
}
//չʾ��ϵ��
void show(struct S *head)
{
	struct S*cur = head;
	while (cur != NULL)
	{
		printf("%s %s %d %s\n", cur->name, cur->num, cur->age, cur->sex);
		cur = cur->next;
	}
}
//�����ϵ��
void qingkong(struct S **head)
{
	struct S*cur = *head;
	while (cur != NULL)
	{
	   *head = cur->next;
		cur = cur->next;
	}
	
}	
//�޸���ϵ��
void xiugai(struct S**head)
{
	char arr[20];
	struct S*cur = *head;
	printf("��������Ҫ�޸ĵ���ϵ��������");
	scanf("%s", arr);
	while (cur != NULL)
	{
		if (strcmp(cur->name, arr) == 0)
		{
			printf("�������޸ĺ����Ϣ��\n");
			printf("������>");
			scanf("%s", cur->name);
			printf("�绰��>");
			scanf("%s", cur->num);
			printf("���䣺>");
			scanf("%d", &cur->age);
			printf("�Ա�>");
			scanf("%s", cur->sex);
			show(*head);
			return ;

		}
		cur = cur->next;
	}
	printf("û�д��ˣ�\n");
}
//����
void sort(struct S *head)
{
	struct S*pre = head;
	struct S*cur = head;
	for (pre = head; pre != NULL; pre = pre->next)
	{
		for (cur = pre; cur != NULL; cur = cur->next)
		{
			if ((*pre).age > (*cur).age)
			{
				struct S tmp;
				strcmp(tmp.name, pre->name);
				strcmp(tmp.num, pre->num);
				tmp.age = pre->age;
				strcmp(tmp.sex, pre->sex);

				strcmp( pre->name,cur->name);
				strcmp( pre->num,cur->name);
			    pre->age=cur->age;
				strcmp( pre->sex,cur->sex);

				strcmp(cur->name,tmp.name);
				strcmp(cur->num,tmp.num);
				cur->age = tmp.age;
				strcmp(cur->sex,tmp.sex);
			}
		}
	}
	show(head);
}
//������ϵ��
void find(struct S *head)
{
	char arr[20];
	struct S*cur = head;
	printf("��������Ҫ���ҵ���ϵ��������");
	scanf("%s", arr);
	while (cur != NULL)
	{
		if (strcmp(cur->name, arr) == 0)
		{
		   printf("%s %s %d %s\n", cur->name, cur->num, cur->age, cur->sex);
		   break;
		}
		cur = cur->next;
	}
	if (cur == NULL)
	{
		printf("û���ҵ���\n");
	}
}
//ɾ����ϵ��
void erase(struct S**head)
{
	struct S *cur = *head;
	struct S *pre = NULL;
	char arr[32] = { 0 };
	printf("��������Ҫɾ������ϵ��������");
	scanf("%s", arr);
	while (cur!= NULL)
	{
		if (strcmp(cur->name, arr) == 0)
		{
			if (cur == *head)    //�����ɾ����Ԫ����ͷָ��
			{
				*head = cur->next;
			}
			else
			{
				pre->next = cur->next;
			}
		}
		else
			pre = cur;
		    cur = cur->next;
	}
	show(*head);
}
//�����ϵ��
void insert(struct S **head)
{
	//����һ������
	struct S *p=(struct S*)malloc(sizeof(struct S));
	printf("������>");
	scanf("%s", p->name);
	printf("�绰��>");
	scanf("%s", p->num);
	printf("���䣺>");
	scanf("%d", &p->age);
	printf("�Ա�>");
	scanf("%s", p->sex);
	p->next = NULL;    //���һ ��Ԫ��ָ����һ���ṹ��
	if (*head == NULL)  //������Ԫ��
	{
		*head = p;
	}
	else               // ��������Ԫ��
	{
		struct S *cur = *head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = p;
	}
	show(*head);
}
void menu()
{
	printf("****************************************\n");
	printf("*1   �����ϵ��*******2   ɾ����ϵ��****\n");
	printf("*3   ������ϵ��*******4   ��ϵ������****\n");
	printf("*5   �޸���ϵ��*******6   ������ϵ��****\n");
	printf("*7   ************�����ϵ��*************\n");
	printf("****************************************\n");
}
int main()
{
	int input;
	struct S *head = NULL; //����һ���ṹ�����person
	do
	{
		menu();
		printf("Enter your choice:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:insert(&head); break;
		case 2:erase(&head); break;
		case 3:find(head); break;
		case 4:sort(head); break;
		case 5:xiugai(&head); break;
		case 6:save(&head); break;
		case 7:qingkong(&head);break;
		case 0:printf("�˳�\n"); break;
		default:printf("�����������������\n"); break;
		}
	} while (input);
	system("pause");
	return 0;
}