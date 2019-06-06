#include"game.h"
//初始化函数
void InitBoard(char arr[ROWS][COLS], int rows, int cols,char sz)
{
	memset(arr, sz, rows*cols*sizeof(arr[0][0]));
}
//放雷
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int i=0;                          //雷数
	while (i < Easy_Count)
	{
		int x = rand() % row + 1;     //rand()%row产生的是0~row-1之间的数
		int y = rand() % col + 1;     
		if (mine[x][y] == '0')        //防止重复放雷
		{
			mine[x][y] = '1';
			i++;
		}
	}
}
//打印
void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i, j;
	for (i = 0; i <= row; i++)           //打印行标---------0~9，便于用户
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= col; i++)
	{
		printf("%d ", i);               //打印列标---------1~9
		for (j = 1; j <= col; j++)      //循环打印元素
		{
			printf("%c ", arr[i][j]);   
		}
		printf("\n");
	}
}
//计算雷的数量
static int CountMine(char mine[ROWS][COLS], int x, int y)
{
	int count;//坐标周围7个地方   字符1-字符0=数字1；
	count = (mine[x][y - 1] + mine[x][y + 1] + mine[x - 1][y] + 
		mine[x - 1][y - 1] + mine[x - 1][y + 1] + mine[x + 1][y] + mine[x+1][y - 1] + mine[x + 1][y + 1]) - 8 * '0';
	return count;
}
//展开函数
static void open_board(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i, j;
	if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL))  //坐标合法
	{
		if (CountMine(mine, x, y) == 0)                //坐标周围没有雷
		{
			show[x][y] = '0';                         
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if (show[i][j] == '*')             //如果这个地方没有展开，则递归展开
						open_board(mine, show, i, j);
				}
			}
		}
		else
			show[x][y] = CountMine(mine, x, y) + '0';
	}
}
//扫雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	int i = 1;              
	int t;
	int m;
	while (1)
	{
		printf("请输入坐标：>");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))      //坐标合法
		{
			if (mine[x][y] == '1')
			{
				if (i > 0)                          //第一次是雷，挪走雷，不被炸死
				{ 
					    int count = 0;
						mine[x][y] = '0';           
						t = rand() % row + 1;       //雷-------x坐标  
						m = rand() % col + 1;       //雷-------y坐标 
						if (mine[t][m] == '0')
						{
							mine[t][m] = '1';       //重新给雷找位置   
						}  
						open_board(mine, show, x, y);//展开
						DisplayBoard(show, ROW, COL);//展示
						i--;                          //i变为0，以后要是遇到雷，不执行这一步，直接炸死
				}
				else
				{
					printf("很遗憾，你被炸死了！\n");
					break;
				}
			}
			else if (mine[x][y] == '0'&&show[x][y] == '*')   //统计周围雷的个数，防止一个位置count++两次
			{
				
				win++;
				open_board(mine, show, x, y);   
				DisplayBoard(show, ROW, COL);
				if (win == row*col - Easy_Count)
				{
					printf("恭喜你，闯关成功!\n");
					break;
				}
				i--;
			}
			else
				printf("坐标重复输入，请重新输入：\n");
		}
		else
		{
			printf("输入的坐标无效，请重新输入！\n");
		}
	}
}
