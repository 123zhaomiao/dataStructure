#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

mon[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
//判断闰年
int isleap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	    return 1;
	else
		return 0;
}
//年份的第一天
int first_day_of_year(int year)
{
	int base_year = 2000;  //定义一个基准年2000年
	int first_day = 6;     //基准天：2000年1月1号是星期6
	int i = 2000;
	int total = 0;          //天数总和
	for (i = base_year; i < year; i++)
	{
		total = total + 365 + isleap(i);  //isleap函数用于判断年份是否是闰年，如果是返回1，不是返回0
	}
	return (total + first_day) % 7;
}
//月份第一天
int first_day_of_month(int year, int month, int first_year)
{
	int total = 0;  //天数和
	int i = 0;
	for(i = 1; i < month; i++)
	{
		total = total + mon[isleap(year)][i];
	}
	return (total + first_year) % 7;
}
//展示日历
void show(int year,int  month, int first_month)
{
	int i = 0;
	printf("一   二   三   四   五   六  日\n");
	for (i = 0; i < first_month-1; i++)
	{
		printf("     ");     //月份第一天是从first_month开始的，所以首先打印first_month-1个空格
	}
	for (i = 1; i <= mon[isleap(year)][month]; i++)
	{
		printf("%-5d", i);
		if ((first_month-1+i) % 7 ==0) //如果（数字+空格数）%7==0，则换行
			printf("\n");
	}
	printf("\n");
}
int main()
{
	int year, month;
	printf("年/月:");  //输入你想打印的年份
	scanf("%d/%d", &year, &month);
	int first_year = first_day_of_year(year);//年份第一天
	int first_month = first_day_of_month(year, month, first_year);//月份第一天
	show(year, month, first_month);
	system("pause");
	return 0;
}
