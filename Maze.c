#include"Maze.h"

//ջ��ʼ��
void StackInit(stack *s)
{
	assert(s);
	s->top = 0;
	memset(s->data, 0, 20 * sizeof(position));
}

//��ջ
void Pushstack(stack* s, position enter)
{
	assert(s);
	s->data[s->top++] = enter;
}

//��ջ
void PopStack(stack* s)
{
	assert(s);
	s->top--;
}

//�ж�����Ƿ���Ч
int IsEnter(int Maze[ROW][COL], position enter)
{
	if (enter.x == 0 || enter.x == ROW - 1 || enter.y == 0 || enter.y == COL - 1)
	{
		//��ڼ��߽�
		return 1;
	}
	else
		return 0;
}


//�ж��Ƿ���ͨ·
int IsPass(int Maze[ROW][COL], position enter, position next)
{
	//1. ��һ����Ч
	if (next.x >= 0 && next.x < ROW&&next.y >= 0 && next.y < COL)
	{
		//2.��Ϊ1������next��enter��Ϊͨ·
		if (Maze[next.x][next.y] == 1 || Maze[next.x][next.y] > Maze[enter.x][enter.y])
		{
			return 1;
		}
	}
	return 0;
}

//�ж��Ƿ��ǳ���
int IsExit(int Maze[ROW][COL], position Enter, position cur)
{
	//�Ǳ߽磬���������
	if ((cur.x == 0 || cur.x == ROW - 1 || cur.y == 0 || cur.y == COL - 1)&&(cur.x!=Enter.x||cur.y!=Enter.y) )
	{
		return 1;
	}
	return 0;
}

//�ж��Ƿ������·��
int IsShortPath(stack *path, stack *shortpath)
{
	//���·��ջΪ�ջ�����·����֮ǰ·����
	if (shortpath->top == 0||path->top < shortpath->top)
	{
		return 1;
	}
	return 0;
}

//���Թ�  EnterΪ�Թ�����  enterΪ�ݹ���Թ����ڣ�pathΪ·����shortpathΪ���·��
void  PassMaze(int Maze[ROW][COL], position Enter, position enter, stack * path, stack *shortpath)
{
	int i = 0;
	position next;
	//�ж�����Ƿ���Ч(ֻ��Maze[x][y]==1ʱ�ж�һ��)
	if (Maze[enter.x][enter.y] == 1&&IsEnter(Maze, enter))
	{
		//�Թ������ջ
		Pushstack(path,enter);
		Maze[enter.x][enter.y] = 2;
	}

	//�ж��Ƿ��ǳ���
	if (IsExit(Maze,Enter,enter))
	{
		//�ж��Ƿ������·��
		if (IsShortPath(path, shortpath))
		{
			for (i = 0; i < path->top; i++)
			{
				shortpath->data[i] = path->data[i];
			}
			shortpath->top = path->top;
		}
	}

	//��
	next = enter;
	next.x = enter.x - 1;
	if (IsPass(Maze, enter, next))
	{
		Pushstack(path, next);
		Maze[next.x][next.y] = Maze[enter.x][enter.y] + 1;
		//����һ�������ݹ�����
	    PassMaze(Maze, Enter, next, path, shortpath);
	}

	//��
	next = enter;
	next.y = enter.y - 1;
	if (IsPass(Maze, enter, next))
	{
		Pushstack(path, next);
		Maze[next.x][next.y] = Maze[enter.x][enter.y] + 1;
		PassMaze(Maze, Enter, next, path, shortpath);
	}
	//��
	next = enter;
	next.y = enter.y + 1;
	if (IsPass(Maze, enter, next))
	{
		Pushstack(path, next);
		Maze[next.x][next.y] = Maze[enter.x][enter.y] + 1;
		PassMaze(Maze, Enter, next, path, shortpath);
	}
	//��
	next = enter;
	next.x = enter.x + 1;
	if (IsPass(Maze, enter, next))
	{
		Pushstack(path, next);
		Maze[next.x][next.y] = Maze[enter.x][enter.y] + 1;
		PassMaze(Maze, Enter, next, path, shortpath);
	}
    //����������ͨ·���ò��ߴ�����
	PopStack(path);
}


//��ӡ�Թ����·��
void Print(stack *shortpath)
{
	int i = 0;
	printf("���·����\n");
	for (i = 0; i < shortpath->top; i++)
	{
		printf("(%d,%d) ", shortpath->data[i].x, shortpath->data[i].y);
	}
	printf("\n");
}

//��ӡ�Թ�
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