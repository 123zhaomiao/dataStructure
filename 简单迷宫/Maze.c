#include"Maze.h"

//初始化栈
void InitStack(stack *s)
{
	assert(s);
	s->top = 0;
	memset(s->data, 0, 20 * sizeof(position));
}
//入栈
void  PushStack(stack *s, position cur)
{
	assert(s);
	s->data[s->top] = cur;
	s->top++;
}
//栈顶元素
position TopStack(stack *s)
{
	assert(s);
	return s->data[s->top - 1];
}
//栈顶元素出栈
void PopStack(stack *s)
{
	assert(s);
	s->top--;
}
//判断是入口吗？
int IsEnter(int Maze[ROW][COL], position enter)
{
	//边界
	if (enter.x == 0 || enter.x == ROW - 1 || enter.y == 0 || enter.y == COL - 1)
	{
		return 1;
	}
	else
		return 0;
}
//是通路吗？
int IsPass(int Maze[ROW][COL], position next)
{
	//1.坐标有效
	if (next.x >= 0 && next.x < ROW && next.y >= 0 && next.y < COL )
	{
		//2.是通路
		if (1 == Maze[next.x][next.y])
		{
			return 1;
		}
	}
	return 0;
}
//是出口吗？
int IsExit(int Maze[ROW][COL], position enter, position cur)
{
	if ((cur.x == 0 || cur.x == ROW - 1 || cur.y == 0 || cur.y == COL - 1) && (cur.x != enter.x || cur.y != enter.y))
	{
		return 1;
	}
	return 0;
}

//走迷宫
void PassMaze(int Maze[ROW][COL], position enter, stack* s)
{
	position cur;
	position next; 
	if (IsEnter(Maze, enter))
	{
		cur = enter;
		//入口入栈
		PushStack(s, cur);
		//为防止重复走，将走过的路标记
		Maze[cur.x][cur.y] = 2;
		//如果不是出口，继续。。。。
		while (!IsExit(Maze, enter,TopStack(s)))
		{
			//cur为当前的栈顶元素
			cur = TopStack(s);
			//上通，从上走，标记
			next = cur;
			next.x = cur.x - 1;
			if (IsPass(Maze, next))
			{
				PushStack(s, next);
				Maze[next.x][next.y] = 2;
				continue;
			}
			//左通，从左走，标记
			next = cur;
			next.y = cur.y - 1;
			if (IsPass(Maze, cur))
			{
				PushStack(s, next);
				Maze[next.x][next.y] = 2;
				continue;
			}
			//右通，从右走，标记
			next = cur;
			next.y = cur.y + 1;
			if (IsPass(Maze, next))
			{
				PushStack(s, next);
				Maze[cur.x][next.y] = 2;
				continue;
			}
			//下通，从下走，标记
			next = cur;
			next.x = cur.x + 1;
			if (IsPass(Maze, next))
			{
				PushStack(s, next);
				Maze[next.x][next.y] = 2;
				continue;
			}
			//若上左右下均不是通路，证明该步走错，回退，且标记
			//栈顶元素出栈
			PopStack(s);
			Maze[cur.x][cur.y] = 3;
		}
		}
}
//打印迷宫
void print(int Maze[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%d ", Maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//打印迷宫路径
void printStack(stack *s)
{
	int i = 0;
	printf("迷宫路径为：\n");
	for (i = 0; i < s->top; i++)
	{
		printf("(%d,%d)  ", s->data[i].x,s->data[i].y);
	}
	printf("\n");
}
