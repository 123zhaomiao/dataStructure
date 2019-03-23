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

	//定义迷宫入口
	position enter;
	position Enter;
	enter.x = 5;
	enter.y = 1;
	Enter = enter;
	//栈初始化
	StackInit(&path);
	StackInit(&shortpath);
	//走迷宫
	PassMaze(Maze, enter, Enter, &path, &shortpath);
	//打印迷宫
	print(Maze);
	//打印迷宫最短路径
	Print(&shortpath);
}
int main()
{
	TestMaze();
	system("pause");
	return 0;
}