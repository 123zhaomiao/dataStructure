#include"Maze.h"

//栈初始化
void StackInit(stack *s)
{
	assert(s);
	s->top = 0;
	memset(s->data, 0, 20 * sizeof(position));
}

//入栈
void Pushstack(stack* s, position enter)
{
	assert(s);
	s->data[s->top++] = enter;
}

//出栈
void PopStack(stack* s)
{
	assert(s);
	s->top--;
}

//判断入口是否有效
int IsEnter(int Maze[ROW][COL], position enter)
{
	if (enter.x == 0 || enter.x == ROW - 1 || enter.y == 0 || enter.y == COL - 1)
	{
		//入口即边界
		return 1;
	}
	else
		return 0;
}


//判断是否是通路
int IsPass(int Maze[ROW][COL], position enter, position next)
{
	//1. 下一步有效
	if (next.x >= 0 && next.x < ROW&&next.y >= 0 && next.y < COL)
	{
		//2.若为1，或者next比enter大即为通路
		if (Maze[next.x][next.y] == 1 || Maze[next.x][next.y] > Maze[enter.x][enter.y])
		{
			return 1;
		}
	}
	return 0;
}

//判断是否是出口
int IsExit(int Maze[ROW][COL], position Enter, position cur)
{
	//是边界，但不是入口
	if ((cur.x == 0 || cur.x == ROW - 1 || cur.y == 0 || cur.y == COL - 1)&&(cur.x!=Enter.x||cur.y!=Enter.y) )
	{
		return 1;
	}
	return 0;
}

//判断是否是最短路径
int IsShortPath(stack *path, stack *shortpath)
{
	//最短路径栈为空或者新路径比之前路径短
	if (shortpath->top == 0||path->top < shortpath->top)
	{
		return 1;
	}
	return 0;
}

//走迷宫  Enter为迷宫进口  enter为递归的迷宫进口，path为路径，shortpath为最短路径
void  PassMaze(int Maze[ROW][COL], position Enter, position enter, stack * path, stack *shortpath)
{
	int i = 0;
	position next;
	//判断入口是否有效(只当Maze[x][y]==1时判断一次)
	if (Maze[enter.x][enter.y] == 1&&IsEnter(Maze, enter))
	{
		//迷宫入口入栈
		Pushstack(path,enter);
		Maze[enter.x][enter.y] = 2;
	}

	//判断是否是出口
	if (IsExit(Maze,Enter,enter))
	{
		//判断是否是最短路径
		if (IsShortPath(path, shortpath))
		{
			for (i = 0; i < path->top; i++)
			{
				shortpath->data[i] = path->data[i];
			}
			shortpath->top = path->top;
		}
	}

	//上
	next = enter;
	next.x = enter.x - 1;
	if (IsPass(Maze, enter, next))
	{
		Pushstack(path, next);
		Maze[next.x][next.y] = Maze[enter.x][enter.y] + 1;
		//将下一步当作递归的入口
	    PassMaze(Maze, Enter, next, path, shortpath);
	}

	//左
	next = enter;
	next.y = enter.y - 1;
	if (IsPass(Maze, enter, next))
	{
		Pushstack(path, next);
		Maze[next.x][next.y] = Maze[enter.x][enter.y] + 1;
		PassMaze(Maze, Enter, next, path, shortpath);
	}
	//右
	next = enter;
	next.y = enter.y + 1;
	if (IsPass(Maze, enter, next))
	{
		Pushstack(path, next);
		Maze[next.x][next.y] = Maze[enter.x][enter.y] + 1;
		PassMaze(Maze, Enter, next, path, shortpath);
	}
	//下
	next = enter;
	next.x = enter.x + 1;
	if (IsPass(Maze, enter, next))
	{
		Pushstack(path, next);
		Maze[next.x][next.y] = Maze[enter.x][enter.y] + 1;
		PassMaze(Maze, Enter, next, path, shortpath);
	}
    //上左右下无通路，该步走错，回退
	PopStack(path);
}


//打印迷宫最短路径
void Print(stack *shortpath)
{
	int i = 0;
	printf("最短路径：\n");
	for (i = 0; i < shortpath->top; i++)
	{
		printf("(%d,%d) ", shortpath->data[i].x, shortpath->data[i].y);
	}
	printf("\n");
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
}
