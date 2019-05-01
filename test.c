#include"Maze.h"

void TestMaze()
{
	//设置一个地图的二位数组
	int Maze[ROW][COL] = { { 0, 0, 0, 0, 0, 0 },
	                       { 0, 0, 1, 0, 0, 0 }, 
						   { 0, 0, 1, 0, 0, 0 },
						   { 0, 0, 1, 1, 1, 0 }, 
						   { 0, 0, 1, 0, 1, 1 },
						   { 0, 0, 1, 0, 0, 0 } };
	position enter;
	//定义栈，用于存放路径
	stack s;
	//打印迷宫
	print(Maze);
	//初始化栈
	InitStack(&s);
	//定义一个迷宫入口
	enter.x = 5;
	enter.y = 2;
	//走迷宫
	PassMaze(Maze, enter, &s);
	//打印迷宫
	print(Maze);
	//打印迷宫路径
	printStack(&s);
}

int main()
{
	TestMaze();
	system("pause");
	return 0;
}