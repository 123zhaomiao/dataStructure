#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define N 10
char arr[N][N];
struct Pos
{
	int xpos; //列偏移量
	int ypos; //行偏移量
}p[3] = { { -1, -1 }, { 0 ,-1 }, {1,-1 } };
//初始化数组
void Init()
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		int j = 0;
		for (j = 0; j < N; j++)
		{
			arr[i][j] = ' ';
			//边框设置为#
			arr[0][j] = '#';       
			arr[N - 1][j] = '#';
			arr[i][0] = '#';
			arr[i][N - 1] = '#';
		}
	}
}
//展示数组
void Show()
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		int j = 0;
		for (j = 0; j < N; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
//检查是否可以摆放
int check_put( int row, int col)
{
	int i;
	int ret = 1;
	int nr = row;
	int nc = col;
	for (i = 0; ret&&i < 3; i++)   //需要判断两个对角线以及上方是否有皇后
	{
		nr = row;
		nc = col;
		while ((arr[nr][nc] != '#')&&ret) //循环到边缘截止
		{
			if (arr[nr][nc] == ' ')      //判断这个位置是否有皇后
			{
				nr = nr + p[i].ypos;     
				nc = nc + p[i].xpos;
			}
			else
				ret = 0;
		}	
	}
	return ret;
}
//摆皇后
void Find(int row)
{
	int j = 0;
	static int count = 0;   //用于计算摆皇后有多少种情况
	if (row > N - 2)        //摆完1-8行后打印
	{
		Show();
		count++;
		printf("count=%d\n", count);
	}
	else
	{
		for (j = 1; j < N - 1; j++)
		{
			if (check_put(row, j))  //判断是否可以放皇后，如果可以返回1；
			{
				arr[row][j] = '*';  //将此位置放上皇后
				Find( row + 1);     //递归摆下一行
				arr[row][j] = ' ';
			}
		}
	}
}
int main()
{
	//初始化数组  
	Init();
	//摆皇后
	Find(1);
	system("pause");
	return 0;
}