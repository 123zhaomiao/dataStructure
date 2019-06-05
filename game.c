#include"game.h"
//初始化棋盘，全部为空格
void InitBoard(char arr[ROW][COL], int row, int col)
{
	memset(arr, ' ', row*col*sizeof(arr[0][0]));
}
//打印棋盘
void DisplayBoard(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", arr[i][0], arr[i][1], arr[i][2]);
		if (i != row - 1)
		{
			printf("---|---|---\n");
		}
	}
}
//玩家移动
void PalyerMove(char arr[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))   //坐标合法
		{
			if (arr[x-1][y-1] == ' ')
			{
				arr[x - 1][y - 1] = 'x';
				DisplayBoard(arr, ROW, COL);
				break;
				}
			else
				printf("该坐标被占用，请重新输入坐标！\n");
		}
		else
			printf("坐标无效，请重新输入！\n");
	}
	
}
//电脑移动
void ComputerMove(char arr[ROW][COL], int row, int col)
{
	    int x = 0;
	    int y = 0;
		printf("电脑走：\n");
		while (1)
		{
			x = rand() % 3;   //生成随机坐标
			y = rand() % 3;
			if (arr[x][y] == ' ')
			{
				arr[x][y] = '0';
				DisplayBoard(arr, ROW, COL);
				break;
			}
		}
}
// 判断棋盘是否满
int Full(char arr[ROW][COL], int row, int col)
{
	int  i, j;
	int count=0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] != ' ')
				count++;
		}
	}
	if (count == row*col)
		return 1;    //棋盘满
	else
		return 0;
}
//判断输赢
char Is_Win(char arr[ROW][COL], int row, int col)
{
	int i;
	int count = 0;
	//行相等
	for (i = 0; i < row; i++)
	{
		if ((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]))
			return arr[i][0];
	}
	// 列相等
	for (i = 0; i < col; i++)
	{
		if ((arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]))
			return arr[0][i];
	}
	//对角线相等
	if ((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]))
		return arr[0][0];
	if ((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]))
		return arr[0][2];
	// 棋盘满
	if (Full(arr, ROW, COL))
		return '1';
	return 0;
}