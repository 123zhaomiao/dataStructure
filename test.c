#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

mon[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
//�ж�����
int isleap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	    return 1;
	else
		return 0;
}
//��ݵĵ�һ��
int first_day_of_year(int year)
{
	int base_year = 2000;  //����һ����׼��2000��
	int first_day = 6;     //��׼�죺2000��1��1��������6
	int i = 2000;
	int total = 0;          //�����ܺ�
	for (i = base_year; i < year; i++)
	{
		total = total + 365 + isleap(i);  //isleap���������ж�����Ƿ������꣬����Ƿ���1�����Ƿ���0
	}
	return (total + first_day) % 7;
}
//�·ݵ�һ��
int first_day_of_month(int year, int month, int first_year)
{
	int total = 0;  //������
	int i = 0;
	for(i = 1; i < month; i++)
	{
		total = total + mon[isleap(year)][i];
	}
	return (total + first_year) % 7;
}
//չʾ����
void show(int year,int  month, int first_month)
{
	int i = 0;
	printf("һ   ��   ��   ��   ��   ��  ��\n");
	for (i = 0; i < first_month-1; i++)
	{
		printf("     ");     //�·ݵ�һ���Ǵ�first_month��ʼ�ģ��������ȴ�ӡfirst_month-1���ո�
	}
	for (i = 1; i <= mon[isleap(year)][month]; i++)
	{
		printf("%-5d", i);
		if ((first_month-1+i) % 7 ==0) //���������+�ո�����%7==0������
			printf("\n");
	}
	printf("\n");
}
int main()
{
	int year, month;
	printf("��/��:");  //���������ӡ�����
	scanf("%d/%d", &year, &month);
	int first_year = first_day_of_year(year);//��ݵ�һ��
	int first_month = first_day_of_month(year, month, first_year);//�·ݵ�һ��
	show(year, month, first_month);
	system("pause");
	return 0;
}