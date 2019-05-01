#include"Maze.h"

//��ʼ��ջ
void InitStack(stack *s)
{
	assert(s);
	s->top = 0;
	memset(s->data, 0, 20 * sizeof(position));
}
//��ջ
void  PushStack(stack *s, position cur)
{
	assert(s);
	s->data[s->top] = cur;
	s->top++;
}
//ջ��Ԫ��
position TopStack(stack *s)
{
	assert(s);
	return s->data[s->top - 1];
}
//ջ��Ԫ�س�ջ
void PopStack(stack *s)
{
	assert(s);
	s->top--;
}
//�ж��������
int IsEnter(int Maze[ROW][COL], position enter)
{
	//�߽�
	if (enter.x == 0 || enter.x == ROW - 1 || enter.y == 0 || enter.y == COL - 1)
	{
		return 1;
	}
	else
		return 0;
}
//��ͨ·��
int IsPass(int Maze[ROW][COL], position next)
{
	//1.������Ч
	if (next.x >= 0 && next.x < ROW && next.y >= 0 && next.y < COL )
	{
		//2.��ͨ·
		if (1 == Maze[next.x][next.y])
		{
			return 1;
		}
	}
	return 0;
}
//�ǳ�����
int IsExit(int Maze[ROW][COL], position enter, position cur)
{
	if ((cur.x == 0 || cur.x == ROW - 1 || cur.y == 0 || cur.y == COL - 1) && (cur.x != enter.x || cur.y != enter.y))
	{
		return 1;
	}
	return 0;
}

//���Թ�
void PassMaze(int Maze[ROW][COL], position enter, stack* s)
{
	position cur;
	position next; 
	if (IsEnter(Maze, enter))
	{
		cur = enter;
		//�����ջ
		PushStack(s, cur);
		//Ϊ��ֹ�ظ��ߣ����߹���·���
		Maze[cur.x][cur.y] = 2;
		//������ǳ��ڣ�������������
		while (!IsExit(Maze, enter,TopStack(s)))
		{
			//curΪ��ǰ��ջ��Ԫ��
			cur = TopStack(s);
			//��ͨ�������ߣ����
			next = cur;
			next.x = cur.x - 1;
			if (IsPass(Maze, next))
			{
				PushStack(s, next);
				Maze[next.x][next.y] = 2;
				continue;
			}
			//��ͨ�������ߣ����
			next = cur;
			next.y = cur.y - 1;
			if (IsPass(Maze, cur))
			{
				PushStack(s, next);
				Maze[next.x][next.y] = 2;
				continue;
			}
			//��ͨ�������ߣ����
			next = cur;
			next.y = cur.y + 1;
			if (IsPass(Maze, next))
			{
				PushStack(s, next);
				Maze[cur.x][next.y] = 2;
				continue;
			}
			//��ͨ�������ߣ����
			next = cur;
			next.x = cur.x + 1;
			if (IsPass(Maze, next))
			{
				PushStack(s, next);
				Maze[next.x][next.y] = 2;
				continue;
			}
			//���������¾�����ͨ·��֤���ò��ߴ����ˣ��ұ��
			//ջ��Ԫ�س�ջ
			PopStack(s);
			Maze[cur.x][cur.y] = 3;
		}
		}
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
	printf("\n");
}

//��ӡ�Թ�·��
void printStack(stack *s)
{
	int i = 0;
	printf("�Թ�·��Ϊ��\n");
	for (i = 0; i < s->top; i++)
	{
		printf("(%d,%d)  ", s->data[i].x,s->data[i].y);
	}
	printf("\n");
}