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
//保存
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
	{	//使用循环，将人员信息一个一个装进文件中去，直到装完，cur指向NULL
		fwrite(cur, sizeof(struct S), 1, fp);
		cur = cur->next;
	}
	//3.关闭文件
	fclose(fp);	//注意：fopen必须和fclose同时使用
}
//展示联系人
void show(struct S *head)
{
	struct S*cur = head;
	while (cur != NULL)
	{
		printf("%s %s %d %s\n", cur->name, cur->num, cur->age, cur->sex);
		cur = cur->next;
	}
}
//清空联系人
void qingkong(struct S **head)
{
	struct S*cur = *head;
	while (cur != NULL)
	{
	   *head = cur->next;
		cur = cur->next;
	}
	
}	
//修改联系人
void xiugai(struct S**head)
{
	char arr[20];
	struct S*cur = *head;
	printf("请输入你要修改的联系人姓名：");
	scanf("%s", arr);
	while (cur != NULL)
	{
		if (strcmp(cur->name, arr) == 0)
		{
			printf("请输入修改后的信息：\n");
			printf("姓名：>");
			scanf("%s", cur->name);
			printf("电话：>");
			scanf("%s", cur->num);
			printf("年龄：>");
			scanf("%d", &cur->age);
			printf("性别：>");
			scanf("%s", cur->sex);
			show(*head);
			return ;

		}
		cur = cur->next;
	}
	printf("没有此人！\n");
}
//排序
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
//查找联系人
void find(struct S *head)
{
	char arr[20];
	struct S*cur = head;
	printf("请输入你要查找的联系人姓名：");
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
		printf("没有找到！\n");
	}
}
//删除联系人
void erase(struct S**head)
{
	struct S *cur = *head;
	struct S *pre = NULL;
	char arr[32] = { 0 };
	printf("请输入你要删除的联系人姓名：");
	scanf("%s", arr);
	while (cur!= NULL)
	{
		if (strcmp(cur->name, arr) == 0)
		{
			if (cur == *head)    //如果被删除的元素是头指针
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
//添加联系人
void insert(struct S **head)
{
	//创建一个链表
	struct S *p=(struct S*)malloc(sizeof(struct S));
	printf("姓名：>");
	scanf("%s", p->name);
	printf("电话：>");
	scanf("%s", p->num);
	printf("年龄：>");
	scanf("%d", &p->age);
	printf("性别：>");
	scanf("%s", p->sex);
	p->next = NULL;    //最后一 个元素指向下一个结构体
	if (*head == NULL)  //插入首元素
	{
		*head = p;
	}
	else               // 插入其他元素
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
	printf("*1   添加联系人*******2   删除联系人****\n");
	printf("*3   查找联系人*******4   联系人排序****\n");
	printf("*5   修改联系人*******6   保存联系人****\n");
	printf("*7   ************清空联系人*************\n");
	printf("****************************************\n");
}
int main()
{
	int input;
	struct S *head = NULL; //定义一个结构体变量person
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
		case 0:printf("退出\n"); break;
		default:printf("输入错误，请重新输入\n"); break;
		}
	} while (input);
	system("pause");
	return 0;
}