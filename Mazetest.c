#include"Maze.h"

void TestMaze()
{
	int Maze[ROW][COL] = {{ 0, 0, 0, 0, 0, 0 }, 
	                      { 0, 1, 1, 1, 0, 0 }, 
						  { 0, 1, 0, 1, 0, 0 },
						  { 0, 1, 0, 1, 0, 0 }, 
						  { 0, 1, 1, 1, 1, 1 },
						  { 0, 1, 0, 0, 0, 0 } };
	stack path;
	stack shortpath;

	//�����Թ����
	position enter;
	position Enter;
	enter.x = 5;
	enter.y = 1;
	Enter = enter;
	//ջ��ʼ��
	StackInit(&path);
	StackInit(&shortpath);
	//���Թ�
	PassMaze(Maze, enter, Enter, &path, &shortpath);
	//��ӡ�Թ�
	print(Maze);
	//��ӡ�Թ����·��
	Print(&shortpath);
}
int main()
{
	TestMaze();
	system("pause");
	return 0;
}