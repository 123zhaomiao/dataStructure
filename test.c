#include"Maze.h"

void TestMaze()
{
	//����һ����ͼ�Ķ�λ����
	int Maze[ROW][COL] = { { 0, 0, 0, 0, 0, 0 },
	                       { 0, 0, 1, 0, 0, 0 }, 
						   { 0, 0, 1, 0, 0, 0 },
						   { 0, 0, 1, 1, 1, 0 }, 
						   { 0, 0, 1, 0, 1, 1 },
						   { 0, 0, 1, 0, 0, 0 } };
	position enter;
	//����ջ�����ڴ��·��
	stack s;
	//��ӡ�Թ�
	print(Maze);
	//��ʼ��ջ
	InitStack(&s);
	//����һ���Թ����
	enter.x = 5;
	enter.y = 2;
	//���Թ�
	PassMaze(Maze, enter, &s);
	//��ӡ�Թ�
	print(Maze);
	//��ӡ�Թ�·��
	printStack(&s);
}

int main()
{
	TestMaze();
	system("pause");
	return 0;
}